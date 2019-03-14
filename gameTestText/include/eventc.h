#ifndef EVENTC_H
#define EVENTC_H

#include <iostream>
#include "string.h"
#include "hero.h"

class eventc
{
    public:
        eventc();
        virtual ~eventc();

        std::string return_event_name() {return event_name;}
        int return_event_id() {return event_id;}
        std::string return_event_type() {return event_type;}
        std::string return_event_file() {return event_file;}

        void print_event(eventc*);

        std::string event_name;     //Every event has a title
        std::string event_type;     //Location (Event) or Global (Event)
        int event_id;               //Event ID
        std::string event_file;     //Event description for ingame reading

    protected:
    private:
};

class location_event : public eventc
{
    public:
        location_event();
        ~location_event();

        void create_location_event(std::string,std::string,int,std::string,bool,std::string,int,std::string,std::string,std::string);

        std::string return_le_type() {return location_event_type;}
        bool return_stat_check() {return stat_check;}
        std::string return_stat_type() {return stat_type;}
        int return_stat_value() {return check_value;}

        std::string return_arg1() {return arg1;}
        std::string return_arg2() {return arg2;}
        std::string return_arg3() {return arg3;}

        void print_location_event();


    protected:                                  //Types of event:
        std::string location_event_type;        //Resource loss/gain or
                                                //Item loss/gain or
                                                //Status move/delay Hero
                                                //Monster attack
        //Some events have a stat check which takes the hero's specific stat
        //and rolls for a chance of an event to occur.
        bool stat_check;
        std::string stat_type;
        int check_value;

        std::string arg1;       //Represents each local event type's first argument:
                                //Resource: Health or Fortitude
                                //Item: Item Name or Random
                                //Status: Move or Delay
                                //Monster attack: Specific Monster Name or Random

        std::string arg2;       //Represents each local event's second argument:
                                //Resource: Loss or Gain
                                //Item:     Loss or Gain
                                //Status: If hero must move, this is the new Location or None
                                //Monster: None (There is no 3rd argument)

        std::string arg3;       //Represents each local event's final argument:
                                //Resource: Value
                                //Item:     Comes from either the SurplusStore or MagicShop
                                //Status:   None (There is no 3rd argument)
                                //Monster:  None (There is no 3rd argument)

    private:


};

class global_event : public eventc
{
    public:
        global_event();
        ~global_event();

    protected:


    private:
};
#endif // EVENTC_H
