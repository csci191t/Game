#include "timer.h"

timer::timer()
{
    //ctor
    startAt=0;
}

timer::~timer()
{
    //dtor
}

void timer::start()
{
    startAt =clock();
}

void timer::stop()
{

}

void timer::reset()
{
    startAt =clock();
}

clock_t timer::getTicks()
{
    return clock()-startAt;
}
