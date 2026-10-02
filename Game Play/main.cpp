#include <iostream>
#include "GamePlayer.h"

int main() {
    std::cout << "Creating Players: \n";
    GamePlayer p1;                          
    GamePlayer p2("Ali", 1250, 15);        
    GamePlayer p3(p2);                     

    p1.display();
    p2.display();
    p3.display();

    std::cout << "\nPlayer ID Verification: \n";
    std::cout << "p2 (Original) ID: " << p2.getPlayerId() << "\n";
    std::cout << "p3 (Copy) ID:     " << p3.getPlayerId() << std::endl;

    std::cout << "\nTeam-Up Combination: \n";
    GamePlayer teamPlayer = p1 + p2;
    teamPlayer.display();

    std::cout << "\nScore Comparison: \n";
    if (p2 > p1) {
        std::cout << p2.getName() << " (" << p2.getScore() << " pts) has a higher score than " 
                  << p1.getName() << " (" << p1.getScore() << " pts).\n";
    } else {
        std::cout << p1.getName() << " does not have a higher score than " << p2.getName() << ".\n";
    }

    // 4. Use transferScore to move points and verify mutated state
    std::cout << "\n Score Transfer: \n";
    std::cout << "Before Transfer:\n";
    p1.display();
    p2.display();

    transferScore(p2, p1, 300);

    std::cout << "After Transfer:\n";
    p1.display();
    p2.display();

    // 5. Print getTotalPlayers() count at the end
    std::cout << "\nSystem Metrics: \n";
    std::cout << "Total GamePlayers Created: " << GamePlayer::getTotalPlayers() << "\n";

    return 0;
}