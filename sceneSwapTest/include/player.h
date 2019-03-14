#ifndef PLAYER_H
#define PLAYER_H

#include "commonUtils.h"

class player
{
    public:
        player();
        virtual ~player();

        void drawPlayer();
        void playerInit(char*);
        void playerAction();

        vec vertices[4];
        float xMin,yMin,xMax,yMax;

    protected:

    private:
};

#endif // PLAYER_H
