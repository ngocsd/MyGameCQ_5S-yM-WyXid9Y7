#include <ansi.h>
#include <equip.h>

inherit "/inh/equip/back";
int get_item_color() { return 2; }
int get_item_value() {return 1000 ;}
int get_item_value_2() {return 1000 ;}
inherit BACK;
// 函数：构造处理
void create()
{
        set_name("Tân Thủ Tuyền Phi Phong");
        set_picid_1(3020);
        set_picid_2(3020);

        set_level(0);
		set_bind(1);
        set_value(1000);
		set_save("tppc",20);
        set_max_lasting(21599);
        set("ap", 100);
        set("dp", 100);
        set("hp", 400);
		set("mp", 400);
		set("sp", 50);
	//	set("double", 300);
		set_hide(0);
        setup();

     //   set_gender(1);
        set_back_type(1);
		set_back_color(0x0020);
}

// 函数：获取描述
string get_desc()
{
        return "★";
}
// 函数：使用效果
int get_equip_effect( object me )
{
	return __FILE__ ->get_equip_effect_callout(me, this_object());
}

// 函数：使用效果(在线更新)
int get_equip_effect_callout( object me, object item )
{
	//处理时间控制上面的。
	if (item->get_lock_time() == 0)
	{
		item->set_lock_time(time()+14*24*60*60);
		send_user( me, "%c%d%c", 0x31, getoid(item), 0 );
	}
}

//
string get_tail_desc()
{
	object item = this_object();
	string desc;

	if (item->get_lock_time() == 0)
	{
		desc = HIG "(Chưa kích hoạt)" NOR "[Thời gian sử dụng 14 ngày]\n ";
	}

	return desc;
}