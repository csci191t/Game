#include "monster.h"
#include <fstream>
#include <sstream>

monster::monster()
{
    //ctor
    monster_name = "";
    monster_id = 0;
    mHealth, mcHealth, mAtt, mDef, mGrit, mMove = 0;
    physicalResistance, physicalyImmune, magicallyImmune, magicalResistance = false;
    frightening, powerful = false;
    frightValue, powerValue = 0;
}

monster::~monster()
{
    //dtor
}

void monster::create_monster(std::string fileName, std::string mName)
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
        if(line == mName)
        {
            monster_name = line;
            std::getline(lineStream, line, ','); std::istringstream(line) >> monster_id;
            std::getline(lineStream, line, ','); std::istringstream(line) >> mHealth;
            std::getline(lineStream, line, ','); std::istringstream(line) >> mAtt;
            std::getline(lineStream, line, ','); std::istringstream(line) >> mDef;
            std::getline(lineStream, line, ','); std::istringstream(line) >> mGrit;
            std::getline(lineStream, line, ','); std::istringstream(line) >> mMove;
            std::getline(lineStream, line, ','); std::istringstream(line) >> std::boolalpha >> physicalResistance;
            std::getline(lineStream, line, ','); std::istringstream(line) >> std::boolalpha >> magicalResistance;
            std::getline(lineStream, line, ','); std::istringstream(line) >> std::boolalpha >> physicalyImmune;
            std::getline(lineStream, line, ','); std::istringstream(line) >> std::boolalpha >> magicallyImmune;
            std::getline(lineStream, line, ','); std::istringstream(line) >> std::boolalpha >> frightening;
            std::getline(lineStream, line, ','); std::istringstream(line) >> std::boolalpha >> powerful;
            std::getline(lineStream, line, ','); std::istringstream(line) >> frightValue;
            std::getline(lineStream, line, ','); std::istringstream(line) >> powerValue;
            std::getline(lineStream, line, ',');
        }
    }
    mcHealth = mHealth;
}


int monster::return_buff_check_fright()
{
    if(frightening)
    {
        return frightValue;
    }
    else
    {
        return 0;
    }
}

int monster::return_buff_check_power()
{
    if(powerful)
    {
        return powerValue;
    }
    else
    {
        return 0;
    }
}

void monster::update_mcHealth(int dmgVal)
{
    mcHealth = mcHealth - dmgVal;
    if(mcHealth <= 0)
    {
        mcHealth = 0;
    }
}

void monster::print_monster_stats()
{
    std::cout<<"Name: "<< monster_name<<std::endl;
    std::cout<<"ID: "<< monster_id<<std::endl;
    std::cout<<"MaxHealth: "<< mHealth<<std::endl;
    std::cout<<"Attack: "<< mAtt<<std::endl;
    std::cout<<"Defense: "<< mDef<<std::endl;
    std::cout<<"Grit: "<< mGrit<<std::endl;
    std::cout<<"Movement: "<< mMove<<std::endl;
    std::cout<<"PhysicalResist: "<< std::boolalpha << physicalResistance<<std::endl;
    std::cout<<"MagicalResist: "<< std::boolalpha << magicalResistance<<std::endl;
    std::cout<<"PhysicalImmunity: "<< std::boolalpha << physicalyImmune<<std::endl;
    std::cout<<"MagicalImmunity: "<< std::boolalpha << magicallyImmune<<std::endl;
    std::cout<<"Frightening: "<< std::boolalpha << frightening<<std::endl;
    std::cout<<"Powerful: "<< std::boolalpha << powerful<<std::endl;
    std::cout<<"FrightVal: "<< frightValue<<std::endl;
    std::cout<<"PowerVal: "<< powerValue<<std::endl;
}
