#include "GLScene.h"

#include "GLLight.h"
#include "Model.h"
#include "Inputs.h"
#include <vector>

#include "heroTeam.h"
#include "gameScene.h"
#include "gameSceneHud.h"
#include "locationsList.h"
#include "battleScene.h"

Inputs *KbMs = new Inputs();
Model *modelTeapot = new Model();

heroTeam *heroes = new heroTeam(2);
locationsList *locs = new locationsList(1);

gameScene *game = new gameScene();
battleScene *battle = new battleScene();

gameSceneHud *hud = new gameSceneHud();

GLScene::GLScene()
{
    //ctor
    screenHeight= GetSystemMetrics(SM_CYSCREEN);
    screenWidth = GetSystemMetrics(SM_CXSCREEN);
}

GLScene::~GLScene()
{
    //dtor
}

GLint GLScene::initGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

   // glEnable(GL_COLOR_MATERIAL);
    GLLight Light(GL_LIGHT0);

    game->gameSceneInit("images/large.png");
    battle->battleSceneInit("images/Eureka.png");


    //game->gameSceneInit("images/Eureka.png");

    heroes->initHero("images/exampleHero1.png","Gerald",0);
    heroes->initHero("images/exampleHero2.png","Amelia",1);

    hud->gsHudInit("images/border3.png");

    locs->initLocation("images/house1.png", "House",0);


    return true;
}

GLint GLScene::drawGLScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();									// Reset The Current Modelview Matrix

	int control = KbMs->sceneController;
	switch(control)
	{
    //Button press keyboard: 1 swaps to large.png scene
    case 0:
        glPushMatrix();
        game->drawGameScene();

        glPushMatrix();
        glTranslatef(0.0,0.5,0.0);
        heroes->drawHero(0);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.5,-0.5,0.0);
        heroes->drawHero(1);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(1.0,1.0,0.0);
        locs->drawLocation(0);
        glPopMatrix();

        glPopMatrix();
        glPopMatrix();
        break;
    //Button press keyboard: 2 switches to Eureka Scene
    case 1:
        glPushMatrix();
        battle->drawBattleScene();
        glPopMatrix();
        break;
	}

	/*glPushMatrix();
	game->drawGameScene();
	glPopMatrix();*/

	hud->gsHudDraw();
}

GLvoid GLScene::resizeGLScene(GLsizei width, GLsizei height)
{
   GLfloat aspectRatio = (GLfloat)width/(GLfloat)height;
   glViewport(0,0,width,height);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(45.0,aspectRatio,0.1,100);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

int GLScene::windMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)									// Check For Windows Messages
	{

	    case WM_KEYDOWN:
	        KbMs->wParam = wParam;
	        KbMs->keyPressed(game);
	    break;

	    case WM_KEYUP:								// Has A Key Been Released?
		{
			KbMs->wParam = wParam;
			KbMs->keyUP();
		break;								// Jump Back
		}

		case WM_LBUTTONDOWN:
        {
            KbMs->wParam = wParam;
            KbMs->mouseEventDown(game,LOWORD(lParam),HIWORD(lParam));
        break;								// Jump Back
        }

   		case WM_RBUTTONDOWN:
        {
            KbMs->wParam = wParam;
            KbMs->mouseEventDown(game,LOWORD(lParam),HIWORD(lParam));
        break;								// Jump Back
        }

          case WM_MBUTTONDOWN:
        {
            KbMs->wParam = wParam;
            KbMs->mouseEventDown(game,LOWORD(lParam),HIWORD(lParam));
        break;								// Jump Back
        }

        case WM_LBUTTONUP:
        case WM_RBUTTONUP:
        case WM_MBUTTONUP:
        {
            KbMs->mouseEventUp();
        break;								// Jump Back
        }

        case WM_MOUSEMOVE:
        {
             KbMs->mouseMove(game, LOWORD(lParam),HIWORD(lParam));
        break;								// Jump Back
        }

        case WM_MOUSEWHEEL:
        {
            KbMs->mouseWheel(game,(double)GET_WHEEL_DELTA_WPARAM(wParam));
        break;								// Jump Back
        }
}
}
