#include "Inputs.h"


Inputs::Inputs()
{
    //ctor
   prev_Mouse_X =0;
   prev_Mouse_Y =0;
   Mouse_Translate=0;
   Mouse_Roatate=0;

   sceneController = 0;
}

Inputs::~Inputs()
{
    //dtor
}

/*void Inputs::keyEnv(float speed)
{
    switch(wParam)
    {
        case VK_LEFT:
            plx->Xmin -=speed;
            plx->Xmax -=speed;
            break;

        case VK_RIGHT:
            plx->Xmin +=speed;
            plx->Xmax +=speed;
            break;

         case VK_UP:
            plx->Ymin -=speed;
            plx->Ymax -=speed;
            break;

        case VK_DOWN:
            plx->Ymin +=speed;
            plx->Ymax +=speed;
            break;

    }
}*/


void Inputs::keyPressed(gameScene* Mdl)
{
    switch(wParam)
    {
    /*case VK_LEFT:
        Mdl->RotateX +=1.0;
        break;

    case VK_RIGHT:
        Mdl->RotateX -=1.0;
        break;

    case VK_DOWN:
        Mdl->RotateY -=1.0;
        break;

    case VK_UP:
        Mdl->RotateY +=1.0;
        break;

    case VK_ADD:
        Mdl->Zoom +=1.0;
        break;

    case VK_SUBTRACT:
        Mdl->Zoom -=1.0;
        break;*/

    case 0x57:      //W Key Up
        Mdl->yPos -= 0.2;
        break;
    case 0x53:      //S key Down
        Mdl->yPos +=0.2;
        break;
    case 0x41:      //A key Left
        Mdl->xPos +=0.2;
        break;
    case 0x44:      //D key Right
        Mdl->xPos -=0.2;
        break;
    case 0x31:
        sceneController = 0;
        break;
    case 0x32:
        sceneController = 1;
        break;

    }
}


void Inputs::keyUP()
{
  switch (wParam)
            {
                default:
                break;
            }
}

void Inputs::mouseEventDown(gameScene *Model, double x,double y)
{
        prev_Mouse_X =x;
        prev_Mouse_Y =y;

   switch (wParam)
            {
                case MK_LBUTTON:
                    Mouse_Translate = true;
                    break;

                case MK_RBUTTON:
                    Mouse_Roatate = true;
                    break;
                case MK_MBUTTON:

                    break;

                default:
                    break;
            }
}

 void Inputs::mouseEventUp()
 {
    Mouse_Translate =false;
    Mouse_Roatate =false;
 }

void Inputs::mouseWheel(gameScene *Model,double Delta)
{
    Model->zoom += Delta/100;
}

void Inputs::mouseMove(gameScene *Model,double x,double y)
{
      if(Mouse_Translate)
      {
       Model->xPos += (x-prev_Mouse_X)/100;
       Model->yPos -= (y-prev_Mouse_Y)/100;

       prev_Mouse_X =x;
       prev_Mouse_Y =y;
      }

      /*if(Mouse_Roatate)
      {
        Model->RotateY += (x-prev_Mouse_X)/3;
        Model->RotateX += (y-prev_Mouse_Y)/3;

        prev_Mouse_X =x;
        prev_Mouse_Y =y;
      }*/
}

