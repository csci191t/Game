#ifndef COMMONUTILS_H
#define COMMONUTILS_H

#include <iostream>

typedef struct
{
    float x;
    float y;
    float z;
}vec;

typedef struct
{
    float xMin;
    float yMin;
    float xMax;
    float yMax;
}texCoord;

class commonUtils
{
    public:
        commonUtils();
        virtual ~commonUtils();

    protected:

    private:
};

#endif // COMMONUTILS_H
