#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() {return 50 ;}
int get_item_value_2() {return 50 ;}
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Hộp Quà Thường");
        set_picid_1(3108);
        set_picid_2(3108);
        set_value(10);
	//	set_save("knb",50);
		set_amount(1);
        
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "Hộp Quà Thường tham gia event 30/4 - 1/5 sẽ có"; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,cash,l;
	object item;
	
	if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return 0;
		}
	rate = random(100);
	
	if ( rate < 1 )	//Bảo Để Phù
	{
		item = new("item/sell/0034");
		if ( !item )
			send_user(who,"%c%s",'!',"có gì đó sai sai <1");
	}
	else if ( rate < 5 )	//Cao Cấp đoạn thạch
	{
		// mặc định rate 1
		item = new("item/sell/2032");
		if ( !item )
			send_user(who,"%c%s",'!',"có gì đó sai sai <5");
	}
	else if ( rate < 15 )	//Trung Cấp đoạn thạch
	// mặc định rate 31
	{		
		item = new("item/sell/1032");
		if ( !item )
			send_user(who,"%c%s",'!',"có gì đó sai sai <15");
	}
	else if ( rate < 25 )	//Sơ Cấp đoạn thạch 
	// mặc định rate 51
	{
		item = new("item/sell/0032");
		if ( !item )
			send_user(who,"%c%s",'!',"có gì đó sai sai <25");
	}
	else if ( rate < 35 )	//法力石
	{
		int ran = 1+random(3);
		send_user(who,"%c%s",'!',"Bạn nhận được " + ran + " Tiền xu");
		who->add_save("tienxu",ran);
	}
	else if ( rate < 45 )	//法力石
	{
		int ran = 2 + random(20)*10;
		send_user(who,"%c%s",'!',"Bạn nhận được " + ran + " Ngân bảo");
		"sys/sys/test_db"->add_yuanbao(who,ran);	
	}
	else 			//乾坤袋
	{
		int ran = 100000+random(100000);
		send_user(who,"%c%s",'!',"Bạn nhận được " + ran + " lượng");
		who->add_cash(ran) ;
	}
	gift->add_amount(-1);
	if ( item )
	{
		send_user(who,"%c%s",'!',"Bạn nhận được "+item->get_name());
		p = item->move2(who);
		item->add_to_user(p);
		USER_D->user_channel(sprintf("Bằng hữu %s mở Hộp Quà Thường nhận được "HIY"%s ", who->get_name(),item->get_name() ));	
	}
	return 0;
}

