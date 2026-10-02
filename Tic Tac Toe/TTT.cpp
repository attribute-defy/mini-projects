#include <iostream>
#include "TTT.h"
TicTacToe::TicTacToe(int n) {
    size = n;
    currentPlayer = 'X';

    // Allocate dynamic 2D raw array
    board = new char*[size];
    for (int i = 0; i < size; ++i) {
        board[i] = new char[size];
        for (int j = 0; j < size; ++j) {
            board[i][j] = ' '; // Initialize with empty space
        }
    }
}

// Destructor: Clean up dynamically allocated memory
TicTacToe::~TicTacToe() {
    for (int i = 0; i < size; ++i) {
        delete[] board[i];
    }
    delete[] board;
}

// Getter for current player
char TicTacToe::getCurrentPlayer() const {
    return currentPlayer;
}

// (a) displayBoard
void TicTacToe::displayBoard() const {
    std::cout << "         TIC-TAC-TOE (" << size << "x" << size << ")\n";
    std::cout << "=====================================\n\n";

    // Column numbers
    std::cout << "    ";
    for (int j = 0; j < size; ++j) {
        std::cout << " " << j + 1 << "  ";
    }
    std::cout << "\n";

    for (int i = 0; i < size; ++i) {
        std::cout << " " << i + 1 << "  ";
        
        for (int j = 0; j < size; ++j) {
            std::cout << " " << board[i][j] << " ";
            if (j < size - 1) std::cout << "|";
        }
        std::cout << "\n";

        // Row Separator
        if (i < size - 1) {
            std::cout << "    ";
            for (int j = 0; j < size; ++j) {
                std::cout << "---";
                if (j < size - 1) std::cout << "+";
            }
            std::cout << "\n";
        }
    }
    std::cout << "\n";
}

// (b) makeMove
bool TicTacToe::makeMove(int row, int col) {
    int r = row - 1;
    int c = col - 1;

    if (r >= 0 && r < size && c >= 0 && c < size) {
        if (board[r][c] == ' ') {
            board[r][c] = currentPlayer;
            return true;
        }
    }
    return false;
}

bool TicTacToe::checkRows() const {
    for (int i = 0; i < size; ++i) {
        bool win = true;
        for (int j = 0; j < size; ++j) {
            if (board[i][j] != currentPlayer) {
                win = false;
                break;
            }
        }
        if (win) return true;
    }
    return false;
}

// Helper
bool TicTacToe::checkColumns() const {
    for (int j = 0; j < size; ++j) {
        bool win = true;
        for (int i = 0; i < size; ++i) {
            if (board[i][j] != currentPlayer) {
                win = false;
                break;
            }
        }
        if (win) return true;
    }
    return false;
}

// Helper
bool TicTacToe::checkDiagonals() const {
    // Main diagonal
    bool mainDiag = true;
    for (int i = 0; i < size; ++i) {
        if (board[i][i] != currentPlayer) {
            mainDiag = false;
            break;
        }
    }
    if (mainDiag) return true;

    // Anti diagonal
    bool antiDiag = true;
    for (int i = 0; i < size; ++i) {
        if (board[i][size - 1 - i] != currentPlayer) {
            antiDiag = false;
            break;
        }
    }
    return antiDiag;
}

// (c) checkWin
bool TicTacToe::checkWin() const {
    return checkRows() || checkColumns() || checkDiagonals();
}

// (d) checkDraw
bool TicTacToe::checkDraw() const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// (e) switchPlayer
void TicTacToe::switchPlayer() {
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    } else {
        currentPlayer = 'X';
    }
}

// (f) playGame
void TicTacToe::playGame() {
    bool gameEnded = false;

    while (!gameEnded) {
        displayBoard();

        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";

        if (!(std::cin >> row >> col)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input format! Please enter two numbers.\n";
            continue;
        }

        if (makeMove(row, col)) {
            if (checkWin()) {
                displayBoard();
                std::cout << "*************************************\n";
                std::cout << "PLAYER " << currentPlayer << " WINS!\n";
                std::cout << "*************************************\n";
                gameEnded = true;
            } else if (checkDraw()) {
                displayBoard();
                std::cout << "*************************************\n";
                std::cout << "                  DRAW!              \n";
                std::cout << "*************************************\n";
                gameEnded = true;
            } else {
                switchPlayer();
            }
        } else {
            std::cout << "\n>>> Invalid move (1-" << size << "). Try again. <<<\n";
        }
    }
}