#ifndef INPUTS_H
#define INPUTS_H
#include <windows.h>

class Inputs
{
    public:
        Inputs();
        virtual ~Inputs();

        void keyPressed();
        void keyUp();

        void mouseEventDown(double, double);
        void mouseEventUp();
        void mouseEventWheel(double);
        void mouseEventMove(double, double);

        double prev_mouse_x;
        double prev_mouse_y;

        bool mouse_Translate;
        bool mouse_Rotate;

        /*************** This part is temporary *****************/
            float RotateX, RotateY, RotateZ, Zoom, xPos, yPos;


        /********************************************/


        WPARAM wParam;

    protected:

    private:
};

#endif // INPUTS_H
