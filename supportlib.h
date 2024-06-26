#include <iostream>
#include <vector>
using namespace std;

void printBoard(const vector<vector<char>> &board, string GameMode)
{
	int counter = 1;
	system("CLS");
	cout << "TIC TAC TOE - User vs " << GameMode << endl;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << board[i][j];
			if (j < 2)
			{
				cout << " | ";
			}
		}
		cout << "\t";
		for (int j = 0; j < 3; ++j)
		{
			cout << counter++;
			if (j < 2)
			{
				cout << " | ";
			}
		}
		cout << endl;
		if (i < 2)
		{
			cout << "---------\t---------" << endl;
		}
	}
}

int ValidateMove(const vector<vector<char>> &board, string charmove)
{
	if (charmove[0] >= '1' && charmove[0] <= '9' && charmove.length() == 1)
	{
		return charmove[0] - '0';
	}
	else
	{
		return -1;
	}
}

char ValidateTurn(string charmove)
{
	if ((charmove[0] == 'X' || charmove[0] == 'x') && charmove.length() == 1)
	{
		return 'X';
	}
	else if ((charmove[0] == 'O' || charmove[0] == 'o') && charmove.length() == 1)
	{
		return 'O';
	}
	else
	{
		return ' ';
	}
}

int convertChar(char c)
{
	if (c >= '1' && c <= '9')
	{
		return c - '0';
	}
	else if (c == '0')
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

bool checkWin(const vector<vector<char>> &board, char player)
{
	for (int i = 0; i < 3; ++i)
	{
		if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
		(board[0][i] == player && board[1][i] == player && board[2][i] == player))
		{
			return true;
		}
	}

	if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
	(board[0][2] == player && board[1][1] == player && board[2][0] == player))
	{
		return true;
	}

	return false;
}

bool isBoardFull(const vector<vector<char>> &board)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (board[i][j] == ' ')
			{
				return false;
			}
		}
	}
	return true;
}

void convertMove(int move, int &row, int &col)
{
	move--;
	row = move / 3;
	col = move % 3;
}

int evaluate(const vector<vector<char>> &board)
{
	if (checkWin(board, 'X'))
	{
		return -1;
	}
	else if (checkWin(board, 'O'))
	{
		return 1;
	}

	if (isBoardFull(board))
	{
		return 0;
	}

	return -2;
}

int minimax(vector<vector<char>> &board, int depth, bool isMaximizing)
{
	int score = evaluate(board);

	if (score != -2)
	{
		return score;
	}

	if (isMaximizing)
	{
		int maxEval = -1000;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (board[i][j] == ' ')
				{
					board[i][j] = 'O';
					int eval = minimax(board, depth + 1, false);
					board[i][j] = ' ';
					maxEval = max(maxEval, eval);
				}
			}
		}
		return maxEval;
	}
	else
	{
		int minEval = 1000;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (board[i][j] == ' ')
				{
					board[i][j] = 'X';
					int eval = minimax(board, depth + 1, true);
					board[i][j] = ' ';
					minEval = min(minEval, eval);
				}
			}
		}
		return minEval;
	}
}