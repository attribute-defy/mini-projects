// Roll Number: 0083-BSCS-25
// Last digit = 3
// Computed Board Size: N = 3 + (3 % 2) = 4

#include <iostream>
#include "TTT.h"

int main() {
    const int LD = 3;
    const int N = 3 + (LD % 2); // N = 4
    std::cout << "========================================" << std::endl;
    std::cout << " Roll Number: 0083-BSCS-25" << std::endl;
    std::cout << " Board Size: " << N << " x " << N << std::endl;
    std::cout << "========================================\n" << std::endl;

    TicTacToe game(N);
    game.playGame();

    return 0;
}