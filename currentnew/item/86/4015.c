
// 自动生成：/make/equip/60b

#include <equip.h>

inherit NECK;

// 函数：适用门派
int get_family() { return 4; }

// 函数：构造处理
void create()
{
        set_name("Thanh Đồng Hạng Liên");
        set_picid_1(8604);
        set_picid_2(8604);

        set_level(15);
        set_value(3400);
        set_max_lasting(5299);
        set("cp", 0);
        set("pp", 17);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "Thanh Đồng Hạng Liên";
}
