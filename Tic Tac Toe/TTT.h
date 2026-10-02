#ifndef TTT_H
#define TTT_H

class TicTacToe {
private:
    char** board;
    int size;
    char currentPlayer;

    bool checkRows() const;
    bool checkColumns() const;
    bool checkDiagonals() const;

public:
    TicTacToe(int n);
    ~TicTacToe();
    
    void displayBoard() const;
    bool makeMove(int row, int col);
    bool checkWin() const;
    bool checkDraw() const;
    void switchPlayer();
    void playGame();
    char getCurrentPlayer() const;
};

#endif