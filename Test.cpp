//
// Created by barak on 25/04/2022.
//

/** Ambassador :
 *  skills:
 *      Offensive -> Transfer().
 *      Defensive -> block() *steal.
 *
 *  Assassin :
 *  skills:
 *      Offensive -> coup () *can use it from 3 coins to 6 with a risk.
 *
 *  Captain :
 *  skills:
 *      Offensive -> Steal().
 *      Defensive -> block() *other steal
 *
 *  Contessa :
 *  skills:
 *      Defensive -> block() *Assassination
 *
 *  Duke :
 *  skills:
 *      Offensive -> Tax()
 *      Defensive -> block() *foreign_aid
 *
 *
 *  Additional Info:
 *  ~~ Player cannot have negative coin value. (captain steal, Ambassador transfer) (exception)
 *  ~~ The turns order is determined within the join order of the players to the game. (exception)
 *  ~~ Player cannot play not in his turn (exception)
 *  ~~ Player who can use block skill can only block specific roles:
 *      Duke - (Anyone who made foreign_aid)
 *      Ambassador - (Captain when he steal)
 *      Captain - (other Captain when he steal)
 *      Contessa - (Assassin on assassination)
 *
 *  ~~ More than one player can have same role.
 *  ~~ Player who possess 10 coins or more must perform a coup operation.
 *  ~~ block Operations can be perform in any time between a full round of turns.
 *  ~~ Player who got blocked on foreign_aid op return the two coins and ends his turn.
 *  ~~ Player (can/can't ?) block an already blocked operation.
 *  ~~ Captain can steal from other player even if he have less then 2 coins.
 *  ~~ Cannot make an operation on a player who don't participant in the game anymore.
 *  ?? does ambasssador can transfer coin to himself.
 *  */




#include "doctest.h"
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"

using namespace coup;

