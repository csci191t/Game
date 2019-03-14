#ifndef GAMESCENEHUD_H
#define GAMESCENEHUD_H


class gameSceneHud
{
    public:
        gameSceneHud();
        virtual ~gameSceneHud();

        void gsHudInit(char*);
        void gsHudDraw();

    protected:

    private:
};

#endif // GAMESCENEHUD_H
