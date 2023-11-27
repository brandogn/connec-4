/**
 * Board is represented as a 2D array. The top left is the first col of the
 * first row, and the bottom right is the last col of the last row.
 */

#include "ConnectFour.h"
#include <iostream>

using namespace std;

ConnectFour::ConnectFour()
{
    init_board();
    currentPlayer = 'X';
}

void ConnectFour::play_game()
{
    display_board();

    while (true)
    {
        int col = get_player_move();
        int row = make_move(col);

        if (row != -1)
        {
            display_board();

            if (check_win(row, col))
            {
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}

void ConnectFour::init_board()
{
    for (int r = 0; r < ROWS; ++r)
    {
        for (int c = 0; c < COLS; ++c)
        {
            board[r][c] = ' ';
        }
    }
}

void ConnectFour::display_board()
{
    for (int r = 0; r < ROWS; ++r)
    {
        for (int j = 0; j < COLS - 1; ++j)
        {
            cout << " | " << board[r][j];
        }
        cout << " | " << board[r][COLS - 1] << " | " << endl;
    }

    for (int c = 1; c < COLS; ++c)
        cout << " | " << c;
    cout << " | " << COLS << " | " << endl;
}

int ConnectFour::get_player_move()
{
    int column;
    cout << "Player " << currentPlayer << ", enter your move (1-7): ";
    cin >> column;
    return column - 1;
}

/**
 * Returns the row in which the new token is placed,
 * if the column is full or out of bounds, returns -1.
 */
int ConnectFour::make_move(int col)
{
    if (col > COLS)
    {
        cout << "Out of bounds. Try again." << endl;
        return -1;
    }

    for (int r = ROWS - 1; r >= 0; --r)
    {
        if (board[r][col] == ' ')
        {
            board[r][col] = currentPlayer;
            return r;
        }
    }

    cout << "Column is full. Try again." << endl;
    return -1;
}

/**
 * Checks if inserting the new token at the given row, col will
 * result in a win of the current player.
 */
bool ConnectFour::check_win(int last_row, int last_col)
{

    int consec_tokens, c, r;

    consec_tokens = 0;
    for (r = last_row; r < ROWS; r++)
    {
        if (board[r][last_col] == currentPlayer)
            consec_tokens++;

        if (consec_tokens >= 4)
            return true;
    }

    for (int slope = -1; slope <= 1; slope++)
    {
        consec_tokens = 0;

        for (int offset = -3; offset <= 3; offset++)
        {
            c = last_col + offset;
            r = last_row + (offset * slope);

            if (c < 0 || c >= COLS || r < 0 || r >= ROWS)
                continue;

            if (board[r][c] == currentPlayer)
                consec_tokens++;
            else
                consec_tokens = 0;

            if (consec_tokens >= 4)
                return true;
        }
    }

    return false;
}
