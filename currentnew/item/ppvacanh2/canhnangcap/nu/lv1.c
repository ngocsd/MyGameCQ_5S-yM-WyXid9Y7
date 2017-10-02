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
        set_name("Huyết Phụng Chi Dực");
        set_picid_1(3031);
        set_picid_2(3031);

        set_level(0);
		set_bind(0);
        set_value(1000);
        set_max_lasting(21599);
     //   set("ap+", 500);
		set("cp+", 350);
        set("dp+", 300);
	//	set("pp+", 300);
        set("hp+", 900);
		set("mp+", 900);
		set("sp+", 100);
	//	set("double", 100);
		
		set_hide(0);
        setup();

        set_gender(2);
        set_back_type(7);
		set_back2_type(7);
		set_back_color(0x6006);
		set_back2_color(40);
}

// 函数：获取描述
string get_desc()
{
        return "Đôi cánh được chế tạo từ Huyết Phụng trên thiên giới. Năng lực tiềm ẩn";
}

// 函数：使用效果
int get_equip_effect( object me )
{
	return __FILE__ ->get_equip_effect_callout(me, this_object());
}

// Hàm giữ vật phẩm ngay cả khi hết tg
int get_equip_effect_callout( object me, object item )
{
	if (item->get_lock_time()==0) 
	item->set_lock_time(time()+30*24*60*60);
	if (item->get_lock_time()<time())
	{
		send_user(me, "%c%s", '!', "Hết hạn sử dụng");
		return 0;		
	}
}

string get_tail_desc()
{
	object item = this_object();
	string desc;

	if (item->get_lock_time() == 0)
	{
		desc = HIG "(Chưa kích hoạt)" NOR "[Thời gian sử dụng 30 ngày]\n ";
	}

	return desc;
}