
#include <equip.h>
#include <ansi.h>

inherit WEAPON;

// 函数：nh9h适用门派
int get_item_value() {return 450 ;}
int get_item_value_2() {return 450 ;}
int get_family() { return 9; }

// 函数：nh9h构造处理
void create()
{
        set_name("[Thần Chiến]Ngọc thần bảo kiếm");
        set_picid_1(6872);
        set_picid_2(6872);

        set_level(10);
        set_value(50000000);
        set_max_lasting(14099);
        set("ap+", 350);
        set("cp+", 350);
        set("dp+", 350);
		        set("!%+", 3500);

        set("hp+", 350);
        set("double", 100);
        set("?%+", 100);
	set_item_color(2);	//紫色
        setup();

        set_weapon_type(SWORD);
}

// 函数：nh9h获取武器级别
int get_weapon_level() { return 75; }

// 函数：nh9h获取描述
string get_desc()
{
        return "“Kiếm pháp”Trang bị";
}

//
string get_tail_desc()
{
	return "“Thái thượng ngọc thần đạo quân sở dụng đích pháp thuật bảo kiếm”\nTăng gia pháp thuật sở tạo thành đích thương hại hiệu quả \nHoà trị liệu hiệu quả ,Tối đa 50 điểm";		
}