#ifndef PLAYER_H
#define PLAYER_H
#include <string>

typedef struct
{
    float x;
    float y;
    float z;
}vec;

class player
{
    public:
        player();
        virtual ~player();

        void drawPlayer();
        void playerInit(char*);
        void playerAction(std::string);

        vec vertices[4];
        float xMin,yMin,xMax,yMax;

    protected:

    private:
};

#endif // PLAYER_H
