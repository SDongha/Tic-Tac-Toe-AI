#ifndef AI_HPP
#define AI_HPP

#include "play.hpp"
#include <vector>
#include <iostream>
#include <cmath>
#include <utility>
#include <bits/stdc++.h>
#include <algorithm>

class AI
{
  public:
    AI();
    AI(Play* game);

    int CountVerticalWins(int);
    int CountHorizontalWins(int);
    int CountDiagonalWins(int);
    bool makeMove();
    void printMoves();
    int minValue(Play* node, int depth, int alpha, int beta);
    int maxValue(Play* node, int depth, int alpha, int beta);
    int minMaxSearch(Play* gameBoard);
    int utility(Play* node);
  
    void playDisc();
    
  private:
    Play* game;
    int diskNum;
    int opponentDiskNum;
    int currentBranch = 0; //for searching
    int currentColumn = 0; //for searching
    int NumMinMaxCalls;
    int NumBoardsExplored;
    std::vector<int> movesTaken;

};

#endif
