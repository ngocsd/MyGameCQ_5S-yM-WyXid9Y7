
// 自动生成：/make/equip/60b

#include <equip.h>

inherit HEAD;

// 函数：适用门派
int get_family() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Phiên Vân Mão");
        set_picid_1(6540);
        set_picid_2(6540);

        set_level(80);
        set_value(26000);
        set_max_lasting(13899);
        set("dp", 93);
        set("pp", 54);

        setup();

        set_gender(1);
        set_head_code(46);
}

// 函数：获取描述
string get_desc()
{
        return "Phiên Vân Mão";
}
