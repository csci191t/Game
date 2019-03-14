#ifndef DECK_H
#define DECK_H

#include <iostream>
#include "string.h"
#include <vector>
#include "item.h"
#include "eventc.h"

class deck
{
    public:
        deck();
        virtual ~deck();

        std::string return_deck_type() {return deck_type;}
        virtual void add_to_deck(std::string) =0;

        //void shuffle_deck();                //Shuffles deck

    protected:
        std::string deck_name;
        std::string deck_type;
        std::vector<item*> this_item_deck;
        std::vector<eventc*> this_event_deck;

    private:

};

class item_deck : public deck
{
    public:
        item_deck(std::string,std::string);     //deck name, deck type
        ~item_deck() {};

        void add_to_deck(std::string);      //Input fileName, adds list to deck
        item *pull_from_item_deck();             //Pop first item from top of deck
        item *find_item(std::string);       //return intended item using item name

        void shuffle_deck();
        void print_deck();

    protected:
    private:

};

class event_deck : public deck
{
    public:
        event_deck(std::string,std::string);    //deck name, deck type
        ~event_deck() {};

        void add_to_deck(std::string);      //input file
        eventc *pull_from_event_deck();             //Pop first event from top of deck

        void print_deck();
        void shuffle_deck();
    protected:
    private:

};
#endif // DECK_H
