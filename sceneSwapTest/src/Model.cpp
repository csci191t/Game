#include "Model.h"
#include <textureLoader.h>

textureLoader *tex = new textureLoader();

Model::Model()
{
    //ctor
        RotateX =0.0; // Rotations
        RotateY =0.0;
        RotateZ =0.0;

        Zoom = -8.0;  //translations
        Xpos = 0.0;
        Ypos = 0.0;
}

Model::~Model()
{
    //dtor
}
void Model::modelInit(char *fileName)
{
    tex->binder();
    tex->bindTexture(fileName);
}


void Model::drawModel()
{
    glColor3f(0.8,0.5,0.0);
    tex->binder();
    glTranslated(Xpos,Ypos,Zoom);
    glRotated(RotateX,1,0,0);
    glRotated(RotateY,0,1,0);
    glRotated(RotateZ,0,0,1);
    glutSolidTeapot(1.5);
}
