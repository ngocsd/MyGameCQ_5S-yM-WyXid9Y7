
// 自用持续技能  TIPS:[PF_SELF_LOOP]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>
#include <equip.h>

#define THIS_SKILL      0425
#define THIS_PERFORM    04252
#define PF_START       "04252"
#define PF_TIME        "04252#"
#define PF_NAME        "Càn Khôn Na Di"

#define SKILL_LEVEL     10
//#define TIME_INTERVAL   me->get_pf_value(THIS_SKILL, SKILL_LEVEL_SQUARE, 18, 5000)    // 警告:me 得准备好
#define TIME_INTERVAL   15
#define SUB_MP          20 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/10*10
#define ADD_INTERVAL    300
#define ADD_EFFECT	100 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/10*200
#define ADD_ENMITY	1*mp + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/10*30 + ret


// 函数:获取符法效果
// int get_cast_seal() { return 42100; }    // 符纸顺旋

// 函数:获取描述
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n Võ công yêu cầu: 10 cấp\n    Dùng nội lực hộ thể, chuyển hóa 100 điểm sát thương thành tiêu hao Pháp Lực. Mỗi 1 điểm sát thương tương ứng 1 điểm Pháp Lực tiêu hao. Tâm pháp có thể duy trì trong 5 phút";
        cur_level = (level - SKILL_LEVEL)/10 + 1;
        result = sprintf(HIC" %s (Cấp %d )\n " NOR "Võ công yêu cầu: Cấp %d \n Pháp Lực tiêu hao: %d điểm\n Tái sử dụng sau: %d giây\n    Dùng nội lực hộ thể, chuyển hóa %d điểm sát thương thành tiêu hao Pháp Lực. Mỗi 1 điểm sát thương tương ứng 1 điểm Pháp Lực tiêu hao. Tâm pháp có thể duy trì trong 5 phút.\n " HIC"Cấp tiếp theo:\n "NOR "Võ công yêu cầu: " HIR "Cấp %d " NOR "\n    Dùng nội lực hộ thể, chuyển hóa %d điểm sát thương thành tiêu hao Pháp Lực.", 
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_MP, TIME_INTERVAL, ADD_EFFECT, cur_level*10+SKILL_LEVEL, ADD_EFFECT + 200 );
        return result;	
}

// 函数:获取描述(持续)
string get_loop_desc( object me )
{
        if( me->get_perform(PF_START) )
                return sprintf( PF_NAME ":\n　　Chuyển hoá %d sát thương thành tiêu hao Pháp lực.\n", me->get_save("pf.miss") );
        else    return sprintf( PF_NAME ":\n　　Chuyển hoá %d sát thương thành tiêu hao Pháp lực.\n", me->get_save("pf.miss") );
}

// 函数:命令处理
int main( object me, object who, int x, int y, string arg )
{
        object *user, item, item1;
        int level, mp, interval, ret, mpp;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        interval = TIME_INTERVAL;

        if( gone_time( me->get_perform(PF_START) ) < interval ) return 1;

        if( me->get_mp() < ( mp = SUB_MP ) )    // 小心准备 me
        {
                printf( ECHO "Sử dụng \" %s \"cần %d điểm Pháp Lực.", PF_NAME, mp );
                return 1;
        }

/*      if( !objectp( item = present("Bùa Giấy", me, 1, MAX_CARRY) ) )
        {
                printf( ECHO "您得有符纸才能使用\"" PF_NAME "\"." );
                return 1;
        }       */

        send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // 所有出招２秒后能使用
        me->set_time( "pf", time() );

        user = get_scene_object_2(me, USER_TYPE);
//      send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(me), get_cast_seal(), 2, UNDER_FOOT, PF_LOOP );

        me->add_mp(-mp);
//      item->add_amount(-1);
       	CHAR_FIGHT_D->set_enmity1(me,10);
        level = me->get_skill(THIS_SKILL);
        interval = ADD_INTERVAL;    // 小心准备 me
		mpp = ADD_EFFECT;
		if( objectp(item1=me->get_equip(WEAPON_TYPE)) && item1->get_name()=="Huyết Lệ" )
		mpp += 400 + random(101);
		if( objectp(item1=me->get_equip(WEAPON_TYPE)) && item1->get_name()=="Càn Khôn Vân Đao" )
		mpp += 400 + random(101);
        me->set_perform( PF_START, time() );
        me->set_perform( PF_TIME, interval );
        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
//        if (get_effect(me, EFFECT_CHAR_MISS) ) return 2;
        set_effect(me, EFFECT_CHAR_MISS, interval);
        send_user( me, "%c%w%w%c", 0x81, 4252, get_effect_3(me, EFFECT_CHAR_MISS), EFFECT_GOOD );
        send_user( user - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 4252, 1, EFFECT_GOOD );
        send_user( user, "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(me), 
                42511, 1, OVER_BODY, 42511, 1, OVER_BODY, PF_ONCE );
	me->set_save("pf.miss", mpp);
//	me->set_save("pf.miss", ADD_EFFECT);
	
	mp = me->get_mp();
        ret = CHAR_FIGHT_D->attack_done(me, who, HIT_UNARMED, (mpp)*mp );    // 小心准备 me
//        ret = CHAR_FIGHT_D->attack_done(me, who, HIT_UNARMED, (ADD_EFFECT)*mp );    // 小心准备 me
//        me->add_mp( -mp );

        if ( who && !who->is_die() )
        	CHAR_FIGHT_D->set_enmity(me,who,ADD_ENMITY);

        return 1;
}

// 函数:法术处理
int cast_done( object me )
{
        return 2;    // 执行成功
}

// 函数:获取特技类型
int get_perform_type() { return ON_ME; }

// 函数:能否使用特技
void can_perform( object me )
{
        int level, interval, interval2;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) 
        {
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, 0, 1, 0, PF_NAME );
                return;
        }

        interval = TIME_INTERVAL;    // 小心准备 me
        interval2 = TIME_INTERVAL - gone_time( me->get_perform(PF_START) );
        if( interval2 < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), interval, 0, PF_NAME );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), interval, interval2, PF_NAME );
}
