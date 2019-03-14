#include "gameScene.h"
#include "textureLoader.h"

textureLoader *gsTex = new textureLoader();

gameScene::gameScene()
{
    //ctor
    xPos, yPos = 0.0;
    zoom = -5.0;
}

gameScene::~gameScene()
{
    //dtor
}

void gameScene::gameSceneInit(char *fileName)
{
    gsTex->bindTexture(fileName);
}

void gameScene::drawGameScene()
{
    gsTex->binder();
    glTranslated(xPos,yPos,zoom);
    //glPushMatrix();
        glBegin(GL_QUADS);
            glTexCoord2f(0,1);
            glVertex3f(-19,-10.8,-5);

            glTexCoord2f(0,0);
            glVertex3f(-19,10.8,-5);

            glTexCoord2f(1,0);
            glVertex3f(19,10.8,-5);

            glTexCoord2f(1,1);
            glVertex3f(19,-10.8,-5);
        glEnd();
    //glPopMatrix();
}
