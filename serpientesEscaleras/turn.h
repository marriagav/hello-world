#ifndef TURN_H
#define TURN_H
#include <iostream>
#include "myGame.h"
using std::ostream;

class Turn{
    private:
    int turn;
    int playerNo;
    Tile currentTile;
    Tile endTile;
    int roll;
    std::string typeOfMove;
    public:
    Turn(int,Tile,int,Tile,std::string,int);
    friend ostream &operator <<(ostream& salida, const Turn); //sobrecarga de operadores
};

Turn::Turn(int _player,Tile _startingTile,int _roll,Tile _endTile,std::string _type,int _turn ){
    playerNo=_player;
    currentTile=_startingTile;
    roll=_roll;
    endTile=_endTile;
    typeOfMove=_type;
    turn=_turn;

}
ostream &operator <<(ostream& salida, const Turn t1){
    salida<<t1.turn<<" "<< t1.playerNo <<" "<< t1.currentTile.getNumberOfTile() << " " << t1.roll << " "<< t1.typeOfMove<< " "<<t1.endTile.getNumberOfTile();
    return salida;
}

#endif