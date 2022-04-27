//
// Created by barak on 25/04/2022.
//

#include "Ambassador.hpp"
Ambassador::Ambassador (coup::Game &game,const std::string &name):coin(0) {
    this->game = &game;
    this->game->add(name);
}
std::string Ambassador::role() const {
    return "Ambassador";
}
void Ambassador::coup(const Player &target) {

}

void Ambassador::transfer(Player &from, Player &to) {

}

void Ambassador::Block(const Player &attacker) {

}
