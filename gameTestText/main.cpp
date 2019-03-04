#include <iostream>
#include "hero.h"
#include "item.h"
#include "deck.h"
#include "monster.h"


int main()
{
    hero *gerald = new hero();
    gerald->create_hero("heroes/heroes.csv", "Gerald");
    gerald->print_hero_stat();

    std::cout<<std::endl;
    std::cout<<std::endl;

    hero *amelia = new hero();
    amelia->create_hero("heroes/heroes.csv", "Amelia");
    amelia->print_hero_stat();

    std::cout<<std::endl;
    std::cout<<std::endl;

    monster *cultist = new monster();
    cultist->create_monster("monsters/monsters.csv", "Cultist");
    cultist->print_monster_stats();

    std::cout<<std::endl;
    std::cout<<std::endl;

    item_deck *newDeck = new item_deck("SurplusStore");
    newDeck->add_to_deck("items/SurplusStore/weapons.csv");
    newDeck->add_to_deck("items/SurplusStore/consumables.csv");
    newDeck->add_to_deck("items/SurplusStore/buffs.csv");
    newDeck->shuffle_deck();
    newDeck->print_deck();

    std::cout<<std::endl;
    std::cout<<std::endl;

    item testItem = newDeck->pull_from_deck();
    std::string testItemName = testItem.item_name;
    gerald->add_item(testItem);
    gerald->remove_item(testItemName);

    return 0;
}
