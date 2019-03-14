#include "battleScene.h"
#include "textureLoader.h"

textureLoader *bsTex = new textureLoader();

battleScene::battleScene()
{
    //ctor
    xPos, yPos = 0.0;
    zoom = -5.0;
}

battleScene::~battleScene()
{
    //dtor
}

void battleScene::battleSceneInit(char *fileName)
{
    bsTex->bindTexture(fileName);
}

void battleScene::drawBattleScene()
{
    bsTex->binder();
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
