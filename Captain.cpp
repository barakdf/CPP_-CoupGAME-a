//
// Created by barak on 25/04/2022.
//

#include "Captain.hpp"

Captain::Captain (coup::Game &game, const std::string &name):coin(0) {
    this->game = &game;
    this->game->add(name);
}

std::string Captain::role() const {
    return "Captain";
}
void Captain::coup(const Player &target) {

}

/** Special Skills */
void Captain::block(const Player &attacker) {

}

void Captain::steal(Player &victim) {

}