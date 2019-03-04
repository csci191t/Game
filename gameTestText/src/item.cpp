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
weapon::weapon(std::string itemName, std::string itemType, std::string weapType, int weapDmg, int weapCd, int itemId)
{
    item_name = itemName;
    item_type = itemType;
    item_ID = itemId;

    weapon_type = weapType;
    weapon_dmg = weapDmg;
    weapon_cd = weapCd;
}

//item name, item type, Recovery type, recovery amount, item id
consumable::consumable(std::string itemName, std::string itemType, std::string rType, int rAm, int itemId)
{
    item_name = itemName;
    item_type = itemType;
    item_ID = itemId;

    recover_type = rType;
    recover_amount = rAm;
}

//item name, item type, buff type, buff amount, item id
buff::buff(std::string itemName, std::string itemType, std::string buffType, int buffAm, int itemId)
{
    item_name = itemName;
    item_type = itemType;
    item_ID = itemId;

    buff_type = buffType;
    buff_amount = buffAm;
}

//item name, item type, misc type, item id
misc::misc(std::string itemName, std::string itemType, std::string miscType, int itemId)
{
    item_name = itemName;
    item_type = itemType;
    item_ID = itemId;

    misc_type = miscType;
}
