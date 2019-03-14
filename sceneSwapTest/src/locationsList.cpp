#include "locationsList.h"

locationsList::locationsList(int max_items)
{
    //ctor
    max_locations = max_items;
    locationName.resize(max_locations);
    locTex.resize(max_locations);
    locSprVector.resize(max_locations);
    locTexCoord.resize(max_locations);

    for(int i=0; i<max_locations; i++)
    {
        locationName[i] = "";
        locTex[i] = new textureLoader();

        vec *locVert = new vec[4];
        locSprVector[i] = locVert;
        locSprVector[i][0].x = 0.0;
        locSprVector[i][0].y = 0.0;
        locSprVector[i][0].z = -5;

        locSprVector[i][1].x = 0.75;
        locSprVector[i][1].y = 0.0;
        locSprVector[i][1].z = -5;

        locSprVector[i][2].x = 0.75;
        locSprVector[i][2].y = 0.75;
        locSprVector[i][2].z = -5;

        locSprVector[i][3].x = 0.0;
        locSprVector[i][3].y = 0.75;
        locSprVector[i][3].z = -5;

        locTexCoord[i].xMin = 0;
        locTexCoord[i].xMax = 1;
        locTexCoord[i].yMin = 0;
        locTexCoord[i].yMax = 1;

    }
}

locationsList::~locationsList()
{
    //dtor
}

void locationsList::initLocation(char *fileName, std::string loc_name, int indx)
{
    locationName[indx] = loc_name;
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    locTex[indx]->bindTexture(fileName);
}

void locationsList::drawLocation(int indx)
{
    locTex[indx]->binder();
    glBegin(GL_QUADS);

    glTexCoord2f(locTexCoord[indx].xMin,locTexCoord[indx].yMax);
    glVertex3f(locSprVector[indx][0].x,locSprVector[indx][0].y,locSprVector[indx][0].z);

    glTexCoord2f(locTexCoord[indx].xMax,locTexCoord[indx].yMax);
    glVertex3f(locSprVector[indx][1].x,locSprVector[indx][1].y,locSprVector[indx][1].z);

    glTexCoord2f(locTexCoord[indx].xMax,locTexCoord[indx].yMin);
    glVertex3f(locSprVector[indx][2].x,locSprVector[indx][2].y,locSprVector[indx][2].z);

    glTexCoord2f(locTexCoord[indx].xMin,locTexCoord[indx].yMin);
    glVertex3f(locSprVector[indx][3].x,locSprVector[indx][3].y,locSprVector[indx][3].z);
    glEnd();
}
