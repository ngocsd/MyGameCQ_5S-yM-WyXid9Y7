2
// 自动生成：/make/item/make32a

inherit ITEM;
    inherit COMBINED;

// 函数：叠加上限
//  int get_max_combined() { return 30; }

// 函数：原料类型
int get_stuff_type() { return 146; }

// 函数：构造处理
void create()
{
        set_name("Cao L??ng");
        set_picid_1(3205);
        set_picid_2(3205);
        set_unit("根");
        set_value(20);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "M?t lo?i n?ng s?n."; 
}
