//
// Created by barak on 25/04/2022.
//

/** Ambassador :
 *  skills:
 *      Offensive -> Transfer().
 *      Defensive -> Block() *steal.
 *
 *  Assassin :
 *  skills:
 *      Offensive -> coup ?
 *
 *  Captain :
 *  skills:
 *      Offensive -> Steal().
 *      Defensive -> Block() *other steal
 *
 *  Contessa :
 *  skills:
 *      Defensive -> Block() *Assassination
 *
 *  Duke :
 *  skills:
 *      Offensive -> Tax()
 *      Defensive -> Block() *foreign_aid
 *
 *
 *  Additional Info:
 *  ~~ Player cannot have negative coin value. (captain steal, Ambassador transfer)
 *  ~~ The turns order is determined within the join order of the players to the game.
 *  ~~ Player cannot play not in his turn (exception)
 *  ~~ Player who can use block skill can only block specific roles:
 *      Duke - (Anyone who made foreign_aid)
 *      Ambassador - (Captain when he steal)
 *      Captain - (other Captain when he steal)
 *      Contessa - (Assassin on assassination)
 *
 *  ~~ More than one player can have same role.
 *  ~~ Player who possess 10 coins or more must perform a coup operation.
 *  ~~ Block Operations can be perform in any time between a full round of turns.
 *  ~~ Player who got blocked on foreign_aid op return the two coins and ends his turn.
 *  ~~ Player (can/can't ?) block an already blocked operation.
 *  */




#include "doctest.h"