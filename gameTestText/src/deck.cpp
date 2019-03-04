#include "deck.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <random>
#include <chrono>



deck::deck()
{
    //ctor
}

deck::~deck()
{
    //dtor
}

void deck::shuffle_deck()
{
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    auto r = std::default_random_engine (seed);
    std::shuffle(std::begin(this_item_deck), std::end(this_item_deck), r);
}

void deck::print_deck()
{
    for(std::vector<item>::const_iterator i = this_item_deck.begin(); i != this_item_deck.end(); ++i)
    {
        std::cout << i->item_name <<std::endl;
    }
}

item_deck::item_deck(std::string dName)
{
    deck_name = dName;
}

void item_deck::add_to_deck(std::string fileName)
{
    std::cout << "Generating items for: " << deck_name <<std::endl;
    std::ifstream inFile;
    inFile.open(fileName.c_str());
    std::string line;           //Captures a line

    std::string itemN;      //item name
    std::string itemT;      //item type

    std::string arg3;       //Respective weapon_type, recovery_type, misc_type
    int arg4, arg5, arg6 = 0;   //Respective integer values

    if(!inFile)
    {
        std::cout<<"File Not found.."<<std::endl;
        return;
    }

    while(std::getline(inFile, line))
    {
        std::istringstream lineStream(line);
        std::getline(lineStream, line, ',');
        itemN = line;
        std::getline(lineStream, line, ',');
        itemT = line;
        if(itemT == "Weapon")
        {
            std::getline(lineStream, line, ',');
            arg3 = line;
            std::getline(lineStream, line, ',');
            std::istringstream(line) >> arg4;
            std::getline(lineStream, line, ',');
            std::istringstream(line) >> arg5;
            std::getline(lineStream, line, ',');
            std::istringstream(line) >> arg6;
            weapon *newWeap = new weapon();
            this_item_deck.push_back(weapon(itemN,itemT,arg3,arg4,arg5,arg6));
        }
        else if(itemT == "Consumable")
        {
            std::getline(lineStream, line, ',');
            arg3 = line;
            std::getline(lineStream, line, ',');
            std::istringstream(line) >> arg4;
            std::getline(lineStream, line, ',');
            std::istringstream(line) >> arg5;
            consumable *newCons = new consumable();
            this_item_deck.push_back(consumable(itemN,itemT,arg3,arg4,arg5));
        }
        else if(itemT == "Buff")
        {
            std::getline(lineStream, line, ',');
            arg3 = line;
            std::getline(lineStream, line, ',');
            std::istringstream(line) >> arg4;
            std::getline(lineStream, line, ',');
            std::istringstream(line) >> arg5;
            buff *newBuff = new buff();
            this_item_deck.push_back(buff(itemN,itemT,arg3,arg4,arg5));
        }
    }
}

item item_deck::pull_from_deck()
{
    shuffle_deck();
    item temp = this_item_deck.back();
    this_item_deck.pop_back();
    return temp;
}

item item_deck::find_item(std::string)
{

}
