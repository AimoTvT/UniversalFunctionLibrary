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

#pragma once


#include "UniversalEnum.generated.h"



/** * 设置操作命令,Set,SetAll,Add,AddUnique,Remove,RemoveAll */
UENUM(BlueprintType)
enum class ESetCmd :uint8
{
	Set = 0			UMETA(DisplayName = "Set"),
	SetAll = 1			UMETA(DisplayName = "SetAll"),
	Add = 2			UMETA(DisplayName = "Add"),
	AddUnique = 3			UMETA(DisplayName = "AddUnique"),
	Remove = 4			UMETA(DisplayName = "Remove"),
	RemoveAll = 5			UMETA(DisplayName = "RemoveAll"),
	Swap = 6			UMETA(DisplayName = "Swap"),
	SwapOther = 7			UMETA(DisplayName = "SwapOther")

};


/** * 运算符号枚举 Addition == "+",Subtraction == "-",Multiplication == "*",Division == "/" */
UENUM(BlueprintType)
enum class EArithmeticOperator :uint8
{
	Addition = 0			UMETA(DisplayName = "Addition"),
	Subtraction = 1			UMETA(DisplayName = "Subtraction"),
	Multiplication = 2		UMETA(DisplayName = "Multiplication"),
	Division = 3			UMETA(DisplayName = "Division")

};


/** *
	碰撞物理材质类,用于碰撞常用物理材质,比如赛选攻击碰撞声音
	// 空气,无声音,除非特殊要求,如踏空而行
	00_Gas_气体_PhysicalMaterial
	// 泥巴地,干的泥土,可能还有草等杂物
	01_Dirt_泥土_PhysicalMaterial
	// 草地,如茅草铺在地面上
	02_Grass_草_PhysicalMaterial
	// 沙地,如海边的沙地一般
	03_Sand_沙子_PhysicalMaterial
	// 如碎石头,杂乱无章的沙子,石头,等
	04_Gravel_沙砾_PhysicalMaterial
	// 冰面
	05_Ice_冰_PhysicalMaterial
	// 坚实的地面
	06_Stone_石头_PhysicalMaterial
	07_Rock_岩石_PhysicalMaterial
	08_Asphalt_沥青_PhysicalMaterial
	09_Brick_砖石_PhysicalMaterial
	// 木质类的地面,木板,树上等
	10_Wood_木材_PhysicalMaterial
	// 水面
	11_Liquid_液体_PhysicalMaterial
	12_Mud_泥潭_PhysicalMaterial
	// 金属
	13_Metal_金属_PhysicalMaterial
	// 玻璃
	14_Glass_玻璃_PhysicalMaterial
	// 塑料
	15_Plastic_塑料_PhysicalMaterial
	// 布料,软绵绵的那种声音
	16_Snow_雪_PhysicalMaterial
	17_Fabric_布料_PhysicalMaterial
	18_LightMaterials_轻材料_PhysicalMaterial
*/
UENUM(BlueprintType)
enum class ECollisionPhysicalMaterialClassEnum :uint8
{
	/** * 空气,无声音,除非特殊要求,如踏空而行 */
	Gas = 0				UMETA(DisplayName = "气体"),
	/** * 泥巴地,干的泥土,可能还有草等杂物 */
	Dirt = 1			UMETA(DisplayName = "泥土"),
	/** * 草地,如茅草铺在地面上 */
	Grass = 2			UMETA(DisplayName = "草"),
	/** * 沙地,如海边的沙地一般 */
	Sand = 3			UMETA(DisplayName = "沙子"),
	/** * 如碎石头,杂乱无章的沙子,石头,等 */
	Gravel = 4			UMETA(DisplayName = "沙砾"),
	/** * 冰面 */
	Ice = 5			UMETA(DisplayName = "冰"),
	/** * 坚实的地面 */
	Stone = 6			UMETA(DisplayName = "石头"),
	Rock = 7			UMETA(DisplayName = "岩石"),
	Asphalt = 8			UMETA(DisplayName = "沥青"),
	Brick = 9			UMETA(DisplayName = "砖石"),
	/** * 木质类的地面,木板,树上等 */
	Wood = 10			UMETA(DisplayName = "木材"),
	/** * 水面 */
	Liquid = 11			UMETA(DisplayName = "液体"),
	Mud = 12			UMETA(DisplayName = "泥潭"),
	/** * 金属 */
	Metal = 13			UMETA(DisplayName = "金属"),
	/** * 玻璃 */
	Glass = 14			UMETA(DisplayName = "玻璃"),
	/** * 塑料 */
	Plastic = 15		UMETA(DisplayName = "塑料"),
	/** * 布料,软绵绵的那种声音 */
	Snow = 16			UMETA(DisplayName = "雪"),
	Fabric = 17			UMETA(DisplayName = "布料"),
	LightMaterials = 18	UMETA(DisplayName = "轻材料")

};