//
// Created by barak on 25/04/2022.
//

#ifndef CPP__COUPGAME_A_CAPTAIN_HPP
#define CPP__COUPGAME_A_CAPTAIN_HPP


#include "Player.hpp"

class Captain: public Player {
private:
    int coin;
    coup::Game *game;
public:
    Captain (coup::Game &game, const std::string &name);

    std::string role() const override;
    void coup(const Player &target) override;

    /** Special Skills */
    void block(const Player &attacker);
    void steal(Player &victim);
};


#endif //CPP__COUPGAME_A_CAPTAIN_HPP
