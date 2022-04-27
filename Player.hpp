//
// Created by barak on 25/04/2022.
//

#ifndef CPP__COUPGAME_A_PLAYER_HPP
#define CPP__COUPGAME_A_PLAYER_HPP
#include <iostream>
#include "Game.hpp"
class Player {
protected:
    int coin = 0;
public:
    int coins() const;
    void income();
    void foreign_aid();
    virtual std::string role() const = 0;
    virtual void coup(const Player &target) = 0;
};
#endif //CPP__COUPGAME_A_PLAYER_HPP
