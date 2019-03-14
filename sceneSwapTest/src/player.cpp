#include "player.h"
#include <iostream>
#include <textureLoader.h>

textureLoader *pTex = new textureLoader();

player::player()
{
    //ctor
    vertices[0].x =0.0;     //First vertex when drawn
    vertices[0].y =0.0;
    vertices[0].z =-1.0;

    vertices[1].x =0.1;     //second vertex, etc.
    vertices[1].y =0.0;
    vertices[1].z =-1.0;

    vertices[2].x =0.1;
    vertices[2].y =0.1;
    vertices[2].z =-1.0;

    vertices[3].x =0.0;
    vertices[3].y =0.1;
    vertices[3].z =-1.0;

    xMin, yMin = 0;
    xMax, yMax = 1;
}

player::~player()
{
    //dtor
}

void player::drawPlayer()
{
    glPushMatrix();
    pTex->binder();
    glBegin(GL_QUADS);

    glTexCoord2f(xMin,yMax);
    glVertex3f(vertices[0].x,vertices[0].y,vertices[0].z);

    glTexCoord2f(xMax,yMax);
    glVertex3f(vertices[1].x,vertices[1].y,vertices[1].z);

    glTexCoord2f(xMax,yMin);
    glVertex3f(vertices[2].x,vertices[2].y,vertices[2].z);

    glTexCoord2f(xMin,yMin);
    glVertex3f(vertices[3].x,vertices[3].y,vertices[3].z);

    glEnd();
    glPopMatrix();

}

void player::playerInit(char *fileName)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    pTex->bindTexture(fileName);

    xMin=0.0;
    xMax=0.1;

    yMin=0.29;
    yMax=0.34;
}

void player::playerAction()
{

}
