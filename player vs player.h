#include <iostream>
#include <string>

using namespace std;

void printBoard(char board[3][3], string currentPlayer)
{
	cout << "Current Board: " << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << "-----------------" << endl;
}

int ValidateMove(char board[3][3], string charmove)
{
	// Implementation of ValidateMove function
}

void convertMove(int move, int &row, int &col)
{
	// Implementation of convertMove function
}

bool checkWin(char board[3][3], char currentPlayer)
{
	// Implementation of checkWin function
}

bool isBoardFull(char board[3][3])
{
	// Implementation of isBoardFull function
}

int main()
{
	char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
	string currentPlayer = "User";
	int flag = 0;

	while (true)
	{
		printBoard(board, currentPlayer);

		cout << "Player " << currentPlayer << ",\nEnter your move (1-9): ";
		string charmove;
		getline(cin, charmove);

		int move = ValidateMove(board, charmove);

		if (move == -1 && flag == 1)
		{
			cout << "Invalid Move. Please Enter a Valid Move" << endl;
			continue;
		}
		else if (flag == 1)
		{
			int row, col;
			convertMove(move, row, col);
			board[row][col] = currentPlayer[0];
		}

		if (checkWin(board, currentPlayer[0]))
		{
			printBoard(board, currentPlayer);
			cout << "Player " << currentPlayer << " wins!" << endl;
			break;
		}

		if (isBoardFull(board))
		{
			printBoard(board, currentPlayer);
			cout << "It's a tie!" << endl;
			break;
		}

		if (flag == 1)
		{
			currentPlayer = (currentPlayer == "X") ? "O" : "X";
		}
		flag = 1;
	}
	return 0;
}