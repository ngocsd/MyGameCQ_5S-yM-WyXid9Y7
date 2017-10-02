
// 自动生成：/make/npc/makenpc

#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <task.h>
#include <ansi.h>

inherit BADMAN;
inherit LEGEND_NPC;

// 函数：获取人物造型
int get_char_picid() { return 0800; }

// 函数：构造处理
void create()
{
        set_name("鬼之魅");

        set_level(51);
	set_max_hp(1050);
	set_ap(370);
	set_dp(400);
	set_cp(100);
	set_pp(200);
	set_sp(120);
	set_walk_speed(4);
	set_attack_speed(13);
        set_max_seek(4);

        setup();
        set_char_type(FIGHTER_TYPE_2);  
}

void check_legend_task( object who )
{
        if ( objectp(who) && who->get_legend(TASK_12, 10) && !who->get_legend(TASK_12, 11) )
        {
		who->set_legend(TASK_12, 11);
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,4,"河道惊魂(完成)" );
		send_user(who, "%c%s",'!', "鬼之魅 1/1");
	}
}
