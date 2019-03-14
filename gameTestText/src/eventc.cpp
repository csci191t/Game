#include "eventc.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>

eventc::eventc()
{
    //ctor
    event_name = "";
    event_type = "";
    event_id = 0;
}

eventc::~eventc()
{
    //dtor
}

void eventc::print_event(eventc *this_event)
{
    if(dynamic_cast<location_event*>(this_event) != nullptr)
    {
        location_event *leCast = dynamic_cast<location_event*>(this_event);
        leCast->print_location_event();
    }
}

location_event::location_event()
{
    location_event_type = "";
    stat_check = false;
    stat_type = "";
    check_value = 0;
    arg1,arg2,arg3 = "None";
}

location_event::~location_event()
{

}

void location_event::create_location_event(std::string a1, std::string a2, int a3, std::string b1, bool b2, std::string b3, int b4, std::string b5, std::string b6, std::string b7)
{
    event_name = a1;
    event_type = a2;
    event_id = a3;

    location_event_type = b1;
    stat_check = b2;
    stat_type = b3;
    check_value = b4;
    arg1 = b5;
    arg2 = b6;
    arg3 = b7;
}

void location_event::print_location_event()
{
        std::cout<<"Name: "<< event_name<<std::endl;
        std::cout<<"Type: "<< event_type<<std::endl;
        std::cout<<"ID: "<< event_id<<std::endl;
        std::cout<<event_type<<" Event Type: "<< location_event_type<<std::endl;
        std::cout<<"stat check: "<< stat_check<<std::endl;
        std::cout<<"stat type: "<< stat_type<<std::endl;
        std::cout<<"check value: "<<check_value<<std::endl;
        std::cout<<"ARG1: "<< arg1<<std::endl;
        std::cout<<"ARG2: "<< arg2<<std::endl;
        std::cout<<"ARG3: "<< arg3<<std::endl;
}

