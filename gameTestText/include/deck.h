#ifndef DECK_H
#define DECK_H

#include <iostream>
#include "string.h"
#include <vector>
#include "item.h"

class deck
{
    public:
        deck();
        virtual ~deck();

        std::string return_deck_name() {return deck_name;}

        void shuffle_deck();                //Shuffles deck
        void print_deck();

    protected:
        std::string deck_name;
        std::vector<item> this_item_deck;

    private:

};

class item_deck : public deck
{
    public:
        item_deck(std::string);
        ~item_deck() {};

        void add_to_deck(std::string);      //Input fileName, adds list to deck
        item pull_from_deck();             //Pop first item from top of deck
        item find_item(std::string);       //return intended item using item name

    protected:
    private:

};

class event_deck : public deck
{
    public:
    protected:
    private:

};
#endif // DECK_H
