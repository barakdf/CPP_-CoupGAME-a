//
// Created by barak on 25/04/2022.
//

#include "Ambassador.hpp"
Ambassador::Ambassador (coup::Game game,const std::string &name):coin(0) {
    game.add(name);
}
int Ambassador::coins() const {
    return this->coin;
}
void Ambassador::income(){

}
void Ambassador::foreign_aid(){

}
std::string Ambassador::role() const {
    return "Ambassador";
}
void Ambassador::coup(const Player &target) {

}

void Ambassador::transfer(Player &from, Player &to) {

}
