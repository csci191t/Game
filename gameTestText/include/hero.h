#ifndef HERO_H
#define HERO_H

#include "string.h"
#include <vector>
#include "item.h"

class hero
{
	public:
		hero();
		~hero();
		//file name, hero name
		void create_hero(std::string, std::string);

		//Returns hero natural stats
		int return_max_health() {return mHealth;}
		int return_max_fortitude() {return mFortitude;}

		int return_move() {return movePT;}
		int return_evade() {return evadePT;}
		int return_attack() {return attPT;}
		int return_defense() {return defPT;}
		int return_mythology() {return mythPT;}
		int return_grit() {return gritPT;}
		int return_perception() {return percPT;}
		int return_luck() {return luckPT;}

		//Returns hero current life resources
		int return_current_health() {return currHealth;}
		int return_current_fortitude() {return currFort;}

		//Mostly updated via battles and negative events
		//To update values, these methods takes in total damage
		//Current resources cannot be negative, if resource=0, defeated/exhausted flag=True
		//If update is a recovery, the input values should be a negative value.
		void update_curr_health(int);
		void update_curr_fortitude(int);

		void add_item(item*);
		void remove_item(std::string);

		void print_hero_stat();

		//std::string return_sprite();

	protected:

	private:
		int check_statVal_override(int);	//any edits to game files that allow for overpowered unit values
		//all gets changed to value=1, essentially permanently nerfing the hero for the game.
		//Natural stat values are under 7. Natural resource values don't exceed 200.
		int check_resVal_override(int);

		//Natural Stats
		std::string hero_name;
		std::string hero_title;
		int mHealth;	//Hero max health
		int mFortitude;	//Hero max "sanity" or "mana"
		int movePT;		//movement points
		int evadePT;	//run from combat modifier
		int attPT;		//combat attack modifier
		int defPT;		//combat defense modifier
		int mythPT;		//"intelligence" check roll (to cast spells)
		int gritPT;		//combat "magic defense" modifier
		int percPT;		//"insight" roll for events
		int luckPT;		//luck roll for events

		//Current Health and Sanity
		int currHealth;
		int currFort;

		//IMPORTANT
		//need to construct classes for items
		std::vector<item*> inventory;

		bool defeated;		//After health is reduced to 0, this flag is triggered.
		bool exhausted;		//After fortitude is reduced to 0, this flag is triggered.
		bool death;			//If at health=0 and defeated is TRUE, hero is dead.
							//If at fortitude=0 and exhausted is TRUE, hero is dead.

		std::string hero_sprite;	//Link sprite file name here
};

#endif //HERO_H
