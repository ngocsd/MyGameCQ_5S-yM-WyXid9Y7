
// 自动生成：/make/equip/60b

#include <equip.h>

inherit BOOTS;

// 函数：适用门派
int get_family() { return 6; }

// 函数：构造处理
void create()
{
        set_name("Thanh Long Hài");
        set_picid_1(8803);
        set_picid_2(8803);

        set_level(30);
        set_value(4000);
        set_max_lasting(5199);
        set("dp", 8);
        set("sp", 11);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "Thanh Long Hài";
}
