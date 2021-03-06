#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;   

// 函数：叠加上限
int get_max_combined() { return %d; }

// 函数：可使用物品
int get_item_type_2() { return %s; }

// 函数：成品编号
int get_fin_type() { return %d; }

// 函数：构造处理
void create()
{
        set_name("%s");
        set_picid_1(%d);
        set_picid_2(%d);
        set_value(%d);
        set_amount(1);
	set("level", %d);
	set("add_hp", %d);	
	set("add_mp", %d);	
}

// 函数：获取描述
string get_desc() 
{
	string desc;
	desc = "%s";
	if (this_player()->get_level()<this_object()->get("level"))
        	return sprintf(HIR+desc+"\n"HIR"使用要求 %%d 级", get("level") ); 
	else
		return sprintf(desc+"\n使用要求 %%d 级", get("level") ); 
}

// 函数：使用效果
int get_use_effect( object me ) { return "/sys/item/food" ->get_use_effect(me, this_object()); }