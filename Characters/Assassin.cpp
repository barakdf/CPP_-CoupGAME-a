//
// Created by barak on 25/04/2022.
//

#include "Assassin.hpp"

Assassin::Assassin (coup::Game &game,const std::string &name):coin(0) {
    this->game = &game;
    this->game->add(name);
}
int Assassin::coins() const {
    return this->coin;
}
void Assassin::income() {

}
void Assassin::foreign_aid() {

}
std::string Assassin::role() const {
    return "Assassin";
}
void Assassin::coup(const Player &target) {

}

/** Special Skills */

