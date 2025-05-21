// main.cpp file

#include <iostream>
using namespace std;

//NUMBERS ASSIGNED TO ONE SQUARE OF THE BOARD.
char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

//PLAYER VARIABLES X AND O
const char PlayerX = 'X';
const char PlayerO = 'O';

//KEEP THE CURRENT PLAYER O
char CurrentPlayer = PlayerO;

//VARIABLE FOR USER INPUT
int userInput;


int i = 0;

void Square(){
	//CLEAR SCREEN
	system("cls");

	//print the tic-tac-toe board.
	cout << "   |   |   " << endl;
	cout << " " << board[0] << " " << "|" << " " << board[1] << " " << "|" << " " << board[2] << endl;
	cout << "___|___|___" << endl;
	
	cout << "   |   |   " << endl;
	cout << " " << board[3] << " " << "|" << " " << board [4] << " " << "|" << " " << board [5] << endl;
	cout << "___|___|___" << endl;

	cout << "   |   |   " << endl;
	cout << " " << board[6] << " " << "|" << " " << board [7] << " " << "|" << " " << board [8] << endl;
	cout << "   |   |   " << endl;
	
}

int CheckWinner(){
	if (board[0] == board[1] && board[1] == board[2]) // WHEN THE CHARACTERS IN FIRST ROW ARE EQUAL.
	{
		return 1; // RETURN 1 MEANS THE PREVIOUS PLAYER (EITHER X OR O) HAS WON.
	}
	else if (board[3] == board[4] && board[4] == board[5]) // WHEN THE CHARACTERS IN SECOND ROW ARE EQUAL.
	{
		return 1;
	}
	else if (board[6] == board[7] && board[7] == board[8]) // WHEN THE CHARACTERS IN THIRD ROW ARE EQUAL.
	{
		return 1;	
	}
	else if (board[0] == board[3] && board[3] == board[6]) // WHEN THE CHARACTERS IN FIRST COLUMN ARE EQUAL.
	{
		return 1;
	}
	else if (board[1] == board[4] && board[4] == board[7]) // WHEN THE CHARACTERS IN SECOND COLUMS ARE EQUAL.
	{
		return 1;
	}
	else if (board[2] == board[5] && board[5] == board[8]) // WHEN THE CHARACTERS IN THIRD COLUMN ARE EQUAL.
	{
		return 1;
	}
	else if (board[0] == board[4] && board[4] == board[8]) // WHEN THE CHARACTERS IN A DIAGONAL ARE EQUAL.
	{
		return 1;
	}
	else if (board[2] == board[4] && board[4] == board[6]) // WHEN THE CHARACTERS IN A DIAGONAL ARE EQUAL.
	{
		return 1;
	} 
	else if (board[0] != '1' && board[1] != '2' && board[2] != '3' &&
		 board[3] != '4' && board[4] != '5' && board[5] != '6' &&
		board[6] != '7' && board[7] != '8' && board[8] != '9') // WHEN THE CHARACTERS IN ALL ROWS STRAIGHT AND ALL COLUMNS STRAIGHT ARE NOT EQUAL 
									//AND THE INITIAL NUMBERS ASSIGNED ARE NOT THERE.
	{
		return 0; // SINCE NO SINGLE ROW OR COLUMN HAS THE SAME CHARACTER AND IS FILLED WITH Xs AND Os, IT RETURNS 0, WHICH MEANS DRAW.
	} 
	else 
	{
		return -1; // RETURNS -1 WHEN NONE OF THE ABOVE CASES ARE TRUE AND HENCE, THE GAME IS NOT DONE.
	}
}

int main() {
	do
	{
		Square(); // PRINT THE BOARD
		
		CurrentPlayer = (CurrentPlayer == PlayerX) ? PlayerO : PlayerX; // IF CURRENT PLAYER IS 'PlayerO' IT CHANGES THE PLAYER TO 'X', ELSE 'PlayerO'.
		
		cout << "Current Player is " << CurrentPlayer << endl; // DECLARES THE CURRENT PLAYER.
		
		cout << endl <<"Enter which square you want to mark: ";
		cin >> userInput;
		board[userInput - 1] = CurrentPlayer; // THE CORRESPONDING SQUARE NUMBER IS CHANGED TO THE MARK OF THE CURRENT PLAYER.

		i = CheckWinner(); // THE RETURN VALUE OF THE CheckWinner() FUNCTION IS STORED IN VARIABLE 'i'.

	} while (i == -1); // THIS LOOP RUNS UNTIL i = -1, WHICH MEANS UNTIL THE GAME FINISHES

	Square(); // PRINTS THE BOARD
	
	if (i == 1) // IF ANYONE HAS ONE
	{
		cout << endl << "\aPlayer " << CurrentPlayer << " Wins" << endl; // DECLARE THE PLAYER WHO HAS PREVIOUSLY ENTERED THE INPUT AS THE WINNER.
	}
	else // IF THE OUTPUT IS NOT 1, IT WOULD BE 0, WHICH MEANS DRAW.
	{
		cout << endl << "\aDraw" << endl;
	}

	return 0;
}
