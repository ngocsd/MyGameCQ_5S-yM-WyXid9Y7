#include <item.h>
#include <ansi.h>
#include <equip.h>

int check_match(object equip, object diamond);
int mix1(object me, object *item);

// 函数：命令处理

int main(object me, string arg)
{
    object *item, who;
    string name, make, result, forge, index;
    int *id;
    int i, flag, level, rate;

    if (!arg)
        return 1;

    item = ({
        0, 0,
    });
    id = ({
        0, 0,
    });

    if (sscanf(arg, "? %s %x# %x#", name, id[0], id[1]) == 3)
        flag = 1;
    else if (sscanf(arg, "%s %x# %x#", name, id[0], id[1]) == 3)
        flag = 2;
    else
    {
        notify("Bạn muốn tinh luyện đồ vật gì?");
        return 1;
    }

    if (flag == 1) //Tinh chỉnh tỉ lệ thành công
    {
        for (i = 0; i < 2; i++)
        {
            if (!objectp(item[i] = present(sprintf("%x#", id[i]), me, 1, MAX_CARRY * 4))) // Mục này có phải là món hàng không?
            {
                send_user(me, "%c%c%c%d", 0x25, 0, 0, 0);
                return 1;
            }
        }
        if (item[1]->get_item_type() != ITEM_TYPE_DIAMOND_100)
        {
            send_user(me, "%c%c%c%d", 0x25, 0, 0, 0);
            return 1;
        }
        if (item[1]->get_diamond_type() != "forge") //Đánh giá đá rèn có phù hợp hay không
        {
            make = item[0]->get("make");
            level = item[1]->get_level();
            if (make == 0)
                make = "";
            if (strlen(make) != level - 1)
            {
                send_user(me, "%c%c%c%d", 0x25, 0, 0, 0);
                return 1;
            }
            if (check_match(item[0], item[1]) == 0)
            {
                send_user(me, "%c%c%c%d", 0x25, 0, 0, 0);
                return 1;
            }
        }
        else //Bản án đá giả mạo kết quả phù hợp với thiết bị.
        {
            forge = item[0]->get("forge"); //Đây là ngôi sao của trang bị
            if (forge == 0)
                forge = "";
            level = strlen(forge);
            index = item[1]->get_forge_index();
            if ((level == 1 || level == 0) && index != "1")
            {
                notify("Loại đá rèn không phù hợp, không thể tinh luyện");
                return 1;
            }
            if ((level == 2 || level == 3) && index != "2")
            {
                notify("Loại đá rèn không phù hợp, không thể tinh luyện");
                return 1;
            }
            if (level >= 4)
            {
                if ((index != "3" && index != "4"))
                {
                    notify("Loại đá rèn không phù hợp, không thể tinh luyện");
                    return 1;
                }
            }
        }
        if (item[1]->get_diamond_type() == "forge") //Ở đây là để tính toán tỷ lệ thành công của các thiết bị tập thể dục rèn đá
        {
            rate = 100;
        }
        else //Dưới đây là tỷ lệ thành công thiết bị tính toán spar giả mạo.
        {
            rate = 100;
        }
        //	if(level!=1 && me->get_vip() && !me->get_save_2("vip_package.trial"))
        if (level > 15 && me->get_vip() && !me->get_save_2("vip_package.trial"))
            rate += 5;
        notify("test 1");
        send_user(me, "%c%c%c%d", 0x25, 0, rate, 0);
        return 1;
    }
    else //精炼装备
    {
        for (i = 0; i < 2; i++)
        {
            if (!objectp(item[i] = present(sprintf("%x#", id[i]), me, 1, MAX_CARRY * 4))) // Mục này có phải là món hàng không?
            {
                notify("test 2");
                send_user(me, "%c%c%c%d", 0x25, 0, 0, 0);
                return 1;
            }
        }
        if (item[1]->get_item_type() != ITEM_TYPE_DIAMOND_100)
        {
            notify("Tinh chỉnh đá");
            return 1;
        }
        if (item[1]->get_diamond_type() == "forge")
        {
            tell_user(me, "vào mix 1");
            return mix1(me, ({item[0], item[1]})); //Giả mạo thiết bị đá giả mạo
        }
        if (item[1]->get_mix_level() && item[0]->get_level() > item[1]->get_mix_level())
        {
            notify(sprintf("Xin lỗi, bạn không thể sử dụng các thiết bị hơn spar %d mức ", item[1]->get_mix_level()));
            return 1;
        }
        make = item[0]->get("make");
        level = item[1]->get_level();
        if (make == 0)
            make = "";
        if (strlen(make) != level - 1)
        {
            notify("Tinh chỉnh bằng đá quý và mức độ thiết bị không phù hợp.");
            return 1;
        }
        if (check_match(item[0], item[1]) == 0)
        {
            notify("Các loại đá quý không phù hợp không thể được tinh chế");
            return 1;
        }
        rate = 100;
        if (level > 15 && me->get_vip() && !me->get_save_2("vip_package.trial"))
            rate += 5;
        if (random100() < rate)
        {
            item[0]->add(item[1]->get_diamond_type(), item[1]->get_diamond_add());
            make += item[1]->get_diamond_index();
            item[0]->set("make", make);
            if (item[1]->is_record())
            {
                result = sprintf("Tinh chế thành công biến mất %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), "", item[1]->get_name(), "/sys/item/item"->get_pawn_save_string(item[1]), 1, item[1]->get_user_id(), get_z(me), get_x(me), get_y(me));
                "/sys/user/cmd"->log_item(result);
            }
            item[1]->remove_from_user();
            destruct(item[1]);
            send_user(me, "%c%d%c", 0x31, getoid(item[0]), 0);
            write_user(me, ECHO " %s tinh luyện thành công! Bạn đạt được %s ＋ %d .", item[0]->get_name(), item[0]->get_name(), level);
            /*	if (level>=9)
                    {
                            result = HIY+ sprintf("Chúc mừng %s ( %d ) thành công luyện được %s ＋ %d ", me->get_name(), me->get_number(), item[0]->get_name(), level);
                            CHAT_D->sys_channel( 0, result );
                    }*/
        }
        else
        {
            if (item[1]->is_record())
            {
                result = sprintf("Tinh chỉnh không biến mất %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), "", item[1]->get_name(), "/sys/item/item"->get_pawn_save_string(item[1]), 1, item[1]->get_user_id(), get_z(me), get_x(me), get_y(me));
                "/sys/user/cmd"->log_item(result);
            }
            item[1]->remove_from_user();
            destruct(item[1]);
            write_user(me, ECHO "%s tinh luyện không thành công！", item[0]->get_name());
        }
        notify("test 3");
        return 1;
    }
    notify("test 4");
    return 1;
}

int check_match(object equip, object diamond)
{
    string type = diamond->get_diamond_type();
    switch (equip->get_equip_type())
    {
    case HEAD_TYPE:
    case ARMOR_TYPE:
        if (type == "hp")
            return 1;
        if (type == "mp")
            return 1;
        if (type == "dp")
            return 1;
        if (type == "pp")
            return 1;
        break;
    case NECK_TYPE:
        if (type != "double" && type != "double2")
            return 1;
        break;
    case WEAPON_TYPE:
        if (type == "ap")
            return 1;
        if (type == "cp")
            return 1;
        if (type == "!%")
            return 1;
        if (type == "double")
            return 1;
        if (type == "double2")
            return 1;
        break;
    case WAIST_TYPE:
        if (type != "ap" && type != "cp" && type != "double" && type != "double2")
            return 1;
        break;
    case BOOTS_TYPE:
        if (type != "ap" && type != "cp" && type != "!%" && type != "double" && type != "double2")
            return 1;
        break;
    }
}
//锻造石精炼装备

int mix1(object me, object *item)
{
    int level, rate, rate1, i, color, bind;
    string forge, result, index;
    if (!(i = item[0]->get_equip_type()) || (i != WEAPON_TYPE && i != ARMOR_TYPE && i != HEAD_TYPE && i != BOOTS_TYPE && i != WAIST_TYPE && i != NECK_TYPE))
    {
        tell_user(me, "check đồ có phải là vk, áo, đầu, giày, lưng, cổ");
        return 0;
    }
    forge = item[0]->get("forge");
    tell_user(me, "số sao hiện tại %s",forge);
    index = item[1]->get_forge_index();
    tell_user(me, "get_forge_index %s",index);
    if (index != "9")
    {
        notify("test 6");
        return 0;
    }
    if (forge == 0)
        forge = "";
    level = strlen(forge);
    if (item[1]->get_level() != 1)
    {
        notify("Đá rèn cho các lớp học đầu vào công cộng trên một phân hủy.");
        return 1;
    }
    if (index == "1")
    {
        if (level > 1)
        {
            notify("Rèn đá chính chỉ rèn thiết bị trong ít hơn 2 sao.");
            return 1;
        }
    }
    if (index == "2")
    {
        if (level > 3)
        {
            notify("Trung cấp rèn đá chỉ rèn thiết bị trong vòng 4 sao.");
            return 1;
        }
    }
    bind = item[0]->get_bind();
    if (me->get_level() / 10 < level + 1)
    {
        notify("Max sao = lv/10");
        return 0;
    }
    color = item[0]->get_item_color();
    rate = 100;
    rate1 = random100();
    if (is_god(me))
    {
        if (me->get("lb"))
            rate1 = me->get("lb");
        tell_user(me, "Bây giờ xác xuất thành công %d là %d", rate, rate1);
    }

    forge += item[1]->get_forge_index();
    if (item[1]->is_record())
    {
        result = sprintf("Tinh chế thành công biến mất %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), "", item[1]->get_name(), "/sys/item/item"->get_pawn_save_string(item[1]), 1, item[1]->get_user_id(), get_z(me), get_x(me), get_y(me));
        "/sys/user/cmd"->log_item(result);

        ITEM_EQUIP_D->init_equip_prop_5(item[0]);
        if (color != 0)
            "/sys/sys/count"->add_equip("blue", -1);
        item[0]->set("forge", forge);
        item[1]->remove_from_user();
        destruct(item[1]);
        //item[1]->add_amount(-1); //Mới
        send_user(me, "%c%d%c", 0x31, getoid(item[0]), 0);
        level = strlen(forge);
        write_user(me, ECHO "Chúc mừng bạn thành công rèn ra %d tinh cấp trang bị!", level);
        /*	if (level>=9)
                  {
                          result = HIY+ sprintf("Chúc mừng %s thành công rèn ra %d tinh cấp trang bị!", me->get_name(), level);
                          CHAT_D->sys_channel( 0, result );
                  } */
    }
    else
    {
        if (item[1]->is_record())
        {
            result = sprintf("Giả mạo không thành công biến mất %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), "", item[1]->get_name(), "/sys/item/item"->get_pawn_save_string(item[1]), 1, item[1]->get_user_id(), get_z(me), get_x(me), get_y(me));
            "/sys/user/cmd"->log_item(result);
        }
        if (item[1]->get_forge_index() == "4")
        {
            //		 	ITEM_EQUIP_D->reduce_equip_prop(item[0]);
            ITEM_EQUIP_D->reduce_equip_prop_123(item[0]);
            write_user(me, ECHO "Thật không may, rèn thất bại, nhưng đừng buồn. %s của bạn vẫn còn y nguyên !", item[0]->get_name());
        }
        else
        {
            item[0]->delete ("forge");
            ITEM_EQUIP_D->reset_equip_prop(item[0]);
            write_user(me, ECHO "Thật không may, rèn thất bại. %s của bạn mất hết ngôi sao", item[0]->get_name());
        }
        send_user(me, "%c%d%c", 0x31, getoid(item[0]), 0);
        item[1]->remove_from_user();
        destruct(item[1]);
        //item[1]->add_amount(-1); //Mới
    }
    return 1;
}
