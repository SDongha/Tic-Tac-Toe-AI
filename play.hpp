#ifndef PLAY_HPP
#define PLAY_HPP

#include <iostream>
#include <string>
#include <vector>

class Play
{
    public:
        Play();
        Play(int, int, bool);
        Play(const Play &play); // copy constructor
        void makeBoard(); // creates the board
        void showBoard(); // prints the board
        void showMoves(); //prints values from the vector[int][int]
        bool gameOver();
        bool addDisk(int); // play a disk on the board
        bool getDisk(int);
        // Checking for win states
        int verticalWin(int,int,int);
        int horizontalWin(int,int,int);
        int diagnolWin_left(int,int,int);
	    int diagnolWin_right(int,int,int);
        void checkWinState(); //check for vertical, horizontal, or diagnol win conditions
        std::vector<std::vector<int> > getBoard();
        void undoMove(int col); //pop last move from board -- for minmax function
        /**
        get program argument values for AI and Human classes
        **/
        int getM();
        int getN();
        int getH();
	    bool isPlayerOneTurn();
	    bool getwinner();

	int getgameBoardValue(int, int);
	int getval(){
		return gameBoard[2][0];
	}

    private:
        int n; //board size: n x n
        int m; // number of stones needed in a row to win
        bool h; // 1: Human first move 0: AI first move FIXME: implement
        int i; //last disk played
        int disksPlayed; //number of disks played in the game for checking stalemate
        bool isGameOver;
        bool playerOneTurn;
        int winningDiskNum;
        std::vector<std::vector<int> > gameBoard;

	bool winner;
	//winner true= player one
	//winnter false= ai class

	bool isMaximizer;
};



#endif
