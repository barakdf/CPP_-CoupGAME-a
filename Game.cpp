//
// Created by barak on 25/04/2022.
//

#include "Game.hpp"

using namespace coup;

void Game::add(const std::string &name) {
    this->members->push_back(name);
}

std::string Game::turn() const {
    return members->at(p_turn);
}
std::vector<std::string> Game::players() const{
    return *(this->members);
}
std::string Game::winner() const {
    if (this->m_size != 1) {
        throw;
    }
    return this->players().at(0);
}

Game::~Game() {
    delete members;
}