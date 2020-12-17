#ifndef SNAKETILE_H
#define SNAKETILE_H
#include "tile.h"

class SnakeTile:public Tile{
    public:
    SnakeTile();
    SnakeTile(int,int);
    SnakeTile(int);
    //int getNumberOfTile() const;
    //int getReward() const;
    int getPenalty() const;
    virtual int getTypeOfTile() const override;
    //void setNumberOfTile(int);
    //void setReward(int);
    void setPenalty(int);

    private:
    //int numberOfTile;
    //int reward;
    int penalty;
    //const char typeOfTile=1; //0=normal, 1=snake, 2=ladder
};

SnakeTile::SnakeTile(){
    penalty=3;
}
SnakeTile::SnakeTile(int _noTile,int _penalty):Tile(_noTile){
    penalty=_penalty;
}
SnakeTile::SnakeTile(int _noTile):Tile(_noTile){
    penalty=3;
}
int SnakeTile::getTypeOfTile() const{
    return 1;
}
int SnakeTile::getPenalty() const{
    return penalty;
}
void SnakeTile::setPenalty(int _penalty){
    penalty=_penalty;
}

#endif