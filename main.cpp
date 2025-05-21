// Tic-Tac-Toe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};


const char PlayerX = 'X';
const char PlayerO = 'O';
char CurrentPlayer = PlayerO;
int userInput;
int i = 0;

void Square(){
	system("cls");

	//print the tic tac toe board
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
	if (board[0] == board[1] && board[1] == board[2])
	{
		return 1;
	}
	else if (board[3] == board[4] && board[4] == board[5])
	{
		return 1;
	}
	else if (board[6] == board[7] && board[7] == board[8])
	{
		return 1;
	}else if (board[0] == board[3] && board[3] == board[6])
	{
		return 1;
	}else if (board[1] == board[4] && board[4] == board[7])
	{
		return 1;
	}else if (board[2] == board[5] && board[5] == board[8])
	{
		return 1;
	}else if (board[0] == board[4] && board[4] == board[8])
	{
		return 1;
	}else if (board[2] == board[4] && board[4] == board[6])
	{
		return 1;
	} else if (board[0] != '1' && board[1] != '2' && board[2] != '3' &&
		 board[3] != '4' && board[4] != '5' && board[5] != '6' &&
		board[6] != '7' && board[7] != '8' && board[8] != '9')
	{
		return 0;
	} else {
		return -1;
	}
}

int main() {
	do
	{
		Square();
		
		CurrentPlayer = (CurrentPlayer == PlayerX) ? PlayerO : PlayerX;
		
		cout << "Current Player is " << CurrentPlayer << endl;
		cin >> userInput;
		board[userInput - 1] = CurrentPlayer;

		i = CheckWinner();

	} while (i == -1);

	Square();
	if ( 1 == i)
	{
		cout << endl << "\aPlayer " << CurrentPlayer << " Wins" << endl;
	}
	else// if (i = 0)
	{
		cout << endl << "\aDraw" << endl;
	}
	
	// return 0;
}