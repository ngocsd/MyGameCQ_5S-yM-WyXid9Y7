#include <ansi.h>
#include <equip.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;
inherit COMBINED;
int get_item_color() { return 2; }
int get_item_value() {return 150 ;}
int get_item_value_2() {return 150 ;}

// 函数：构造处理
void create()
{
        set_name("Túi Hoàng Kim");
        set_picid_1(3102);
        set_picid_2(3102);
        set_value(100);
	//	set_save("tbpt",200);
		set_amount(1);
}

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "Sau khi sử dụng có thể nhận được ngẫu nhiên trang bị Hoàng Kim tương ứng giới tính, môn phái, cấp bậc.";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who, object gift ) 
{
	int p,level;
	object item;
	string *nTmp,cFile;

	if (who->get_fam_name()==""||!who->get_fam_name())
	{
		send_user(who, "%c%s", '!', "Hãy gia nhập môn phái");
		return 0;
	}

	if(USER_INVENTORY_D->get_free_count(who) < 1 )
	{
	        send_user(who,"%c%s",'!',"Hành trang không đủ chỗ.");
    		return 0;
	}

	gift->add_amount(-1);
	nTmp = WEAPON_FILE->get_family_equip( who->get_fam_name(),who->get_gender(),who->get_level(),HEAD_TYPE+random(6) );
	cFile = nTmp[random(sizeof(nTmp))];
	if( load_object(cFile) )
	{
		item = new( cFile );
		ITEM_EQUIP_D->init_equip_prop_3(item);
		p = item->move2(who,-1);
		item->add_to_user(p);
	}
	return 0;
}