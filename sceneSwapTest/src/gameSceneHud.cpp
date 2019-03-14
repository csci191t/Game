#include "gameSceneHud.h"
#include "textureLoader.h"
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>

textureLoader *hdTex = new textureLoader();

gameSceneHud::gameSceneHud()
{
    //ctor
}

gameSceneHud::~gameSceneHud()
{
    //dtor
}

void gameSceneHud::gsHudInit(char *fileName)
{
    glEnable(GL_BLEND);                                 //Begin transparent image texture bind
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  //Set the model's empty space to transparent from image
    hdTex->bindTexture(fileName);
}

void gameSceneHud::gsHudDraw()
{
    //Before drawing the HUD, must push a new matrix and setup a 2D overlay. Also disable, then re-enable GL_DEPTH_TEST.
    //Make sure to push and pop matrix in order of matrixMode
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(-300,300,-300,300);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glDisable(GL_DEPTH_TEST);

    hdTex->binder();
    glBegin(GL_QUADS);
        glTexCoord2f(0,1);
        glVertex3f(200,-150,0);
        glTexCoord2f(0,0);
        glVertex3f(-200,-150,0);
        glTexCoord2f(1,0);
        glVertex3f(-200,-300,0);
        glTexCoord2f(1,1);
        glVertex3f(200,-300,0);
    glEnd();

    glEnable(GL_DEPTH_TEST);
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}
