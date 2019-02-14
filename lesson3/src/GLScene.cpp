#include "GLScene.h"
#include "GLLight.h"
#include "Inputs.h"

//Calls the inputs from the built in Inputs Class
Inputs *KMs = new Inputs();

GLScene::GLScene()
{
    //ctor
}

GLScene::~GLScene()
{
    //dtor
}


//===============================================================
GLint GLScene::initGL()
{
    glShadeModel(GL_SMOOTH);                //for good transitions in animations
    glClearColor(1.0f, 0.0f, 0.0f, 0.0f);   //set background color
    glClearDepth(1.0f);                     //decide what is at front and behind
    glEnable(GL_DEPTH_TEST);                //depth calculations


    glEnable(GL_COLOR_MATERIAL);

    GLLight Light(GL_LIGHT0);               //create light instance

    Light.SetLight(GL_LIGHT0);

    return true;
}

GLint GLScene::drawGLScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslated(KMs->xPos, KMs->yPos, KMs->Zoom);    //for zooming in and out
    glRotated(KMs->RotateX, 0,1,0); //rotate teapot along y axis
    glRotated(KMs->RotateY, 1,0,0); //rotate teapot along y axis
    glRotated(KMs->RotateZ, 0,0,1); //This doesn't work atm
    glColor3f(0.0,1.0,0.0);
    glutSolidTeapot(1.5);
}

GLvoid GLScene::resizeGLScene(GLsizei width, GLsizei height)
{
    GLfloat aspectRatio = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, aspectRatio, 0.1, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

int GLScene::winMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_KEYUP:
        {
            break;
        }
        case WM_KEYDOWN:
        {
            KMs->wParam = wParam;   //Uses the inputs taken from the KMs (Inputs) class
            KMs->keyPressed();
            break;
        }
        case WM_LBUTTONDOWN:
        {
            KMs->wParam = wParam;   //Uses the inputs taken from the KMs (Inputs) class
            KMs->mouseEventDown(LOWORD(lParam),HIWORD(lParam));
            break;								// Jump Back
        }
        case WM_RBUTTONDOWN:
        {
            KMs->wParam = wParam;   //Uses the inputs taken from the KMs (Inputs) class
            KMs->mouseEventDown(LOWORD(lParam),HIWORD(lParam));
            break;								// Jump Back
        }

          case WM_MBUTTONDOWN:
        {
            KMs->wParam = wParam;   //Uses the inputs taken from the KMs (Inputs) class
            KMs->mouseEventDown(LOWORD(lParam),HIWORD(lParam));
            break;								// Jump Back
        }

        case WM_LBUTTONUP:
        case WM_RBUTTONUP:
        case WM_MBUTTONUP:
        {
            KMs->mouseEventUp();
            break;								// Jump Back
        }

        case WM_MOUSEMOVE:
        {
            KMs->mouseEventMove(LOWORD(lParam),HIWORD(lParam));
            break;								// Jump Back
        }

        case WM_MOUSEWHEEL:
        {
            KMs->mouseEventWheel((double)GET_WHEEL_DELTA_WPARAM(wParam));
            break;								// Jump Back
        }
        default: break;
    }
}
