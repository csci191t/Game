#include "heroTeam.h"

heroTeam::heroTeam(int max_items)
{
    //ctor
    num_heroes = max_items;
    heroName.resize(num_heroes);
    hTex.resize(num_heroes);
    spriteVector.resize(num_heroes);
    spriteCoord.resize(num_heroes);

    for(int i=0; i<num_heroes; i++)
    {
        //initialize hero names
        heroName[i] = "";

        //initialize texture loader pointer class
        hTex[i] = new textureLoader();

        //each item in sprite vector contains 4 vector coordinates to draw square
        vec *vertices = new vec[4];
        spriteVector[i] = vertices;
        spriteVector[i][0].x = 0.0;
        spriteVector[i][0].y = 0.0;
        spriteVector[i][0].z = -5;

        spriteVector[i][1].x = 0.4;
        spriteVector[i][1].y = 0.0;
        spriteVector[i][1].z = -5;

        spriteVector[i][2].x = 0.4;
        spriteVector[i][2].y = 0.4;
        spriteVector[i][2].z = -5;

        spriteVector[i][3].x = 0.0;
        spriteVector[i][3].y = 0.4;
        spriteVector[i][3].z = -5;

        //each item contains the texture mapping for the texture
        spriteCoord[i].xMin = 0.0;
        spriteCoord[i].xMax = 0.09;
        spriteCoord[i].yMin = 0.29;
        spriteCoord[i].yMax = 0.34;
    }
}

heroTeam::~heroTeam()
{
    //dtor
}

void heroTeam::initHero(char* fileName, std::string hero_name, int indx)
{
    heroName[indx] = hero_name;
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    hTex[indx]->bindTexture(fileName);
}

void heroTeam::drawHero(int indx)
{
    hTex[indx]->binder();
    glBegin(GL_QUADS);

    glTexCoord2f(spriteCoord[indx].xMin,spriteCoord[indx].yMax);
    glVertex3f(spriteVector[indx][0].x,spriteVector[indx][0].y,spriteVector[indx][0].z);

    glTexCoord2f(spriteCoord[indx].xMax,spriteCoord[indx].yMax);
    glVertex3f(spriteVector[indx][1].x,spriteVector[indx][1].y,spriteVector[indx][1].z);

    glTexCoord2f(spriteCoord[indx].xMax,spriteCoord[indx].yMin);
    glVertex3f(spriteVector[indx][2].x,spriteVector[indx][2].y,spriteVector[indx][2].z);

    glTexCoord2f(spriteCoord[indx].xMin,spriteCoord[indx].yMin);
    glVertex3f(spriteVector[indx][3].x,spriteVector[indx][3].y,spriteVector[indx][3].z);

    glEnd();
}
