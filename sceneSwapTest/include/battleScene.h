#ifndef BATTLESCENE_H
#define BATTLESCENE_H


class battleScene
{
    public:
        battleScene();
        virtual ~battleScene();

        void battleSceneInit(char*);
        void drawBattleScene();

        double xPos;
        double yPos;
        double zoom;

    protected:

    private:
};

#endif // BATTLESCENE_H
