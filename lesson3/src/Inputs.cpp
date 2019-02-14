#include "Inputs.h"

Inputs::Inputs()
{
    //ctor
    prev_mouse_x = 0;
    prev_mouse_y =0;

    mouse_Translate =false;
    mouse_Rotate =false;

    RotateX =0;
    RotateY =0;
    RotateZ =0;
    Zoom =-8.0;

    xPos = 0;
    yPos = 0;
}

Inputs::~Inputs()
{
    //dtor
}

void Inputs::keyPressed()
{
    switch(wParam)
    {
    case VK_LEFT:
        RotateX -=1.0;
        break;
    case VK_RIGHT:
        RotateX +=1.0;
        break;
    case VK_UP:
        RotateY -=1.0;
        break;
    case VK_DOWN:
        RotateY +=1.0;
        break;
    case VK_ADD:
        Zoom +=1.0;
        break;
    case VK_SUBTRACT:
        Zoom -=1.0;
        break;
    }
}

void Inputs::keyUp()
{

}

//When mouse button is clicked (or in down position), enable rotation and translation FLAGS
void Inputs::mouseEventDown(double x, double y)
{
    prev_mouse_x = x;
    prev_mouse_y = y;

    switch (wParam)
    {
        case MK_LBUTTON:
            mouse_Rotate =true;
            break;
        case MK_RBUTTON:
            mouse_Translate =true;
            break;
        case MK_MBUTTON:
            break;
        default: break;
    }
}

void Inputs::mouseEventUp()
{
    //Release mouse button, sets the conditions to false, meaning
    //you will stop rotating / translating
    mouse_Rotate = false;
    mouse_Translate = false;
}

void Inputs::mouseEventWheel(double delta)
{
    //Zoom in and out using mouse wheel
    Zoom += delta/100;
}

//For now, only moves along the x and y axis. Don't really need to
//implement for z axis.
void Inputs::mouseEventMove(double x, double y)
{
    if(mouse_Translate)
    {
        xPos += (x-prev_mouse_x)/100;
        yPos -= (y-prev_mouse_y)/100;

        prev_mouse_x = x;
        prev_mouse_y = y;
    }
    if(mouse_Rotate)
    {
        RotateX += (x-prev_mouse_x)/3;
        RotateY += (y-prev_mouse_y)/3;

        prev_mouse_x = x;
        prev_mouse_y = y;
    }
}
