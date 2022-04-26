//
// Created by barak on 25/04/2022.
//

#ifndef CPP__COUPGAME_A_CONTESSA_HPP
#define CPP__COUPGAME_A_CONTESSA_HPP


#include "../Player.hpp"

class Contessa: public Player {
private:
    int coin;
    coup::Game *game;
public:
    Contessa (coup::Game &game,const std::string &name);
    int coins() const override;
    void income() override;
    void foreign_aid() override;
    std::string role() const override;
    void coup(const Player &target) override;

    /** Special Skills */
    void block(const Player &attacker);
};


#endif //CPP__COUPGAME_A_CONTESSA_HPP