TEST_CASE ("Valid Game") {

    Game scenario;
    Assassin assassin{scenario, "asi"};
    Ambassador ambassador{scenario, "ambi"};
    Captain captain{scenario, "capi"};
    Contessa contessa{scenario, "conti"};
    Duke duke{scenario, "duk"};

    std::vector<std::string> test_players;
    test_players.emplace_back("asi");
    test_players.emplace_back("ambi");
    test_players.emplace_back("capi");
    test_players.emplace_back("conti");
    test_players.emplace_back("duk");
    std::vector<std::string> game_players;

    for (size_t i = 0; i < test_players.size(); ++i) {
        CHECK(test_players.at(i) == game_players.at(i));
    }



    /** Start Game */

    assassin.income();
    ambassador.income();
    captain.income();
    contessa.income();
    duke.tax();
    /*Game coin STATUS: assassin: 1, ambassador: 1, captain: 1, contessa: 1, duke: 3*/
            SUBCASE("match coin values round 1") {
                CHECK_EQ(assassin.coins(), 1);
                CHECK_EQ(ambassador.coins(), 1);
                CHECK_EQ(captain.coins(), 1);
                CHECK_EQ(contessa.coins(), 1);
                CHECK_EQ(duke.coins(), 3);
    }
    assassin.foreign_aid();
    ambassador.foreign_aid();
    /* duke is blocking the ambassador from taking double coin*/
    duke.block(ambassador);
    /* captain is trying to steal 2 coins from the ambassador */
    captain.steal(ambassador);
    /* the ambassador is blocking captain stealing*/
    ambassador.block(captain);
    contessa.income();
    duke.tax();

    /*Game coin STATUS: assassin: 3, ambassador: 1, captain: 1, contessa: 2, duke: 6*/
            SUBCASE("match coin values round 2") {
                CHECK_EQ(assassin.coins(), 3);
                CHECK_EQ(ambassador.coins(), 1);
                CHECK_EQ(captain.coins(), 1);
                CHECK_EQ(contessa.coins(), 2);
                CHECK_EQ(duke.coins(), 6);
    }
    /* the assassin is trying to assassinate duke */
    assassin.coup(duke);
    /*contessa is blocking the assassin operation and saves duke's life */
    contessa.block(assassin);
    /* the ambassador is transferring one coin from contessa to assassin */
    ambassador.transfer(contessa, assassin);
    /*captain is stealing 2 coins from duke, the ambassador is not blocking this operation*/
    captain.steal(duke);
    contessa.foreign_aid();
    /* duke is not blocking contessa double coin*/
    duke.tax();

    /*Game coin STATUS: assassin: 1, ambassador: 1, captain: 1, contessa: 3, duke: 7*/
            SUBCASE("match coin values round 3") {
                CHECK_EQ(assassin.coins(), 1);
                CHECK_EQ(ambassador.coins(), 1);
                CHECK_EQ(captain.coins(), 1);
                CHECK_EQ(contessa.coins(), 3);
                CHECK_EQ(duke.coins(), 7);
    }
    assassin.foreign_aid();
    /* duke is blocking assassin from double coin*/
    duke.block(assassin);
    /* the ambassador is transferring one coin from captain to the assassin */
    ambassador.transfer(captain, assassin);
    /* the duke is not blocking captain from double coin */
    captain.foreign_aid();
    contessa.foreign_aid();
    /* duke is betraying contessa who saved him life from the assassin and coup her */
    duke.coup(contessa);


    /*Game coin STATUS: assassin: 2, ambassador: 1, captain: 2, contessa: DEAD, duke: 0*/
            SUBCASE("match coin values round 4") {
                CHECK_EQ(assassin.coins(), 2);
                CHECK_EQ(ambassador.coins(), 1);
                CHECK_EQ(captain.coins(), 2);
        // contessa DEAD
                CHECK_EQ(duke.coins(), 0);
    }
    assassin.income();
    ambassador.foreign_aid();
    /*duke is blocking ambassador from getting double coin*/
    duke.block(ambassador);
    captain.steal(assassin);
    /* ambassador is blocking captain from stealing 2 coins from the assassin */
    ambassador.block(captain);
    duke.tax();

    /*Game coin STATUS: assassin: 3, ambassador: 1, captain: 2, contessa: DEAD, duke: 3 */
            SUBCASE("match coin values round 5") {
                CHECK_EQ(assassin.coins(), 3);
                CHECK_EQ(ambassador.coins(), 1);
                CHECK_EQ(captain.coins(), 2);
        // contessa DEAD
                CHECK_EQ(duke.coins(), 3);
    }
    /*the assassin is eliminating the captain, contessa is already dead so captain can be saved */

    assassin.coup(captain);
    ambassador.transfer(duke, assassin);
    duke.tax();

    /*Game coin STATUS: assassin: 0, ambassador: 1, captain: DEAD, contessa: DEAD, duke: 5 */
            SUBCASE("match coin values round 6") {
                CHECK_EQ(assassin.coins(), 0);
                CHECK_EQ(ambassador.coins(), 1);
        // captain DEAD
        // contessa DEAD
                CHECK_EQ(duke.coins(), 5);
    }
    assassin.income();
    ambassador.foreign_aid();
    /* duke is blocking ambassador from taking double coin */
    duke.block(ambassador);
    duke.tax();

    /*Game coin STATUS: assassin: 1, ambassador: 1, captain: DEAD, contessa: DEAD, duke: 7 */
            SUBCASE("match coin values round 7") {
                CHECK_EQ(assassin.coins(), 1);
                CHECK_EQ(ambassador.coins(), 1);
        // captain DEAD
        // contessa DEAD
                CHECK_EQ(duke.coins(), 7);
    }
    assassin.income();
    ambassador.transfer(duke, assassin);
    duke.tax();

    /*Game coin STATUS: assassin: 3, ambassador: 1, captain: DEAD, contessa: DEAD, duke: 9 */
            SUBCASE("match coin values round 8") {
                CHECK_EQ(assassin.coins(), 3);
                CHECK_EQ(ambassador.coins(), 1);
        // captain DEAD
        // contessa DEAD
                CHECK_EQ(duke.coins(), 9);
    }
    /*the assassin is eliminating the duke and contessa cannot save him because he betrayed and killed her*/
    assassin.coup(duke);
    /* ambassador is taking double coin and duke is DEAD so he cant block him */
    ambassador.foreign_aid();

    /*Game coin STATUS: assassin: 0, ambassador: 3, captain: DEAD, contessa: DEAD, duke: DEAD */
            SUBCASE("match coin values round 9") {
                CHECK_EQ(assassin.coins(), 0);
                CHECK_EQ(ambassador.coins(), 3);
        // captain DEAD
        // contessa DEAD
        // duke dead
    }
    assassin.foreign_aid();
    ambassador.foreign_aid();

    /*Game coin STATUS: assassin: 2, ambassador: 5, captain: DEAD, contessa: DEAD, duke: DEAD */
            SUBCASE("match coin values round 6") {
                CHECK_EQ(assassin.coins(), 2);
                CHECK_EQ(ambassador.coins(), 5);
        // captain DEAD
        // contessa DEAD
        // duke dead
    }
    assassin.foreign_aid();
    ambassador.foreign_aid();

    /*Game coin STATUS: assassin: 4, ambassador: 7, captain: DEAD, contessa: DEAD, duke: DEAD */
            SUBCASE("match coin values round 6") {
                CHECK_EQ(assassin.coins(), 4);
                CHECK_EQ(ambassador.coins(), 7);
        // captain DEAD
        // contessa DEAD
        // duke dead
    }
    assassin.coup(ambassador);
            SUBCASE("match coin values round 6") {
                CHECK_EQ(assassin.coins(), 1);
        // ambassador DEAD
        // captain DEAD
        // contessa DEAD
        // duke dead
    }

    /** Game Ends */

            CHECK_EQ(scenario.winner(), "asi");


}

