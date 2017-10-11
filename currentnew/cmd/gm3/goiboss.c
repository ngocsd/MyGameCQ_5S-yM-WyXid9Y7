
#include <ansi.h>
#include <equip.h>
#include <npc.h>

// 函数：命令处理
int main( object me, string arg )
{
        object item,boss1;
        string *weapon, file;
        string cmd1, cmd2, cmd3, cmd4;
        int family, z, x, y, p, i, size;

        if( !is_god(me) ) 
        {
            notify( "gọi gì đấy cưng?" );
			return 1;
        }
        z = get_z(me), x = get_x(me), y = get_y(me);

		switch(arg){
			case "sondaivuong":
				if( p = efun::get_xy_point( 151, IS_CHAR_BLOCK ) ) //151 = Kênh trịnh quốc 1
				{
					x = ( p % 1000000 ) / 1000;  y = p % 1000;
					boss1 = new("npc/boss/0021"); //link boss
					notify("đến đc line 27");
					if ( boss1 )
					{
						"map/map/151"->add_boss(boss1);
						boss1->add_to_scene(151,80,24); //z chính là id của map boss sẽ xuất hiện, x,y là tọa độ, ở đây là xuất hiện ngẫu nhiên
						notify( "đã gọi đc con boss "+arg  );
					}
				}
			break;
		}
        return 1;
}
