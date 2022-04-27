//
// Created by barak on 25/04/2022.
//

#include "Player.hpp"

int Player::coins() const {
    return coin;
}

void Player::income() {
    this->coin++;
}

void Player::foreign_aid() {
    this->coin += 2;
}

std::string Player::role() const {
    return nullptr;
}

void Player::coup(const Player &target) {}