TEST_CASE ("Exceptions") {

//    SUBCASE("Negative coins") {
//
//    }
            SUBCASE("Turns") {
        Game game1{};
        Duke duke{game1, "shimon"};
        Ambassador ambassador{game1, "amber"};
        Assassin assassin{game1, "asi"};
        duke.income();
        /* not the assassin turn */
                CHECK_THROWS(assassin.income());
        ambassador.income();
        assassin.income();
        /* the the ambassador turn */
                CHECK_THROWS(ambassador.income());
        duke.tax();
        /*duke already made his turn by calling tax()*/
                CHECK_THROWS(duke.income());
    }
            SUBCASE("Invalid Blocks") {
        Game game_2{};
        Duke duke{game_2, "shimon"};
        Ambassador ambassador{game_2, "amber"};
        Assassin assassin{game_2, "asi"};
        Contessa contessa{game_2, "cony"};
        /** START GAME */
        /** ROUND 1*/
        duke.tax();
        ambassador.income();
        assassin.foreign_aid();
        /* the assassin did not assassinate so contessa block is not valid */
                CHECK_THROWS(contessa.block(assassin));
        contessa.foreign_aid();
        /* STATUS: duke: 3c, ambassador: 1c, assassin: 2c, contessa:0c */
        /** ROUND 2*/
                CHECK_NOTHROW(duke.block(contessa));

                CHECK_EQ(contessa.coins(), 0);

        duke.tax();
                CHECK_NOTHROW(ambassador.transfer(duke, assassin));
        assassin.coup(contessa);
        /* ambassador cannot block assassin */
                CHECK_THROWS(ambassador.block(assassin));
                CHECK_NOTHROW(contessa.block(assassin));
        contessa.income();
        /* STATUS: duke: 5c, ambassador: 1c, assassin: 0c, contessa:1c */
        /** ROUND 3*/
        duke.tax();
        /* contessa can block only assassin */
                CHECK_THROWS(contessa.block(duke));
        /*ambassador can block only captain steal operation*/
                CHECK_THROWS(ambassador.block(assassin));
        assassin.foreign_aid();
                CHECK_NOTHROW(duke.block(assassin));


    }
            SUBCASE("Invalid Skill") {
                SUBCASE("Invalid Targets") {
            Game game_3;
            Ambassador ambassador{game_3, "amber"};
            Assassin assassin{game_3, "asi"};
            Contessa contessa{game_3, "cony"};
            Captain captain{game_3, "capi"};
            Duke duke{game_3, "shimon"};

            /** START GAME */
            /** ROUND 1*/
            ambassador.foreign_aid();
            assassin.foreign_aid();
            contessa.foreign_aid();
            captain.foreign_aid();
            duke.tax();

            /**ROUND 2*/
            ambassador.foreign_aid();
            assassin.foreign_aid();
            contessa.foreign_aid();
            captain.foreign_aid();
            duke.tax();

            /**ROUND 3*/
            ambassador.foreign_aid();
            /* assassin can coup in cost of 3 coins*/
                    CHECK_NOTHROW(assassin.coup(contessa));
            contessa.foreign_aid();
            /* duke can block contessa for foreign_aid operation*/
                    CHECK_NOTHROW(duke.block(contessa));
            captain.foreign_aid();
            duke.tax();

            /**ROUND 4*/
            /* ~~ at this point contessa is out of the game, any operation on contessa is illegal*/
                    CHECK_THROWS(ambassador.transfer(contessa, assassin));
            ambassador.foreign_aid();
            assassin.foreign_aid();
                    CHECK_THROWS(contessa.income());
                    CHECK_THROWS(captain.steal(contessa));
                    CHECK_NOTHROW(captain.steal(assassin));
            duke.coup(ambassador);

            /**ROUND 4*/
            /* ~~ambassador is no longer in the game, any operation on him is illegal*/
                    CHECK_THROWS(ambassador.transfer(duke, assassin));
            /* assassin trying to coup players that do not in the game anymore */
                    CHECK_THROWS(assassin.coup(ambassador));
                    CHECK_THROWS(assassin.coup(contessa));
            assassin.coup(duke);
            /* captain try to steal from non-playing contessa*/
                    CHECK_THROWS(captain.steal(contessa));
            /*captain trying to steal from duke, but the assassin couped him,
             * since there is not a contessa player in the game the assassination is absolute */
                    CHECK_THROWS(captain.steal(duke));
                    CHECK_NOTHROW(captain.steal(assassin));
            /* duke has been assassinated */
                    CHECK_THROWS(duke.income());

            /** trying to operate on player from a different game */
            Game other;
            Ambassador ambassador_other{other, "ambi"};

            assassin.foreign_aid();
                    CHECK_THROWS(captain.steal(ambassador_other));
            captain.foreign_aid();

            assassin.foreign_aid();
            captain.foreign_aid();

                    CHECK_THROWS(assassin.coup(ambassador_other));
                    CHECK_NOTHROW(assassin.coup(captain));

                    CHECK_EQ(game_3.winner(), "asi");


        }
                SUBCASE("Lack Of Resources") {
            Game game_l;
            Ambassador ambassador{game_l, "amb"};
            Assassin assassin{game_l, "as"};
            Captain captain{game_l, "cap"};

            /** start game */
                    CHECK_THROWS(ambassador.coup(assassin));

                    CHECK_THROWS(assassin.coup(ambassador));

                    CHECK_THROWS(captain.coup(ambassador));

            ambassador.foreign_aid();
            assassin.foreign_aid();
            captain.foreign_aid();

            ambassador.foreign_aid();
            assassin.foreign_aid();
            captain.steal(assassin);

                    CHECK_THROWS(assassin.coup(ambassador));

            ambassador.foreign_aid();
            assassin.foreign_aid();
            captain.steal(ambassador);

                    CHECK_NOTHROW(assassin.coup(captain));
        }

    }
            SUBCASE("10 coins Characters") {
        Game game_10c;
        Ambassador ambassador{game_10c, "amb"};
        Assassin assassin{game_10c, "as"};
        Captain captain{game_10c, "cap"};

        for (int i = 0; i < 5; ++i) {
            ambassador.foreign_aid();
            assassin.foreign_aid();
            captain.foreign_aid();
        }
        /* ambassador have 10 coins so he have to coup at this turn */
                CHECK_THROWS(ambassador.income());
        ambassador.coup(assassin);
        /* assassin has coup -> can't income or even coup*/
                CHECK_THROWS(assassin.income());
                CHECK_THROWS(assassin.coup(captain));

        /* ambassador have 10 coins so he have to coup at this turn */
                CHECK_THROWS(captain.income());
        /*assassin is no longer in the game and cant be couped */
                CHECK_THROWS(captain.coup(assassin));
                CHECK_NOTHROW(captain.coup(ambassador));

                CHECK_EQ(game_10c.winner(), "cap");

    }

}