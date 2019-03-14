#include "item.h"
#include <iostream>
#include "string.h"


item::item()
{
    item_name = "";
    item_type = "";
    item_ID = -1;
}
//item name, item type, weapon type, damage, cooldown, item id
void weapon::create_weapon(std::string itemName, std::string itemType, std::string weapType, int weapDmg, int weapCd, int itemId)
{
    item_name = itemName;
    item_type = itemType;
    item_ID = itemId;

    weapon_type = weapType;
    weapon_dmg = weapDmg;
    weapon_cd = weapCd;
}

//item name, item type, Recovery type, recovery amount, item id
void consumable::create_consumable(std::string itemName, std::string itemType, std::string rType, int rAm, int itemId)
{
    item_name = itemName;
    item_type = itemType;
    item_ID = itemId;

    recover_type = rType;
    recover_amount = rAm;
}

//item name, item type, buff type, buff amount, item id
void buff::create_buff(std::string itemName, std::string itemType, std::string buffType, int buffAm, int itemId)
{
    item_name = itemName;
    item_type = itemType;
    item_ID = itemId;

    buff_type = buffType;
    buff_amount = buffAm;
}

//item name, item type, misc type, item id
void misc::create_misc(std::string itemName, std::string itemType, std::string miscType, int itemId)
{
    item_name = itemName;
    item_type = itemType;
    item_ID = itemId;

    misc_type = miscType;
}

void item::print_item(item *thisItem)
{
    if(dynamic_cast<weapon*>(thisItem) != nullptr)
    {
        weapon *wcast = dynamic_cast<weapon*>(thisItem);
        wcast->print_weapon();
    }
    else if(dynamic_cast<consumable*>(thisItem) != nullptr)
    {
        consumable *ccast = dynamic_cast<consumable*>(thisItem);
        ccast->print_consumable();
    }
    else if(dynamic_cast<buff*>(thisItem) != nullptr)
    {
        buff *bcast = dynamic_cast<buff*>(thisItem);
        bcast->print_buff();
    }
}

void weapon::print_weapon()
{
    std::cout<<"ItemName: "<<item_name<<std::endl;
    std::cout<<"ItemType: "<<item_type<<std::endl;
    std::cout<<"ItemID: "<<item_ID<<std::endl;
    std::cout<<"WeaponType: "<<weapon_type<<std::endl;
    std::cout<<"WeaponDMG: "<<weapon_dmg<<std::endl;
    std::cout<<"WeaponCD: "<<weapon_cd<<std::endl;
}

void consumable::print_consumable()
{
    std::cout<<"ItemName: "<<item_name<<std::endl;
    std::cout<<"ItemType: "<<item_type<<std::endl;
    std::cout<<"ItemID: "<<item_ID<<std::endl;
    std::cout<<"RecoverType: "<<recover_type<<std::endl;
    std::cout<<"RecoverValue: "<<recover_amount<<std::endl;
}

void buff::print_buff()
{
    std::cout<<"ItemName: "<<item_name<<std::endl;
    std::cout<<"ItemType: "<<item_type<<std::endl;
    std::cout<<"ItemID: "<<item_ID<<std::endl;
    std::cout<<"StatBuff: "<<buff_type<<std::endl;
    std::cout<<"BuffValue: "<<buff_amount<<std::endl;
}
