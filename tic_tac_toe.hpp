#include <iostream>

#ifdef _WIN32
  	#define CLEAR "cls"
#else
   	#define CLEAR "clear"
#endif

int i = 0;

char Squares[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

//PLAYER VARIABLES X AND O
const char PlayerX = 'X';
const char PlayerO = 'O';
int userInput;
bool Marked = false; // THIS VARIABLE IS USED TO CHECK IF THE SQUARE IS ALREADY MARKED OR NOT.


//KEEP THE CURRENT PLAYER O
char CurrentPlayer = PlayerO;

class Tic_Tac_Toe
{
public:
	//VARIABLE FOR USER INPUT

	void ShowBoard();
	int CheckIfGameEnd();
	void DeclareWinner();
	int Opponent();
};

void Tic_Tac_Toe :: ShowBoard(){
	//CLEAR SCREEN
	system(CLEAR);
  
	//print the tic-tac-toe board.
	std::cout << "   |   |   " << std::endl;
	std::cout << " " << Squares[0] << " " << "|" << " " << Squares[1] << " " << "|" << " " << Squares[2] << std::endl;
	std::cout << "___|___|___" << std::endl;
	
	std::cout << "   |   |   " << std::endl;
	std::cout << " " << Squares[3] << " " << "|" << " " << Squares[4] << " " << "|" << " " << Squares[5] << std::endl;
	std::cout << "___|___|___" << std::endl;

	std::cout << "   |   |   " << std::endl;
	std::cout << " " << Squares[6] << " " << "|" << " " << Squares[7] << " " << "|" << " " << Squares[8] << std::endl;
	std::cout << "   |   |   " << std::endl;

    if (Marked == true) // IF THE SQUARE IS ALREADY MARKED, IT PRINTS THE MESSAGE.
    {
        std::cout << "Square already marked. Please try again." << std::endl;
        Marked = false; // RESET THE MARKED VARIABLE TO FALSE.
    }
}

int Tic_Tac_Toe :: CheckIfGameEnd(){
	for (int i = 0; i < 3; i++)
	{
		if (Squares[i] == Squares[i + 1] && Squares[i + 1] == Squares[i + 2]) // WHEN THE CHARACTERS IN FIRST ROW ARE EQUAL.
		{
			return 1; // RETURN 1 MEANS THE PREVIOUS PLAYER (EITHER X OR O) HAS WON.
		}
		else if (Squares[i] == Squares[i + 3] && Squares[i + 3] == Squares[i + 6]) // WHEN THE CHARACTERS IN FIRST COLUMN ARE EQUAL.
		{
			return 1;
		}
	}
	if (Squares[0] == Squares[4] && Squares[4] == Squares[8]) // WHEN THE CHARACTERS IN A DIAGONAL ARE EQUAL.
	{
		return 1;
	}
	else if (Squares[2] == Squares[4] && Squares[4] == Squares[6]) // WHEN THE CHARACTERS IN A DIAGONAL ARE EQUAL.
	{
		return 1;
	} 
	else if (Squares[0] != '1' && Squares[1] != '2' && Squares[2] != '3' &&
		 Squares[3] != '4' && Squares[4] != '5' && Squares[5] != '6' &&
		Squares[6] != '7' && Squares[7] != '8' && Squares[8] != '9') // WHEN THE CHARACTERS IN ALL ROWS STRAIGHT AND ALL COLUMNS STRAIGHT ARE NOT EQUAL 
																//AND THE INITIAL NUMBERS ASSIGNED ARE NOT THERE.
	{
		return 0; // SINCE NO SINGLE ROW OR COLUMN HAS THE SAME CHARACTER AND IS FILLED WITH Xs AND Os, IT RETURNS 0, WHICH MEANS DRAW.
	} 
	else 
	{
		return -1; // RETURNS -1 WHEN NONE OF THE ABOVE CASES ARE TRUE AND HENCE, THE GAME IS NOT DONE.
	}
}

void Tic_Tac_Toe :: DeclareWinner(){
	if (i == 1) // IF ANYONE HAS ONE
	{
		std::cout << std::endl << "\aPlayer " << CurrentPlayer << " Wins" << std::endl; // DECLARE THE PLAYER WHO HAS PREVIOUSLY ENTERED THE INPUT AS THE WINNER.
	}
	else // IF THE OUTPUT IS NOT 1, IT WOULD BE 0, WHICH MEANS DRAW.
	{
		std::cout << std::endl << "\aDraw" << std::endl;
	}
}

Tic_Tac_Toe tic_tac_toe;