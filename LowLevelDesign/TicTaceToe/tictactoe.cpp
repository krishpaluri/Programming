//============================================================================
// Name        : TicTaceToe.cpp
// Author      : Paluri Sai Krishna
// Description : TicTacToe Experiment
//               MakeMove in O(1) time
//               This is one of the entry level yet tricky question
//               asked for Low Level Design
//============================================================================

#include <iostream>
#include <vector>
#include <cstdlib>
#include <unordered_map>
using namespace std;



class TicTacToe
{
    private:
	   vector< vector<int> > rows;
	   int columns;
	   enum markers
	   {
		   nothing =0,
		   player1,
		   player2
	   };
	   enum GameStatus
	   {
		   Draw,
		   P1Won,
		   P2Won,
		   OnGoing,
		   NotYetStarted
	   };
	   int turn;
	   unordered_map<int,int> rowsum;
	   unordered_map<int,int> columnsum;
	   int diagonalsum;
	   int gameStatus;
	   int SpacesFilled;
    public:
	   enum MoveStates
	   {
		   NotYourTurn =0,
		   SpaceAlreadyFilled,
		   WrongCoordinates,
		   Success
	   };
	   TicTacToe(int columns)
       {
		   this->turn = nothing;
		   this->columns =  columns;
		   for(int i=0;i<=columns;i++)
		   {
			   vector<int> temp;
			   for(int j=0;j<=columns;j++)
			   {
				   temp.push_back(nothing);
			   }
			   this->rows.push_back(temp);
		   }
		   this->diagonalsum =0;
		   this->gameStatus = NotYetStarted;
		   this->SpacesFilled = 0;
       }
	   int getTurn()
	   {
		   return this->turn;
	   }
	   int getRows()
	   {
		   return this->columns;
	   }
	   int getColumns()
	   {
		   return this->getRows();
	   }
	   int getMatchStatus()
	   {
		   return this->gameStatus;
	   }
     int incrementSpacesFilled()
     {
       this->SpacesFilled += 1;
     }
	   int MakeMove(int player,int row, int column,int &didPlayerWin);
	   void startGame();
	   bool isGameOver()
	   {
		   return this->SpacesFilled == ((this->columns) * (this->columns));
	   }
	   bool didthisPlayerWon(int player)
	   {
		   if(player == player1)
		   {
			   if(getMatchStatus() == P1Won)
				   return true;
		   }
		   else if(player == player2)
		   {
			   if(getMatchStatus() == P2Won)
				   return true;
		   }
		   return false;
	   }
	   void swap(int &a1,int &a2)
	   {
		   int temp = a1;
		   a1 = a2;
		   a2 = temp;
	   }
};

void TicTacToe::startGame()
{
	int row =0,column =0;
	int player = player1;
	int didCurPlayerWin = 0;
	int status;
	this->gameStatus = OnGoing;
	this->turn = player1;
	//Entry Point of Game
	while(!isGameOver())
	{
		didCurPlayerWin =0;
		if(player == player1)
			cout<<" Player 1 Please";
		else
			cout<<" Player 2 Please";
		cout<<" enter Coordinates";
		cin>>row;
		cin>>column;
		status = MakeMove(player,row,column,didCurPlayerWin);
		if(status != Success)
		{
			if(status == NotYourTurn)
			{
				cout<<"Not Your Turn";
			}
			else if(status == SpaceAlreadyFilled)
			{
				cout<<"Space Already Filled choose Another space";
			}
			else if(status == WrongCoordinates)
			{
				cout<<"Wrong Coordinates Please enter again";
			}
			continue;
		}
		if(didCurPlayerWin == 1)
		{
			this->gameStatus = player == player1 ? P1Won : P2Won;
			break;
		}
		//swap turns now
		player = player == player1 ? player2 : player1;
		this->turn = player;
	}
	if(didCurPlayerWin != 1)
		this->gameStatus = Draw;

	if(this->gameStatus == Draw)
		cout<<"Both are Equals. Well Fought"<<endl;
	else if(this->gameStatus == P1Won)
	{
		cout<<"Player 1 Emerged as Victorious"<<endl;
	}
	else
		cout<<"Player 2 Emerged as Victorious"<<endl;

}

int TicTacToe::MakeMove(int player,int row,int column,int &didPlayerWin)
{
	if(this->turn != player)
	{
		// Not your turn
		// Wait for your Turn
		return NotYourTurn;
	}
	if(row <= 0 || column <=0 || row > this->columns || column > this->columns)
	{
		return WrongCoordinates;
	}
	int value = player == player1 ? 1 : -1;

	if(this->rows[row][column] == nothing)
		this->rows[row][column] = player;
	else // Already filled use another space
		return SpaceAlreadyFilled;
	this->rowsum[row] += value;
	if( abs(this->rowsum[row]) == this->columns )
		didPlayerWin = 1;
	this->columnsum[row] += value;
	if( abs(this->columnsum[row]) == this->columns )
		didPlayerWin = 1;
	if(row == column)
	{
		this->diagonalsum += value;
		if( abs(this->diagonalsum) == this->columns)
			didPlayerWin = 1;
	}
	this->incrementSpacesFilled();
	return Success; // Move Successful
}

int main()
{
	TicTacToe game(3);
	game.startGame();
	return 0;
}
