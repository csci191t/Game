#ifndef GLSCENE_H
#define GLSCENE_H

#include <windows.h>
#include <GL/glut.h>

class GLScene
{
    public:
        GLScene();              //constructor
        virtual ~GLScene();     //deconstructor

        GLint initGL();
        GLint drawGLScene();
        GLvoid resizeGLScene(GLsizei, GLsizei);

        //Pretty much a copy and pasted function found in main
        //Using this here, we can grab inputs from the Inputs class and have that specific
        //class do all the grabbing of the keyboard and mouse inputs
        int winMsg(HWND	hWnd, UINT uMsg, WPARAM	wParam, LPARAM lParam);

    protected:

    private:
};

#endif // GLSCENE_H
