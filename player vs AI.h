#include <iostream>
#include <vector>
#include <unistd.h>
#include <conio.h>

using namespace std;

void makeAIMove(vector<vector<char>> &board)
{
    int bestMove = -1;
    int bestScore = -1000;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = 'O';
                int moveScore = minimax(board, 0, false);
                board[i][j] = ' ';

                if (moveScore > bestScore)
                {
                    bestScore = moveScore;
                    bestMove = i * 3 + j + 1;
                }
            }
        }
    }

    int row, col;
    convertMove(bestMove, row, col);
    board[row][col] = 'O';
}

void tictactoeai()
{
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    string charmove;
    int move, flag = 0;

    while (true)
    {
        printBoard(board, "AI");

        if (currentPlayer == 'X')
        {
            cout << "Player " << currentPlayer << ",\nEnter your move (1-9): ";
            getline(cin, charmove);

            move = ValidateMove(board, charmove);

            if (move == -1 && flag == 1)
            {
                cout << "Invalid Move. Please Enter Valid Move" << endl;
                getch();
                continue;
            }
            else if (flag == 1)
            {
                int row, col;
                convertMove(move, row, col);
                board[row][col] = currentPlayer;
            }
        }
        else
        {
            cout << "Thinking";
            for (int j = 0; j < 3; ++j)
            {
                cout << ".";
                usleep(500000);
            }
            cout << endl;
            makeAIMove(board);
        }

        if (checkWin(board, currentPlayer))
        {
            printBoard(board, "AI");
            if (currentPlayer == 'O')
            {
                cout << "AI Wins!" << endl;
                cout << "Press any Key to Continue...";
                getch();
                system("cls");
            }
            else
            {
                cout << "Player " << currentPlayer << " Wins!" << endl;
                cout << "Press any Key to Continue...";
                getch();
                system("cls");
            }
            break;
        }

        if (isBoardFull(board))
        {
            printBoard(board, "AI");
            cout << "It's a tie!" << endl;
            cout << "Press any Key to Continue...";
            getch();
            system("cls");
            break;
        }

        if (flag == 1)
        {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
        flag = 1;
    }
}

// int main()
// {
//     cout << "Welcome to Tic Tac Toe!" << endl;
//     while (1)
//     {
//         tictactoeai();
//         getch();
//     }
//     return 0;
// }
