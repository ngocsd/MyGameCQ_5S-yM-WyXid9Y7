
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// 函数：适用门派
int get_family() { return 6; }

// 函数：构造处理
void create()
{
        set_name("Tử Hồn Kiếm");
        set_picid_1(7618);
        set_picid_2(7618);

        set_level(70);
        set_value(36000);
        set_max_lasting(7599);
        set("ap", 140);
        set("dp", 0);
        set("cp", 225);
        set("sp", 0);

        setup();

        set_weapon_type(SWORD);
}

// 函数：获取武器级别
int get_weapon_level() { return LEVEL_09; }

// 函数：获取描述
string get_desc()
{
        return "Trang bị \"Kiếm Pháp\"";
}
