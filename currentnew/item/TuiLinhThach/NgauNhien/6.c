#include <ansi.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;
inherit COMBINED;

int get_max_combined() { return 100; }
int get_item_color() { return 2; }
int get_item_value() {return 100 ;}
int get_item_value_2() {return 100 ;}

// 函数：构造处理
void create()
{
        set_name( "Túi Linh Thạch cấp 6" );
        set_picid_1(7108);
        set_picid_2(7108);
        set_value(50);
		set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Sau khi sử dụng có thể nhận được một Linh Thạch cấp 6";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int p;
	object item;

	gift->remove_from_user();
	destruct(gift);
	item = new(sprintf("/item/sell/%d", 9301+random(10)));
	item->set_level(6);
	p = item->move2(who,-1);
	item->add_to_user(p);
	CHAT_D->sys_channel( 0, sprintf(who->get_name()+" đã mở Túi Linh Thạch cấp 6 và nhận được %s ",item->get_name()));
	return 0;
}