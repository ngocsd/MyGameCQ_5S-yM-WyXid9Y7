
// 自动生成：/make/equip/60b

#include <equip.h>

inherit NECK;

// 函数：适用门派
int get_family() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Thiên Chu Hạng Liên");
        set_picid_1(8656);
        set_picid_2(8656);

        set_level(65);
        set_value(38000);
        set_max_lasting(7999);
        set("cp", 0);
        set("pp", 70);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "Thiên Chu Hạng Liên";
}
