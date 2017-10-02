
// 自动生成：/make/npc/makenpc

#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <task.h>
#include <ansi.h>

inherit BADMAN;
inherit LEGEND_NPC;

// 函数：获取人物造型
int get_char_picid() { return 0251; }

// 函数：构造处理
void create()
{
        set_name("恶霸赵六");

        set_level(60);
	set_max_hp(1500);
	set_ap(400);
	set_dp(410);
	set_cp(100);
	set_pp(230);
	set_sp(160);
	set_walk_speed(4);
	set_attack_speed(13);
        set_max_seek(4);

        setup();
        set_char_type(FIGHTER_TYPE_2);  
}

void check_legend_task( object who )
{
        if ( objectp(who) && who->get_legend(TASK_15, 1) && !who->get_legend(TASK_15, 2) )
        {
		who->set_legend(TASK_15, 2);
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHAOGUO,13,"长城恶霸(完成)" );
		send_user(who, "%c%s",'!', "恶霸赵六 1/1");
	}
}
   