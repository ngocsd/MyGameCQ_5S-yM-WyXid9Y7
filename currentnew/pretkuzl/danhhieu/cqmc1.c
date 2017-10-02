#include <ansi.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;
inherit COMBINED;

int get_item_value() {return 1020 ;}
int get_item_value_2() {return 1020 ;}
int get_item_color() { return 3; }

// 函数：构造处理
void create()
{
        set_name("Chiến Quốc Tiểu Minh Chủ");
        set_picid_1(0089);
        set_picid_2(0089);
        set_value(1000);
		set_amount(1);
		set_no_give(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Sử dụng sẽ nhận được danh hiệu Chiến Quốc Tiểu Minh Chủ.";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int gender,family,exp,type;
	object item,item1;
	string cTmp,cFile,p;
		if ( who->get_level() < 10 )
		{
		send_user(who,"%c%s",'!',"Cấp 10 mới có thể sử dụng.");
		    		return 0;

		}
					who->add_title("Y300");
			gift->add_amount(-1);
}