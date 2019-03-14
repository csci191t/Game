#ifndef LOCATION_H
#define LOCATION_H

#include "string.h"
#include "deck.h"



class location
{
    public:
        location();
        virtual ~location();

    protected:

    private:
        std::string location_name;
        int loc_x;
        int loc_y;
        deck *event_holder;

};

#endif // LOCATION_H
