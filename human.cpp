#include "human.hpp"

Human::Human(){}

Human::Human(Play* game)
{
    std::cout << "A human player has entered the game.." << std::endl;
    this->game = game;
}

bool Human::playDisc()
{
    int col;
    std::cout << "Enter column #: " << std::endl;
    std::cin >> col;
    std::cout << std::endl;
    moves.push_back(col);
    bool sucessfulPlay = this->game->addDisk(col);
    return sucessfulPlay;
}

// void Human::printMove()
// {
//     std::cout << "Human player chose [";
//     for (size_t i = 0; i < this->moves.size(); i++)
//     {
//         if(i < this->moves.size()-1)
//         {
//             std::cout << this->moves[i] << ", ";
//         }
//         else
//         {
//             std::cout << this->moves[i];
//         }
//     }
//     std::cout << "]" << std::endl;
// }