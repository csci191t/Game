#ifndef LOCATIONSLIST_H
#define LOCATIONSLIST_H

#include <iostream>
#include "textureLoader.h"
#include "commonUtils.h"
#include <vector>
#include <string>

class locationsList
{
    public:
        locationsList(int);
        virtual ~locationsList();

        void initLocation(char*,std::string,int);
        void drawLocation(int);

        std::vector<std::string> locationName;
        std::vector<textureLoader*> locTex;
        std::vector<vec*> locSprVector;
        std::vector<texCoord> locTexCoord;

    protected:

    private:
        int max_locations;
};

#endif // LOCATIONSLIST_H
