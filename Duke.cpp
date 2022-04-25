//
// Created by barak on 25/04/2022.
//

#include "Duke.hpp"

Duke::Duke (coup::Game game, const std::string& name):coin(0) {
    game.add(name);
}

int Duke::coins() const {
    return this->coin;
}

void Duke::income() {

}
void Duke::foreign_aid() {

}
std::string Duke::role() const {
    return "Duke";
}
void Duke::coup(const Player &target){

}

/** Special Skills */
void Duke::block(const Player &attacker) {

}

void Duke::tax() {

}
