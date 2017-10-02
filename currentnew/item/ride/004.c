#include <item.h>
#include <effect.h>
#include <skill.h>
#include <ansi.h>
inherit ITEM;
inherit USABLE;

inherit "/inh/equip/equip";   
int is_ridepk() { return 1; }

#define RIDE_ID	4

// 函数：构造处理
void create()
{
        set_name( "Trứng Bọ Hung" );
        set_picid_1(13);
        set_picid_2(13);
        set_value(500);
        set_hide(0);
        set_bind(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Bọ Hung vốn là Kỵ Thú của nước Ngụy\n Điều kiện sử dụng: Người sử dụng phải trở thành dân của nước Ngụy hoặc đạt đủ Giao Hảo với nước Ngụy.\n Vật phẩm sau khi sử dụng sẽ Phong Ấn vào nhân vật.\n";
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
		me->set_ride(0);
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));		
		return 0;
	}
	me->set_ride(RIDE_ID);
	me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
	if (item->get_bind()==1)
	{
		item->set_bind(2);
		send_user( me, "%c%d%c", 0x31, getoid(item), 0 );
	}
        return 0;
}
