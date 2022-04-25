//
// Created by barak on 25/04/2022.
//

#ifndef CPP__COUPGAME_A_AMBASSADOR_HPP
#define CPP__COUPGAME_A_AMBASSADOR_HPP


#include "Player.hpp"

class Ambassador: public Player {
private:
    int coin;
public:
    Ambassador (coup::Game game,const std::string &name);
    int coins() const override;
    void income() override;
    void foreign_aid() override;
    std::string role() const override;
    void coup(const Player &target) override;

    /** Special Skills */
    void transfer(Player &from, Player &to);
};


#endif //CPP__COUPGAME_A_AMBASSADOR_HPP
