//
// Created by barak on 25/04/2022.
//

#ifndef CPP__COUPGAME_A_DUKE_HPP
#define CPP__COUPGAME_A_DUKE_HPP

//#include "Game.hpp"
#include "Player.hpp"

class Duke:public Player {
private:
    int coin;
public:
    Duke (coup::Game game, const std::string &name);
    int coins() const override;
    void income() override;
    void foreign_aid() override;
    std::string role() const override;
    void coup(const Player &target) override;

    /** Special Skills */
    void block(const Player &attacker);
    void tax();
};
#endif //CPP__COUPGAME_A_DUKE_HPP
