
// ؔ֯ʺԉú/make/equip/60b

#include <equip.h>

inherit "/inh/equip/back";
int get_item_color() { return 2; }
// گ˽úˊԃąƉ
int get_family() { return 8; }

// گ˽úٹլԦm
void create()
{
        set_name("Vạn Ác Chi Vực PURPLE Đậm");
        set_picid_1(100);
        set_picid_2(100);

        set_level(0);
        set_value(10000000);
        set_max_lasting(2599);
        set("ap", 1000);
        set("cp", 1240);
        set("dp", 2340);
        set("pp", 1060);
        set("hp", 2610);
        set("!%", 10000);
        set("?%", 10000);

        setup();
        set_back_type(8);
		set_back2_type(8);
		set_back_color(PURPLE);
		set_back2_color(PURPLE);
}

// گ˽úܱȡĨ˶
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
string get_desc()
{
        return "  Là chiếc cánh có sức mạnh ghê hồn của ác quỷ ";
}
