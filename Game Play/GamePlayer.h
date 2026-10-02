#ifndef GAMEPLAYER_H
#define GAMEPLAYER_H

#include <string>

class GamePlayer {
private:
    const int playerId;
    std::string name;
    int score;
    int level;
    static int totalPlayers;

public:

    GamePlayer();
    GamePlayer(std::string name, int score, int level = 1);
    GamePlayer(const GamePlayer& other);

    // Getters
    int getPlayerId() const;
    std::string getName() const;
    int getScore() const;
    int getLevel() const;

    // Overloaded operators
    GamePlayer operator+(const GamePlayer& other) const;
    bool operator>(const GamePlayer& other) const;
    bool operator<(const GamePlayer& other) const;
    bool operator==(const GamePlayer& other) const;

    // Friend function
    friend void transferScore(GamePlayer& from, GamePlayer& to, int points);

    // Static member function
    static int getTotalPlayers();

    // Utility method
    void display() const;
};

#endif