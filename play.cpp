#include "play.hpp"

Play::Play(){}

Play::Play(int n, int m, bool h)
{
    this->n = n;
    this->m = m;
    this->h = h;
    this->isGameOver = false;
	  playerOneTurn=true;   
}

Play::Play(const Play &play)
{
    this->n = play.n;
    this->m = play.m;
    this->h = play.h;
    this->isGameOver = play.isGameOver;
	  playerOneTurn = play.playerOneTurn;

    for(size_t i = 0; i < this->gameBoard.size(); i++)
    {
        this->gameBoard[i].resize(this->n);
    }

    for(int i = 0; i < this->n; i++)
    {
        for(int j = 0; j < this->n; j++)
        {
           this->gameBoard[i][j] = play.gameBoard[i][j];
	   std::cout<<"vals: "<<this->gameBoard[i][j];
        }
    }
    std::cout<<std::endl;
    
}

void Play::makeBoard()
{
    std::cout << "Creating board..." << std::endl;
    this->gameBoard.resize(this->n);
    for(size_t i = 0; i < this->gameBoard.size(); i++)
    {
        this->gameBoard[i].resize(this->n);
    }

    for(int i = 0; i < this->n; i++)
    {
        for(int j = 0; j < this->n; j++)
        {
            this->gameBoard[i][j] = 0;
        }
    }
}

void Play::showBoard()
{
    std::string state;
    state.append("\n");
    for(int i = 0; i < this->n; ++i)
    {
        for(int j = 0; j < this->n; ++j)
        {
            state.append("+---");
        }
            state.append("+");
            state.append("\n");

        for(int j = 0; j < this->n; ++j)
        {
            state.append("| ");

        if(this->gameBoard[i][j] == 1)
        {
            state.append("X");
        }
        else if(this->gameBoard[i][j] == 5)
        {
            state.append("O");
        }
        else
        {
            state.append(" ");
        }
        state.append(" ");
        }
        state.append("|");
        state.append("\n");
    }

    for(int j = 0; j < this->n; ++j)
    {
        state.append("+---");
    }
    state.append("+");
    state.append("\n");

    for(int j = 0; j < this->n; ++j)
    {
        state.append("| ");
        state.append(std::to_string(j + 1));
        state.append(" ");
    }

    state.append("|");
    state.append("\n");

    std::cout << state << std::endl;
}

/*/////////////////
void Play::showMoves()
{
    for(int i = 0; i < this->n; i++)
    {
        for(int j = 0; j < this->n; j++)
        {
            std::cout << this->gameBoard[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
*///////////////////////

bool Play::addDisk(int j)
{
  bool legalMove = false;
  j-=1; // make column selections indexed from 1
  if(j >= 0 && j < this->n) //is legal column
  {
    for(int i = this->n-1; i >= 0; --i)
    {
      if(this->gameBoard[i][j] == 0) // no disc exsists in spot
      {
		legalMove = true;
        if(playerOneTurn == true)
        {
          this->gameBoard[i][j] = 1; // player 1 move
          playerOneTurn = !playerOneTurn; // change turns
          this->disksPlayed++;
          this->i = i;
          break;
        }
        else
        {
          this->gameBoard[i][j] = 5; //player 2 move
          playerOneTurn = !playerOneTurn; //change turns
          this->disksPlayed++;
          this-> i = i;
          break;
        }
      }
    }

    if (!legalMove)
    {
      return false; //column is full
    }
  }
  else
  {
    return false; //col out of range
  }

  return true;
}
bool Play::isPlayerOneTurn()
{
	return playerOneTurn;
}

bool Play::gameOver()
{
  if(this->disksPlayed == (this->n * this->n))
  {
    // this->winningDisk = -1;
    return true;
  }

  return this->isGameOver;
}
int Play::getgameBoardValue(int i, int j)
{
	return this->gameBoard[i][j];
}

void Play::checkWinState()
{

	for(int j=0;j<this->n;j++)
	{
		for(int i=this->n-1;i>=0;i--)
		{
			if(this->gameBoard[i][j]!=0)
			{
				if(this->gameBoard[i][j]==1)
				{
		//Since each gameBoard will be 0, 1, or 2
		//total number of vertical, horizontal
		//will be used on deciding whether the 
		//board is continued or not
					if(verticalWin(i,j,0)==1*m)
					{
						this->isGameOver=true;
						winner=true;
						return;
					}

					if(horizontalWin(i,j,0)==1*m)
					{
						this->isGameOver=true;
						winner=true;
						return;
					}
					if(diagnolWin_left(i,j,0)==1*m)
					{
						this->isGameOver=true;
						winner=true;
						return;
					}
					if(diagnolWin_right(i,j,0)==1*m)
					{
						this->isGameOver=true;
						winner=true;
						return;
					}

				}
				else if(this->gameBoard[i][j]==5)
				{

					if(verticalWin(i,j,0)==5*m)
					{
						this->isGameOver=true;
						winner=false;
						return;
					}
					if(horizontalWin(i,j,0)==5*m)
					{
						this->isGameOver=true;
						winner=false;
						return;
					}
					if(diagnolWin_left(i,j,0)==5*m)
					{
						this->isGameOver=true;
						winner=false;
						return;
					}
					if(diagnolWin_right(i,j,0)==5*m)
					{
						this->isGameOver=true;
						winner=false;
						return;
					}
				}


			}
		}
	}

}
bool Play::getwinner()
{
	return this->winner;
}
int Play::horizontalWin(int a, int b, int c)
{
	int total=0;
	if(b>this->n-1)
		return 0;
	else if(c==m)
		return 0;
	else 
		total += this->gameBoard[a][b];
	c++;
	return total+ horizontalWin(a,b+1,c);
}

int Play::verticalWin(int a, int b, int c)
{
	int total=0;
	
	if(a<0)
		return 0;
	else if(c==m)
		return 0;
	else
		total += this->gameBoard[a][b];
	c++;

	return total+ verticalWin(a-1,b,c);
}

int Play::diagnolWin_left(int a, int b, int c)
{

	int total=0;
	if(a<0)
		return 0;
	if(b<0)
		return 0;
	if(c==m)
		return 0;
	else
		total+=this->gameBoard[a][b];
	c++;

	return total+ diagnolWin_left(a-1,b-1,c);

}

int Play::diagnolWin_right(int a, int b, int c)
{

	int total=0;
	if(a<0)
		return 0;
	if(b>this->n-1)
		return 0;
	if(c==m)
		return 0;
	else 
		total+=this->gameBoard[a][b];
	c++;
	return total+ diagnolWin_right(a-1,b+1,c);
}

int Play::getN()
{
  return this->n;
}

int Play::getM()
{
  return this->m;
}

int Play::getH()
{
  return this->h;
}

void Play::undoMove(int j)
{
  j--;
  for(int i = 0; i < this->n; i++)
  {
    if(this->gameBoard[i][j] == 1 || this->gameBoard[i][j] == 2)
    {
      this->isGameOver = false;
      this->disksPlayed--;
      this->winningDiskNum = 0;
      playerOneTurn = !playerOneTurn;
      this->gameBoard[i][j] = 0;
      return;
    }
  }
}

