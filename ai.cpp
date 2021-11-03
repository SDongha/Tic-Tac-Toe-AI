#include "ai.hpp"

AI::AI(){}

AI::AI(Play* game)
{
    std::cout << "An AI Player has entered the game..." << std::endl;
    this->game = game;
    //this->game = new 
}

// bool AI::makeMove() //FIXME: not done, need to implement minMaxSearch function
// {
//     this->NumBoardsExplored = 0;

//     int chosenCol = minMaxSearch(this->game->getBoard());

// }

//psuedocode in notes
int AI::minValue(Play* node, int depth, int alpha, int beta)
{
    std::cout << "in minValue()" << std::endl;
    if(game->gameOver() == true || depth == 0)
    {
        std::cout << "reached terminal case from minValue()" << std::endl;
       return utility(node);
    }

    for(int i = 0; i < this->game->getN(); i++) //for each possible column choice
    {
        std::cout << "making move from minValue: " << i <<std::endl;
        node->addDisk(i); // make move
        std::cout << "calling maxValue() from minValue()" << std::endl;
        beta = std::min(beta, maxValue(node, depth-1, alpha, beta));
        if(alpha >= beta)
        {
            return -1000000;
        }
    }
    return beta;
}

//psuedocode in notes
int AI::maxValue(Play* node, int depth, int alpha, int beta)
{
    std::cout << "in maxValue()" << std::endl;
    if(this->game->gameOver() == true || depth == 0) //win state or base case
    {
        std::cout << "reached terminal case from maxValue()" << std::endl;
        return utility(node);
    }

    for(int i = 0; i < this->game->getN(); i++) //for each possible column choice
    {
        node->addDisk(i); // make move (bool move =)
        alpha = std::max(alpha, minValue(node, depth-1, alpha, beta));
        if(alpha >= beta)
        {
            return 1000000;
        }
    }
    return alpha;
}

//psuedocode in notes
int AI::minMaxSearch(Play* gameBoard)
{

    std::cout << "in minMaxSearch" << std::endl;
    Play* node = new Play();
    std::cout << "calling memcpy()" << std::endl;
    memcpy(&node, &this->game, sizeof(node));
    //Play node(gameBoard); //gameboard with intial state -- used to check future game states
    //std::cout << "copied board using copy constructor" << std::endl;
    int alpha = -1000000;
    int beta = 1000000;
    int action;
    int depth = 1;

    for(int i = 0; i < this->game->getN(); i++) //for each possible column choice
    {
        node->addDisk(i); // make move
        std::cout << "move: " << i << std::endl;
        depth--;
        std::cout << "calling minValue() from MinMax" << std::endl;
        int alphaPrime = minValue(node, node->getN(), alpha, beta);
        std::cout << "returned from minValue() call" << std::endl;
        if (alphaPrime > alpha)
        {
            alpha = alphaPrime;
            action = i;
        }
	
    }  
    std::cout << "returning action" << std::endl;
    return action;
}

int AI::utility(Play* node)
{
    std::cout << "in Utility Function" << std::endl;
	int empty_score, win_score;
    int slot_score_1=5;//player 1
	int slot_score_2=-5;// ai

	int result=0;

	if(node->getwinner())
	{
        std::cout << "node->getWinner() == TRUE" << std::endl;
		win_score=50;
		empty_score=10;
	
		//winner=true=>player1
		//false-> ai
	}
	else
	{
        std::cout << "node->getWinner() == FALSE" << std::endl;
		win_score=-50;
		empty_score=-10;
	}

	std::cout<<"getN: "<<node->getN()<<std::endl;
	std::cout<<"game:"<<node->getval()<<std::endl;
	for(int i=0; i<node->getN();i++)
	{
		for(int j=0; j<node->getN(); j++)
		{
            std::cout << "in second for loop" << std::endl;
	    std::cout<<"game: "<<node->getval()<<std::endl;
	    
			if(node->getgameBoardValue(i,j)==1)
			{
				std::cout<<"value"<<std::endl;
				result=result+slot_score_1;
			}
			else if(node->getgameBoardValue(i,j)==5)
			{
				std::cout<<"vale2"<<std::endl;
				result=result+slot_score_2;
			}
			else
			{
				std::cout<<"vale3"<<std::endl;
				result=result+empty_score;
			}
		}
	}

	result=result+win_score;
    std::cout << "returning result" << std::endl;
	return result;

	//This will count all the scores
	//each slots +5/-5
	//win case +50/-50
	//empty slots bonus(+10/-10 on each)
	


}

void AI::playDisc()
{
    std::cout << "calling minMaxSearch()" << std::endl;
    int move = minMaxSearch(this->game); //seg fault here
    std::cout << "making AI's move" << std::endl;
	this->game->addDisk(move);
}

