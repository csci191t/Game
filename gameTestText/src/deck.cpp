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
    deck_name = "";
    deck_type = "";
}

deck::~deck()
{
    //dtor
}

void item_deck::shuffle_deck()
{
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    auto r = std::default_random_engine (seed);
    std::shuffle(std::begin(this_item_deck), std::end(this_item_deck), r);
}

void item_deck::print_deck()
{
    for(std::vector<item*>::iterator i = this_item_deck.begin(); i != this_item_deck.end(); ++i)
    {

        item* this_item = *i;
        std::cout << this_item->return_name() <<std::endl;

    }
}

item_deck::item_deck(std::string dName, std::string dType)
{
    deck_name = dName;
    deck_type = dType;
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
            newWeap->create_weapon(itemN,itemT,arg3,arg4,arg5,arg6);
            this_item_deck.push_back(newWeap);
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
            newCons->create_consumable(itemN,itemT,arg3,arg4,arg5);
            this_item_deck.push_back(newCons);
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
            newBuff->create_buff(itemN,itemT,arg3,arg4,arg5);
            this_item_deck.push_back(newBuff);
        }
    }
}

item *item_deck::pull_from_item_deck()
{
    shuffle_deck();
    item *temp = this_item_deck.back();
    this_item_deck.pop_back();
    return temp;
}

item *item_deck::find_item(std::string)
{

}

//========================================================================================================

event_deck::event_deck(std::string dName, std::string dType)
{
    deck_name = dName;
    deck_type = dType;
}

void event_deck::add_to_deck(std::string fileName)
{
    std::cout << "Generating items for: " << deck_name <<std::endl;
    std::ifstream inFile;
    inFile.open(fileName.c_str());
    std::string line;           //Captures a line

    std::string eventN;      //event name
    std::string eventT;      //event type
    int eventID;            //eventID

    std::string typeT, statT, eventArg1, eventArg2, eventArg3;
    bool statC;
    int statVal;

    //std::string eventSprite

    if(!inFile)
    {
        std::cout<<"File Not found.."<<std::endl;
        return;
    }
    while(std::getline(inFile, line))
    {
        std::istringstream lineStream(line);
        std::getline(lineStream, line, ','); eventN = line;
        std::getline(lineStream, line, ','); eventT = line;
        std::getline(lineStream, line, ','); std::istringstream(line) >> eventID;
        if(eventT == "Location")
        {
            std::getline(lineStream, line, ','); typeT = line;
            std::getline(lineStream, line, ','); std::istringstream(line) >> std::boolalpha >> statC;
            std::getline(lineStream, line, ','); statT = line;
            std::getline(lineStream, line, ','); std::istringstream(line) >> statVal;
            std::getline(lineStream, line, ','); eventArg1 = line;
            std::getline(lineStream, line, ','); eventArg2 = line;
            std::getline(lineStream, line, ','); eventArg3 = line;

            location_event *newEvent = new location_event();
            newEvent->create_location_event(eventN,eventT,eventID,typeT,statC,statT,statVal,eventArg1,eventArg2,eventArg3);
            this_event_deck.push_back(newEvent);
        }
        else if(eventT == "Global")
        {

        }

    }
}

eventc *event_deck::pull_from_event_deck()
{
    shuffle_deck();
    eventc *temp = this_event_deck.back();
    this_event_deck.pop_back();
    return temp;
}

void event_deck::shuffle_deck()
{
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    auto r = std::default_random_engine (seed);
    std::shuffle(std::begin(this_event_deck), std::end(this_event_deck), r);
}

void event_deck::print_deck()
{
    for(std::vector<eventc*>::iterator i = this_event_deck.begin(); i != this_event_deck.end(); ++i)
    {
		eventc* this_event = *i;
        std::cout << this_event->return_event_name() <<std::endl;

    }
}





