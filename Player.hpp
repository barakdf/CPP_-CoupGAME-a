//
// Created by barak on 25/04/2022.
//

#ifndef CPP__COUPGAME_A_PLAYER_HPP
#define CPP__COUPGAME_A_PLAYER_HPP
#include <iostream>
#include "Game.hpp"
class Player {
public:
    virtual int coins() const = 0;
    virtual void income() = 0;
    virtual void foreign_aid() = 0;
    virtual std::string role() const = 0;
    virtual void coup(const Player &target) = 0;
};
#endif //CPP__COUPGAME_A_PLAYER_HPP
