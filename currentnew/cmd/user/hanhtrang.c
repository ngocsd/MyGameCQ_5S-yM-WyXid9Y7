#include <ansi.h>
#include <skill.h>
#include <equip.h>
#include <effect.h>

int main(object me, string arg) 
{

    int p, cap, exist, exist2, i, size;
	string result,arg2,arg3,arg4,*line,*data;
    object item, item1, who, *objs, target;
		
		if( !arg ) return 1;
		if (arg==0) return 1;
	if( sscanf(arg, "+ %s", arg2 ) == 1 ) 
	{
		if ( !me->get_save("passhanhtrang") )
		{
			if ( strlen(arg2) < 6 || strlen(arg2) > 12 )
			{
			send_user( me, "%c%c%d%s", 0x43, 10, 0, HIR "Mật khẩu bảo vệ Hành trang phải từ 6-12 ký tự" );
			return 1;
			}
			for( i = 0; i < strlen(arg2); i ++ )
			{ 
				if(     ( arg2[i] < 'a' || arg2[i] > 'z' )
				&&      ( arg2[i] < 'A' || arg2[i] > 'Z' )	
                &&      arg2[i] != '-' && arg2[i] != '_'
                &&      ( arg2[i] < '0' || arg2[i] > '9' ) )
                {
			send_user( me, "%c%c%d%s", 0x43, 10, 0, HIR "Mật khẩu bảo vệ Hành trang không được chứa ký tự  đặc biệt , khoảng trống , tiếng việt có dấu." );
			return 1;
                }
			}
		result = sprintf("Bạn muốn thiết lập "HIR "%s "NOR "làm Mật khẩu bảo vệ Hành trang không? \n", arg2 );
		result += sprintf(ESC "Xác nhận\nhanhtrang ? %s\n", arg2);   
		result += ESC "Hủy bỏ\n"; 
		send_user( me, "%c%s", ':', result);
		}
		else
		{
				if ( me->get_save("ndmkhtk") >= 1 )
				{
			if ( strlen(arg2) < 6 || strlen(arg2) > 12 )
			{
			send_user( me, "%c%c%d%s", 0x43, 10, 0, HIR "Mật khẩu bảo vệ Hành trang phải từ 6-12 ký tự" );
			return 1;
			}
			for( i = 0; i < strlen(arg2); i ++ )
			{ 
				if(     ( arg2[i] < 'a' || arg2[i] > 'z' )
				&&      ( arg2[i] < 'A' || arg2[i] > 'Z' )	
                &&      arg2[i] != '-' && arg2[i] != '_'
                &&      ( arg2[i] < '0' || arg2[i] > '9' ) )
                {
			send_user( me, "%c%c%d%s", 0x43, 10, 0, HIR "Mật khẩu bảo vệ Hành trang không được chứa ký tự  đặc biệt , khoảng trống , tiếng việt có dấu." );
			return 1;
                }
			}
		result = sprintf("Bạn muốn thiết lập "HIR "%s "NOR "làm Mật khẩu bảo vệ Hành trang mới không? \n", arg2 );
		result += sprintf(ESC "Xác nhận\nhanhtrang ? %s\n", arg2);   
		result += ESC "Hủy bỏ\n"; 
		send_user( me, "%c%s", ':', result);
				}
				else
				{
			send_user( me, "%c%c%d%s", 0x43, 10, 0, HIR "Bạn chưa nhập Mật khẩu bảo vệ cũ." );	
				}
		}
			return 1; 			
	}
	else if( sscanf(arg, "? %s", arg2 ) == 1 ) 
	{
		if ( !me->get_save("passhanhtrang") )
		{	
			if ( strlen(arg2) < 6 || strlen(arg2) > 12 )
			{
			send_user( me, "%c%c%d%s", 0x43, 10, 0, HIR "Mật khẩu bảo vệ Hành trang phải từ 6-12 ký tự" );
			return 1;
			}
			for( i = 0; i < strlen(arg2); i ++ )
			{  
				if(     ( arg2[i] < 'a' || arg2[i] > 'z' )
				&&      ( arg2[i] < 'A' || arg2[i] > 'Z' )	
                &&      arg2[i] != '-' && arg2[i] != '_'
                &&      ( arg2[i] < '0' || arg2[i] > '9' ) )
                {
			send_user( me, "%c%c%d%s", 0x43, 10, 0, HIR "Mật khẩu bảo vệ Hành trang không được chứa ký tự  đặc biệt , khoảng trống , tiếng việt có dấu." );
			return 1;
                }
			}
			me->set_save("passhanhtrang",arg2);
			"sys/party/hanhtrang"->update_setpass(me, arg2);
			ghi_file("hanhtrang.txt", sprintf("%s %d %s\n", me->get_name(), me->get_number(), arg2));
			send_user( me, "%c%c%d%s", 0x43, 10, 0, HIR "Bạn đã đặt Mật khẩu bảo vệ Hành trang !" );
			send_user( me, "%c%c%d%s", 0x43, 10, 0, sprintf(HIR "Mật khẩu Hành trang của bạn : %s", arg2) );
		}
		else
		{
				if ( me->get_save("ndmkhtk") >= 1 )
				{
			if ( strlen(arg2) < 6 || strlen(arg2) > 12 )
			{
			send_user( me, "%c%c%d%s", 0x43, 10, 0, HIR "Mật khẩu bảo vệ Hành trang phải từ 6-12 ký tự" );
			return 1;
			}
			for( i = 0; i < strlen(arg2); i ++ )
			{  
				if(     ( arg2[i] < 'a' || arg2[i] > 'z' )
				&&      ( arg2[i] < 'A' || arg2[i] > 'Z' )	
                &&      arg2[i] != '-' && arg2[i] != '_'
                &&      ( arg2[i] < '0' || arg2[i] > '9' ) )
                {
			send_user( me, "%c%c%d%s", 0x43, 10, 0, HIR "Mật khẩu bảo vệ Hành trang không được chứa ký tự  đặc biệt , khoảng trống , tiếng việt có dấu." );
			return 1;
                }
			}
			me->set_save("passhanhtrang",arg2);
			"sys/party/hanhtrang"->update_setpass(me, arg2);
			me->set_save("ndmkhtk",0);
			ghi_file("hanhtrang.txt", sprintf("%s %d %s\n", me->get_name(), me->get_number(), arg2));
			send_user( me, "%c%c%d%s", 0x43, 10, 0, HIR "Bạn đã đổi Mật khẩu bảo vệ Hành trang !" );
			send_user( me, "%c%c%d%s", 0x43, 10, 0, sprintf(HIR "Mật khẩu Hành trang của bạn : %s", arg2) );
				}
				else
				{
			send_user( me, "%c%c%d%s", 0x43, 10, 0, HIR "Bạn chưa nhập Mật khẩu bảo vệ cũ." );	
				}
		}	
			return 1; 
	}
	else if( sscanf(arg, "@ %s", arg2 ) == 1 ) 
	{
			
		"sys/party/hanhtrang"->checkpass(me, arg2);
		return 1; 			
	}	
	return 1;
} 