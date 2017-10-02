#include <ansi.h>
#include <equip.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Trang bị Bá Vương [Nón]");
        set_picid_1(3104);
        set_picid_2(3104);
        set_value(2);
		set_no_give(0);		
        set_no_sell(0);
		set_no_drop(0);
}

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "Sau khi mở ra sẽ nhận được trang bị [Nón] \nBá Vương.";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who, object gift ) 
{
	int i,p,gender,level;
	object item;
	string *nTmp,cFile,forge="";
	level = 160;

	if (who->get_fam_name()==""||!who->get_fam_name())
	{
		send_user(who, "%c%s", '!', "Phải gia nhập Phái mới sử dụng được。");
		return 0;
	}

	nTmp = WEAPON_FILE->get_family_equip( who->get_fam_name(),who->get_gender(),level,HEAD_TYPE );
	cFile = nTmp[random(sizeof(nTmp))];
	if( load_object(cFile) )
	{
		item = new(cFile);
		"/sys/item/equip"->init_equip_prop_3(item);
		for (i = 0; i< 15; i++)
		{
			"/sys/item/equip"->init_equip_prop_5(item);
			forge += "1";
			item->set("forge", forge);
		}
		item->set_item_color(2);
		item->set_hide(0);
		item->set_bind(0);
		p = item->move2(who,-1);
		item->add_to_user(p);
	}
	gift->remove_from_user();
	destruct(gift);
	return 0;
}