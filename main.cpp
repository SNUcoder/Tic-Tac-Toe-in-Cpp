// main.cpp: This file contains the 'main' function. Program execution begins and ends there.
//
#include "tic_tac_toe.hpp"

// FUNCTION TO CHECK IF THE SQUARE IS ALREADY MARKED OR NOT.
bool CheckMark(int Input)
{
	if (Squares[Input - 1] == PlayerX || Squares[Input - 1] == PlayerO)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void game()
{
	tic_tac_toe.ShowBoard(); // PRINT THE BOARD

	CurrentPlayer = (CurrentPlayer == PlayerO) ? PlayerX : PlayerO; // IF CURRENT PLAYER IS 'PlayerO' IT CHANGES THE PLAYER TO 'X', ELSE 'PlayerO'.

	std::cout << "Current Player is " << CurrentPlayer << std::endl; // DECLARES THE CURRENT PLAYER.

	std::cout << std::endl
			  << "Enter which square you want to mark: ";
	std::cin >> userInput;

	Marked = CheckMark(userInput);
	// CHECKS IF THE SQUARE IS ALREADY MARKED OR NOT.
	if (Marked == true)
	{
		CurrentPlayer = (CurrentPlayer == PlayerX) ? PlayerO : PlayerX; // IF THE SQUARE IS ALREADY MARKED, THE CURRENT PLAYER IS CHANGED TO 'PlayerO' AND THE GAME RESTARTS.
		game();
		return (void)0;
	}
	else
	{
		Squares[userInput - 1] = CurrentPlayer; // THE CORRESPONDING SQUARE NUMBER IS CHANGED TO THE MARKER OF THE CURRENT PLAYER.

		i = tic_tac_toe.CheckIfGameEnd();

		if (i == -1) // THIS LOOP RUNS UNTIL i = -1, WHICH MEANS UNTIL THE GAME FINISHES
		{
			game(); // THE RETURN VALUE OF THE CheckIfGameEnd() FUNCTION IS STORED IN VARIABLE 'i'.
		}
		else
		{
			tic_tac_toe.ShowBoard(); // PRINTS THE BOARD
			tic_tac_toe.DeclareWinner();

			return (void)0;
		}
	}
	return (void)0;
}

int main()
{

	game();

	return 0;
}
