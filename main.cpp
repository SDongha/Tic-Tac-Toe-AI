#include "play.hpp"
#include "human.hpp"
#include "ai.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char** argv)
{
    int n = std::atoi(argv[1]); // arg for board size: n x n
    int m = std::atoi(argv[2]); // arg for number of disc in a row to win
    bool h = std::atoi(argv[3]); // arg for who has first move, human: 1 AI: 0

    while(n>10 || n<3)
    {
	    std::cout<<"Set board size between 3 - 10"<<std::endl;
	    std::cin>>n;
    }

    while(m<2 || m>n){
	    std::cout<<"Number of connection 2 - "<<n<<std::endl;
	    std::cin>>m;
    }

    Play game = Play(n, m, h);
    game.makeBoard();

    Play* ptr = &game;

    Human humanPlayer(ptr);
    AI aiPlayer(ptr);

    game.showBoard();

    do
    {

	game.checkWinState();
        if(game.gameOver())
	{

		if(!game.getwinner())
	        std::cout << "The AI won!" << std::endl;
		else
			std::cout<<"The player won!"<<std::endl;
        game.showBoard();
//        humanPlayer.printMove();
        // aiPlayer.printMove();
        return 0;
        }
	if(game.isPlayerOneTurn())
	{

		if(!humanPlayer.playDisc())
		{
			continue; //keep playing until a valid move is chosen
		}
	        game.showBoard();
	}
	else if(!game.isPlayerOneTurn())
	{

		aiPlayer.playDisc();
		game.showBoard();
	}
//	game.showBoard();


        // if(!aiPlayer.playDisc())   FIXME: need to implements AI player
        // {
        // //if unsuccessful turn, repeat
        // continue;
        // }
        // if(game.gameOver())
        // {
        // std::cout << "Player 2 wins!" << std::endl;
        // game.showBoard();
        // humanPlayer.printMove();
        // // aiPlayer.printMove();
        // return 0;
        // }
        // game.showBoard();

    } while(!game.gameOver());

}
