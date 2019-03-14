#ifndef INPUTS_H
#define INPUTS_H

#include <windows.h>
#include <iostream>
#include "gameScene.h"


class Inputs
{
    public:
        Inputs();
        virtual ~Inputs();

        void keyPressed(gameScene *);
        void keyUP();
        //void keyEnv(float); // movements of my background

        void mouseEventDown(gameScene *,double ,double);
        void mouseEventUp();
        void mouseWheel(gameScene *,double);
        void mouseMove(gameScene *,double ,double );

        double prev_Mouse_X;
        double prev_Mouse_Y;
        bool Mouse_Translate;
        bool Mouse_Roatate;

        WPARAM wParam;

        int sceneController;

    protected:

    private:
};

#endif // INPUTS_H
