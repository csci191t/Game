#ifndef GAMESCENE_H
#define GAMESCENE_H


class gameScene
{
    public:
        gameScene();
        virtual ~gameScene();

        void gameSceneInit(char*);
        void drawGameScene();

        double xPos;
        double yPos;
        double zoom;

    protected:

    private:
};

#endif // GAMESCENE_H
