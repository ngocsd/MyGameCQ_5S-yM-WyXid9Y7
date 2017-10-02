
#include <equip.h>

inherit ARMOR;

// ??:????
void create()
{
        set_name("Áo Trắng Nhạt");
        set_picid_1(6000);
        set_picid_2(6000);
        set_unit("Áo");

        set_level(0);
        set_value(5000);
        set_max_lasting(2599);
        set("dp", 60);
        set("pp", 60);
        set("hp", 55);
        set("mp", 55);

        setup();

        set_armor_code(M_BUYI);
        set_armor_color_1(0x00578B2E);
        set_armor_color_2(0x00578B2E);
}


string get_desc()
{
        return "  Là chiếc áo giúp đồ bạn trở thành màu trắng nhạt";
}
