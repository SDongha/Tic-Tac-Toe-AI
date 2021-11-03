#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "play.hpp"
#include <iostream>
#include <vector>

class Human
{
    public:
        Human();
        Human(Play* game);
        bool playDisc();
        void printMove();

        private:
            Play* game;
            std::vector<int> moves;

};

#endif