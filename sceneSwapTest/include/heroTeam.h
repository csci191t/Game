#ifndef HEROTEAM_H
#define HEROTEAM_H

#include <iostream>
#include "player.h"
#include "textureLoader.h"
#include "commonUtils.h"
#include <vector>
#include <string>

class heroTeam
{
    public:
        heroTeam(int);                                  //initialize list of heroes with a vector size
        virtual ~heroTeam();

        void initHero(char*,std::string,int);           //Requires the fileName, name of hero, and the index of hero

        void drawHero(int);                             //Draws the hero at index #

        std::vector<std::string> heroName;              //List of hero's name with respect to vector's index
        std::vector<textureLoader*> hTex;               //Texture Loader pointer for each hero
        std::vector<vec*> spriteVector;                 //List of 4 vector points per object drawing
        std::vector<texCoord> spriteCoord;              //List of texture loading for sprites

    protected:

    private:
        int num_heroes;
};

#endif // HEROTEAM_H
