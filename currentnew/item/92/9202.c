
inherit ITEM;

// 函数：构造处理
void create()
{
        set_name( "铜矿" );
        set_picid_1(9535);
        set_picid_2(9535);
        set_unit( "块" );
        set_value(100);
}

// 函数：获取描述
string get_desc() 
{ 
        return "矿产的一种"; 
}
