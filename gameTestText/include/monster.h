#ifndef MONSTER_H
#define MONSTER_H

#include "string.h"
#include "item.h"

class monster
{
    public:
        monster();
        virtual ~monster();


        void create_monster(std::string, std::string);      //Extracts monster information the same as Hero.cpp
        std::string return_name() {return monster_name;}
        int return_id() {return monster_id;}

        int return_mHealth() {return mHealth;}
        int return_mcHealth() {return mcHealth;}
        int return_att() {return mAtt;}
        int return_def() {return mDef;}
        int return_grit() {return mGrit;}
        int return_move() {return mMove;}

        bool return_PResist() {return physicalResistance;}
        bool return_MResist() {return magicalResistance;}
        bool return_pImmune() {return physicalyImmune;}
        bool return_mImmune() {return magicallyImmune;}

        int return_buff_check_fright();     //Checks boolean frightening and returns fright value
        int return_buff_check_power();      //Checks boolean powerful and returns power value

        void update_mcHealth(int);
        void print_monster_stats();


    protected:

    private:
        std::string monster_name;
        int monster_id;

        int mHealth;        //Monster max health
        int mcHealth;       //Monster current health
        int mAtt;           //monster attack power
        int mDef;           //monster defense power
        int mGrit;          //monster magical defense
        int mMove;          //monster movement/speed

        bool physicalResistance;        //Resistant against physical weapons half incoming dmg taken
        bool magicalResistance;         //Resistant against magical weapons or spells half incoming dmg taken
        bool physicalyImmune;           //Immune to physical weapons (except base attack), no dmg taken
        bool magicallyImmune;           //Immune to magical weapons or spells (except base attack), no dmg taken

        bool frightening;       //Monster initial fear factor against hero Grit
        bool powerful;          //Monster initial overwhelming factor against Hero Def

        int frightValue;        //Dmg value against hero Fortitude
        int powerValue;         //Dmg value against hero Health

        std::string monster_sprite;

};

#endif // MONSTER_H
