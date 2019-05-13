#include "GLScene.h"
#include "GLLight.h"
#include "Inputs.h"
#include "timer.h"
#include "worldMap.h"
#include "locSprite.h"
#include "connector.h"
#include "heroSprite.h"
#include "location.h"
#include "monster.h"
#include "titleScreen.h"
#include "titleController.h"
#include "titleObject.h"

#define L_MAX 3
#define M_MAX 20
#define T_MAX 3

Inputs *KbMs = new Inputs();

worldMap *gondora = new worldMap();
locSprite locations[L_MAX];
location locMap[L_MAX];
monster monsterList[M_MAX];
connector lines[2];
heroSprite *hero = new heroSprite();
timer *time_ = new timer();
titleScreen *title = new titleScreen();
titleController *controller = new titleController();
titleObject selection[T_MAX];

GLScene::GLScene()
{
    // constructor
    screenHeight= GetSystemMetrics(SM_CYSCREEN);
    screenWidth = GetSystemMetrics(SM_CXSCREEN);
}

GLScene::~GLScene()
{
    // destructor
}

GLint GLScene::initGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    //glEnable(GL_COLOR_MATERIAL);
    GLLight Light(GL_LIGHT0);

    gondora->initWM("images/worldMap/Kartoja.png");

    locations[0].initLS("images/locPNG/portAlleyway.png"); locations[0].setLocation(-5.0, -2.0, 0.0);
    locations[1].initLS("images/locPNG/merchantPlaza.png"); locations[1].setLocation(0.0, 0.0, 1.0);
    locations[2].initLS("images/locPNG/theAtrium.png"); locations[2].setLocation(5.0, 5.0, 2.0);

    locations[0].setNextLoc(&locations[1], "east");
    locations[1].setNextLoc(&locations[2], "east");
    locations[1].setNextLoc(&locations[0], "west");
    locations[2].setNextLoc(&locations[1], "west");

    lines[0].initConnector("images/locPNG/line.png", -7, -3); lines[0].rotation = 20.0;
    lines[1].initConnector("images/locPNG/line.png", 2, 4); lines[1].rotation = 50.0;

    hero->initHS("images/hero/hero.png", -4.0, -1.0);
    hero->loc_index=locations[0].returnLocIndex();

    locMap[0].getLayout("maps/map1.txt");
    locMap[0].initLocation("images/locBack/parallax.png");
    locMap[0].initRoads("images/tiles/floor1.png");

    locMap[0].locAvailable = true;

    locMap[1].getLayout("maps/map1.txt");
    locMap[1].initLocation("images/locBack/parallax3.png");
    locMap[1].initRoads("images/tiles/floor3.png");

    locMap[1].locAvailable = true;

    monsterList[0].setFrames(6.0, 8.0);
    monsterList[0].initMonster("images/monsters/monster4.png");
    monsterList[0].frameDirection(2.0, 0.0, 6.0, 4.0);
    monsterList[0].liveMonster = true;
    monsterList[0].monsterPlacement = true;

    title->initTS("images/title/Title.png", screenWidth, screenHeight);
    controller->initTC("images/title/selectIcon.png", -12.0, 2.0);

    selection[0].initTO("images/title/playGame.png", -7.5, 0.0);
    selection[1].initTO("images/title/information.png", -7.5, -5.0);
    selection[2].initTO("images/title/quit.png", -7.5, -10.0);

    selection[0].setObjectLink(NULL, &selection[1]);
    selection[1].setObjectLink(&selection[0], &selection[2]);
    selection[2].setObjectLink(&selection[1], NULL);

    return true;
}

GLint GLScene::drawGLScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
    glLoadIdentity();

    if(title->liveTS)
    {
        glPushMatrix();
            title->drawTS();
            controller->drawTC();
            selection[0].drawTO();
            selection[1].drawTO();
            selection[2].drawTO();

            controller->animateController();
        glPopMatrix();
    }
    if(gondora->worldMapLive)
    {
        glPushMatrix();
        glTranslatef(gondora->view.xLoc-hero->return_hero_wmLoc().xLoc, gondora->view.yLoc-hero->return_hero_wmLoc().yLoc, gondora->zoom);
        gondora->drawWM();

        lines[0].drawConnector();
        lines[1].drawConnector();

        locations[0].drawLS();
        locations[1].drawLS();
        locations[2].drawLS();

        hero->drawHS();
        hero->animateHero();

        glPopMatrix();
    }
    if(locMap[hero->loc_index].locationLive && locMap[hero->loc_index].locAvailable)
    {
        glPushMatrix();
        locMap[hero->loc_index].drawLocation(hero, monsterList, M_MAX);
        locMap[hero->loc_index].scrollBackground();
        //hero->moveHero();
        //hero->heroAttack0();
        monsterList[0].animateMonster(hero->return_hero_bLoc().xLoc, hero->return_hero_bLoc().yLoc, locMap[hero->loc_index].return_map_minX(), locMap[hero->loc_index].return_map_maxX(), locMap[hero->loc_index].return_map_minY(), locMap[hero->loc_index].return_map_maxY());
        glPopMatrix();
    }
}

GLvoid GLScene::resizeGLScene(GLsizei width, GLsizei height)
{
    GLfloat aspectRatio = (GLfloat)width / (GLfloat)height;
    glViewport(0.0, 0.0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, aspectRatio, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int GLScene::windMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)									// Check For Windows Messages
    {

    case WM_KEYDOWN:
        KbMs->wParam = wParam;
        KbMs->keyPressed(title, controller, selection, T_MAX, gondora, locations, L_MAX, hero, locMap, L_MAX);
        break;

    case WM_KEYUP:								// Has A Key Been Released?
    {
        KbMs->wParam = wParam;
        KbMs->keyUP(hero, locMap, M_MAX);
        break;								// Jump Back
    }

    case WM_LBUTTONDOWN:
    {
        KbMs->wParam = wParam;
        //KbMs->mouseEventDown(gmap,heroTeam,LOWORD(lParam),HIWORD(lParam));
        break;								// Jump Back
    }

    case WM_RBUTTONDOWN:
    {
        KbMs->wParam = wParam;
        //KbMs->mouseEventDown(gmap,heroTeam,LOWORD(lParam),HIWORD(lParam));
        break;								// Jump Back
    }

    case WM_MBUTTONDOWN:
    {
        KbMs->wParam = wParam;
        //KbMs->mouseEventDown(gmap,heroTeam,LOWORD(lParam),HIWORD(lParam));
        break;								// Jump Back
    }

    case WM_LBUTTONUP:
    case WM_RBUTTONUP:
    case WM_MBUTTONUP:
    {
        //KbMs->mouseEventUp();
        break;								// Jump Back
    }

    case WM_MOUSEMOVE:
    {
        //KbMs->mouseMove(gmap, LOWORD(lParam),HIWORD(lParam));
        break;								// Jump Back
    }

    case WM_MOUSEWHEEL:
    {
        //KbMs->mouseWheel(gmap,(double)GET_WHEEL_DELTA_WPARAM(wParam));
        break;								// Jump Back
    }
    }
}

