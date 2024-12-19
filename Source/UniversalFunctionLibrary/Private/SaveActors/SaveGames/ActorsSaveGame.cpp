/**
* Copyright: Aimo_皑墨
* Open Source Date: Jun 5, 2023
* BiLiBiLi (哔哩哔哩) address: https://space.bilibili.com/146962867
* making address: https://github.com/AimoTvT/UniversalFunctionLibrary
* We welcome the contributions of powerful movers and movers to join this plugin
* Build powerful plugins together!!
*
* 版权所有权: Aimo_皑墨
* 开源时间: 2023年6月29日
* BiLiBiLi(哔哩哔哩)地址: https://space.bilibili.com/146962867
* GitHub地址: https://github.com/AimoTvT/UniversalFunctionLibrary
* 欢迎有实力的大佬/萌新加入本插件的贡献
* 一起打造强大的插件!!!
*/



#include "SaveActors/SaveGames/ActorsSaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "Serialization/ObjectAndNameAsStringProxyArchive.h"

int UActorsSaveGame::SaveTagActors(FName InSaveTagName)
{
    SaveTagName = InSaveTagName;
    TArray<AActor*> AllActors;
    UGameplayStatics::GetAllActorsWithTag(GWorld, InSaveTagName, AllActors);
    return SaveActors(AllActors);
}

int UActorsSaveGame::SaveActors(const TArray<AActor*>& InAllActors)
{
    ActorSaveData.Empty();
    if (GWorld == nullptr)
    {
        UE_LOG(LogTemp, Log, TEXT("[%s][Add] GWorld = nullptr"), *GetName());
        return 0;
    }
    if (InAllActors.Num() == 0)
    {
        UE_LOG(LogTemp, Log, TEXT("[%s][Add] AllActors Num : %d"), *GetName(), InAllActors.Num());
        return 0;
    }


    for (size_t i = 0; i < InAllActors.Num(); i++)
    {
        AActor* Actor = InAllActors[i];
        if (Actor)
        {
            TArray<uint8> SerializedData;
            FMemoryWriter Writer(SerializedData, true);
            FObjectAndNameAsStringProxyArchive Ar(Writer, false);
            // 设置翻译器标识
            Ar.ArIsSaveGame = true;
            Ar.ArNoDelta = true;
            // 序列化 Actor 数据
            Actor->Serialize(Ar);
            ActorSaveData.Add(FActorSaveData(Actor->GetClass(), Actor->GetActorTransform(), SerializedData));

            // 对每个 Actor 进行操作
            UE_LOG(LogTemp, Log, TEXT("[%s][Add][SpawnActorName = %s] Actor Writer Serialize"), *GetName(), *Actor->GetName());
        }
    }
    UE_LOG(LogTemp, Log, TEXT("[%s][End] All saved actors are successful, with final storage, ActorSaveData Num : %d"), *GetName(), ActorSaveData.Num());
    return ActorSaveData.Num();
}

int UActorsSaveGame::LoadActors(bool bRemoveSaveActor)
{
    if (GWorld == nullptr)
    {
        return 0;
    }

    if (bRemoveSaveActor) //删除所有保存标签的Actor
    {
        TArray<AActor*> AllActors;
        UGameplayStatics::GetAllActorsWithTag(GWorld, SaveTagName, AllActors);
        for (size_t i = 0; i < AllActors.Num(); i++)
        {
            if (AllActors[i])
            {
                AllActors[i]->Destroy();
            }
        }
        UE_LOG(LogTemp, Log, TEXT("[%s][RemoveAllSaveTagActors] Remove SaveActors Num: %d"), *GetName(), AllActors.Num());
    }
    AActor* NewActor;
    int ActorNum = 0;


    for (size_t i = 0; i < ActorSaveData.Num(); i++, ActorNum++)
    {
        if (ActorSaveData[i].SoftActorClassPath.IsValid() == false)
        {
            continue;
        }
        UClass* ActorClass = Cast<UClass>(ActorSaveData[i].SoftActorClassPath.TryLoad());
        if (ActorClass == nullptr)
        {
            continue;
        }
        // 生成Actor延迟,等待FinishSpawning()完成初始化后生成
        NewActor = GWorld->SpawnActorDeferred<AActor>(ActorClass, ActorSaveData[i].ActorTransform);

        // 对 Actor 进行初始化
        if (NewActor)
        {

            TArray<uint8> SerializedData;
            // 使用 FMemoryReader 反序列化数据
            FMemoryReader Reader(ActorSaveData[i].ActorSerializedData, true);
            FObjectAndNameAsStringProxyArchive Ar(Reader, false);
            // 设置翻译器标识
            Ar.ArIsSaveGame = true;
            Ar.ArNoDelta = true;
            NewActor->Serialize(Ar);
            if (NewActor->Tags.Find(SaveTagName) == -1)
            {
                NewActor->Tags.Add(SaveTagName);
            }
            // 初始化完成后完成生成
            NewActor->FinishSpawning(ActorSaveData[i].ActorTransform);
            UE_LOG(LogTemp, Log, TEXT("[%s][SpawnActor][Index = %d][SpawnActorName = %s] Actor Reader Serialize"), *GetName(), i, *NewActor->GetName());
        }
    }

    UE_LOG(LogTemp, Log, TEXT("[%s][End] All saved actors loaded successfully, Actor Num : %d"), *GetName(), ActorNum);

    return ActorNum;
}
