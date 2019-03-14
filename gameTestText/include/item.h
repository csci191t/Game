#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include "string.h"

class item	//parent class
{
	public:
		item();
		virtual ~item() {};

		std::string return_name() {return item_name;}
		std::string return_type() {return item_type;}
		int return_id()	{return item_ID;}

		void print_item(item*);

		std::string item_name;
		std::string item_type;
		int item_ID;

	protected:
	private:
};


class weapon : public item
{
	public:
		weapon() {};
		~weapon() {};

        //item name, item type, weapon type, damage, cooldown, item id
		void create_weapon(std::string, std::string, std::string, int, int, int);
		//Weapon type are one of 2: physical, magical

		std::string return_wType() {return weapon_type;}
		int return_wDmg() {return weapon_dmg;}
		int return_wCD() {return weapon_cd;}

		void print_weapon();

	protected:

	private:
		std::string weapon_type;
		int weapon_dmg;
		int weapon_cd;
		//std::string stat_type_sac;
		//int sac_amount;
};

class consumable : public item
{
	public:
		consumable() {};
		~consumable() {};

        //item name, item type, Recovery type, recovery amount, item id
		void create_consumable(std::string, std::string, std::string, int, int);
		//Recovery type are one of 4: health, fortitude, defeated, exhausted

		std::string return_rType() {return recover_type;}
		int return_rAmount() {return recover_amount;}

		void print_consumable();

	protected:

	private:
		std::string recover_type;
		int recover_amount;
};

class buff : public item
{
    public:
        buff() {};
        ~buff() {};

        //item name, item type, buff type, buff amount, item id
        void create_buff(std::string, std::string, std::string, int, int);

        std::string return_buff_type() {return buff_type;}
        int return_buff_amount() {return buff_amount;}

        void print_buff();
    protected:
    private:
        std::string buff_type;
        int buff_amount;

};

class misc : public item
{
	public:
		misc() {};
		~misc() {};

		//item name, item type, misc type, item id
		void create_misc(std::string, std::string, std::string, int);
		//Misc type, for now, is only one: monster drop

		std::string return_mType() {return misc_type;}

	protected:

	private:
		std::string misc_type;
};
#endif //ITEM_H
