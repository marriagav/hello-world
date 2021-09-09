#ifndef PLAYER_H
#define PLAYER_H
#include "dice.h"
#include "string"
#include "tile.h"

class Player{
    public:
    Player();
    Player(int, Tile);
    int getNumber()const;
    Tile getTile() const;
    void setNumber(int);
    void setTile(Tile);

    private:
    int number;
    Tile currentTile;
};

Player::Player(){
    number=0;
    currentTile=Tile();
}
Player::Player(int _no, Tile _tile){
    number=_no;
    currentTile= _tile;
}
int Player::getNumber()const{
    return number;
}
Tile Player::getTile()const{
    return currentTile;
}
void Player::setNumber(int _no){
    number=_no;
}
void Player::setTile(Tile _tile){
    currentTile=_tile;
}
#endif