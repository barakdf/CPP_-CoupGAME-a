//
// Created by barak on 25/04/2022.
//

#include "Contessa.hpp"

Contessa::Contessa (coup::Game game,const std::string &name):coin(0) {
    game.add(name);
}

int Contessa::coins() const {
    return this->coin;
}
void Contessa::income() {

}
void Contessa::foreign_aid() {

}
std::string Contessa::role() const {
    return "Contessa";
}
void Contessa::coup(const Player &target) {

}

/** Special Skills */
void Contessa::block(const Player &attacker) {

}