#include <iostream>
#include <algorithm>
#include "GamePlayer.h"

int GamePlayer::totalPlayers = 0;

GamePlayer::GamePlayer(): playerId(++totalPlayers), name("Guest"), score(0), level(1) {}

GamePlayer::GamePlayer(std::string name, int score, int level): playerId(++totalPlayers) {
    this->name = name;

    if (score < 0) {
        std::cout << "Warning: Score cannot be negative (" << score << "). Defaulting to 0.\n";
        this->score = 0;
    } else {
        this->score = score;
    }

    if (level < 1) {
        std::cout << "Warning: Level is below minimum (1). Clamping to 1.\n";
        this->level = 1;
    } else if (level > 100) {
        std::cout << "Warning: Level exceeds maximum (100). Clamping to 100.\n";
        this->level = 100;
    } else {
        this->level = level;
    }
}

GamePlayer::GamePlayer(const GamePlayer& other) 
    : playerId(++totalPlayers), name(other.name), score(other.score), level(other.level) {}

int GamePlayer::getPlayerId() const {
    return playerId;
}

std::string GamePlayer::getName() const {
    return name;
}

int GamePlayer::getScore() const {
    return score;
}

int GamePlayer::getLevel() const {
    return level;
}

GamePlayer GamePlayer::operator+(const GamePlayer& other) const {
    std::string combinedName = this->name + " & " + other.name;
    int combinedScore = this->score + other.score;
    int highestLevel = std::max(this->level, other.level);

    return GamePlayer(combinedName, combinedScore, highestLevel);
}

bool GamePlayer::operator>(const GamePlayer& other) const {
    return this->score > other.score;
}

bool GamePlayer::operator<(const GamePlayer& other) const {
    return this->score < other.score;
}

bool GamePlayer::operator==(const GamePlayer& other) const {
    return this->score == other.score;
}

void transferScore(GamePlayer& from, GamePlayer& to, int points) {
    if (points <= 0) {
        std::cout << "Transfer Failed: Points to transfer must be greater than 0.\n";
        return;
    }

    if (from.score < points) {
        std::cout << "Transfer Failed: " << from.name << " has insufficient score (" 
                  << from.score << " available, " << points << " requested).\n";
        return;
    }

    from.score -= points;
    to.score += points;
    std::cout << "Transfer Successful: Transferred " << points << " points from " 
              << from.name << " to " << to.name << ".\n";
}

int GamePlayer::getTotalPlayers() {
    return totalPlayers;
}

void GamePlayer::display() const {
    std::cout << "ID: " << playerId 
              << " | Name: " << name 
              << " | Score: " << score 
              << " | Level: " << level << "\n";
}