#ifndef CONNECTFOUR_H
#define CONNECTFOUR_H

class ConnectFour {
public:
    ConnectFour();
    void play_game();
    
private:
    const static int ROWS = 6;
    const static int COLS = 7;

    char board[ROWS][COLS];
    char currentPlayer;

    void init_board();
    void display_board();
    int get_player_move();
    int make_move(int col);
    bool check_win(int last_row, int last_col);
};

#endif // CONNECTFOUR_H
