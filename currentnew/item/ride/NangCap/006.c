#include <item.h>
#include <ansi.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit USABLE;

inherit "/inh/equip/equip";
int is_ridepk() { return 1; }
int get_item_color() {return 2 ;}
#define RIDE_ID	6

// 函数：构造处理
void create()
{
        set_name( "★ Chiến Thú Tử Mao ★" );
        set_picid_1(15);
        set_picid_2(15);
        set_value(500);
        set_hide(0);
        set_bind(2);
}

// 函数：获取描述
string get_desc() 
{ 
        return "\n★★★★★★ \n"HIC"Thuộc tính Chiến Thú sau khi cưỡi : \n"HIY"Khí Huyết: "NOR "+ 500 \n"HIY"Pháp Lực: "NOR "+ 500 \n"HIY"Thân Thủ : "NOR "+ 100\n";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me, this_object()); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me, object item )
{
	int type;
	object who, npc;
	int i, size, x, y, z, p;	
	if (me->get_ride()) 
	{
	/* me->set_2("thucuoi.ap", 0);
	me->set_2("thucuoi.cp", 0); */
	me->set_2("thucuoi.hp", 0);
	me->set_2("thucuoi.mp", 0);
	me->set_2("thucuoi.sp", 0);
	/* USER_ENERGY_D->count_ap(me);
	USER_ENERGY_D->count_cp(me); */
	USER_ENERGY_D->count_hp(me);
	USER_ENERGY_D->count_mp(me);
	USER_ENERGY_D->count_sp(me);
		me->set_ride(0);
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));		
		return 0;
	}
	if (me->set_ride(6))
	{
/*	me->set_2("thucuoi.ap", 500);
	me->set_2("thucuoi.cp", 500); */
	me->set_2("thucuoi.hp", 500);
	me->set_2("thucuoi.mp", 500);
	me->set_2("thucuoi.sp", 100);
	/* USER_ENERGY_D->count_ap(me);
	USER_ENERGY_D->count_cp(me); */
	USER_ENERGY_D->count_hp(me);
	USER_ENERGY_D->count_mp(me);
	USER_ENERGY_D->count_sp(me);
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));		
		return 0;
	}
	me->set_ride(RIDE_ID);
	me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
	/*if (item->get_bind()==1)
	{
		item->set_bind(2);
		send_user( me, "%c%d%c", 0x31, getoid(item), 0 );
	}*/
        return 0;
}

