#include <iostream>
#include <fstream>
#include <sstream>
#include "hero.h"
#include <string>
#include <algorithm>

hero::hero()
{
    hero_name ="";
    hero_title ="";
    mHealth, currHealth =1;
    mFortitude, currFort =1;
    movePT, evadePT, attPT, defPT, mythPT, gritPT, percPT, luckPT =1;
    defeated, exhausted, death = false;

    hero_sprite = "";
}


void hero::create_hero(std::string fileName, std::string heroName)
{
    std::ifstream inFile;
    inFile.open(fileName.c_str());
    std::string line;
    if(!inFile)
    {
        std::cout<<"File Not found.."<<std::endl;
        return;
    }
    while(std::getline(inFile, line))
    {
        std::istringstream lineStream(line);
        std::getline(lineStream, line, ',');
        if(line == heroName)
        {
            hero_name = line;
            std::getline(lineStream, line, ','); hero_title = line;
            std::getline(lineStream, line, ','); std::istringstream(line) >> mHealth; //mHealth = check_resVal_override(mHealth);
            std::getline(lineStream, line, ','); std::istringstream(line) >> mFortitude; //mFortitude = check_resVal_override(mFortitude);
            std::getline(lineStream, line, ','); std::istringstream(line) >> movePT; //movePT = check_statVal_override(movePT);
            std::getline(lineStream, line, ','); std::istringstream(line) >> evadePT; //evadePT = check_statVal_override(evadePT);
            std::getline(lineStream, line, ','); std::istringstream(line) >> attPT; //attPT = check_statVal_override(attPT);
            std::getline(lineStream, line, ','); std::istringstream(line) >> defPT; //defPT = check_statVal_override(defPT);
            std::getline(lineStream, line, ','); std::istringstream(line) >> mythPT; //mythPT = check_statVal_override(mythPT);
            std::getline(lineStream, line, ','); std::istringstream(line) >> gritPT; //gritPT = check_statVal_override(gritPT);
            std::getline(lineStream, line, ','); std::istringstream(line) >> percPT; //percPT = check_statVal_override(percPT);
            std::getline(lineStream, line, ','); std::istringstream(line) >> luckPT; //luckPT = check_statVal_override(luckPT);
            std::getline(lineStream, line, ';');
        }
    }


	currHealth = mHealth;
	currFort = mFortitude;

}

int hero::check_statVal_override(int x)
{
	if(x >= 8)
    {
        return 1;
    }
}

int hero::check_resVal_override(int x)
{
    if(x >=200)
    {
        return 10;
    }
}

void hero::update_curr_health(int tDmg)
{
	currHealth = currHealth - tDmg;
	if(currHealth <= 0)
	{
		defeated = true;
		currHealth = 0;
	}
	else if(currHealth >= mHealth)
    {
        currHealth = mHealth;
    }
	else
	{
		defeated = false;
	}
}

void hero::update_curr_fortitude(int tDmg)
{
	currFort = currFort - tDmg;
	if(currFort <= 0)
	{
		exhausted = true;
		currFort = 0;
	}
	else if(currFort >= mFortitude)
    {
        currFort = mFortitude;
    }
	else
	{
		exhausted = false;
	}
}

void hero::print_hero_stat()
{
    std::cout<<"Name: "<< hero_name<<std::endl;
    std::cout<<"Title: "<< hero_title<<std::endl;
    std::cout<<"MaxHealth: "<< mHealth<<std::endl;
    std::cout<<"MaxFortitude: "<< mFortitude<<std::endl;
    std::cout<<"Movement: "<< movePT<<std::endl;
    std::cout<<"Evasion: "<< evadePT<<std::endl;
    std::cout<<"Attack: "<< attPT<<std::endl;
    std::cout<<"Defense: "<< defPT<<std::endl;
    std::cout<<"Mythology: "<<mythPT<<std::endl;
    std::cout<<"Grit: "<< gritPT<<std::endl;
    std::cout<<"Perception: "<< percPT<<std::endl;
    std::cout<<"Luck: "<< luckPT<<std::endl;
}

void hero::add_item(item *newItem)
{
    std::cout<<"Adding "<<newItem->return_name()<<" to "<<hero_name<<" inventory."<<std::endl;
    inventory.push_back(newItem);
}

void hero::remove_item(std::string itemName)
{
    std::vector<item*>::iterator it;
    it = std::find_if(inventory.begin(), inventory.end(), [itemName](item * obj){return obj->return_name() == itemName;});
    if(it != inventory.end())
    {
        std::cout<<itemName<<" found in inventory. Preparing delete."<<std::endl;
    }
    else
    {
        std::cout<<itemName<<" not found. No remove from inventory."<<std::endl;
    }
}
