#ifndef LADDERTILE_H
#define LADDERTILE_H
#include "tile.h"

class LadderTile:public Tile{
    public:
    LadderTile();
    LadderTile(int,int);
    LadderTile(int);
    //int getNumberOfTile() const;
    int getReward() const;
    virtual int getTypeOfTile() const override;
    //int getPenalty() const;
    //void setNumberOfTile(int);
    void setReward(int);
    //void setPenalty(int);

    private:
    //int numberOfTile;
    //const char typeOfTile=2; //0=normal, 1=snake, 2=ladder
    int reward;
    //int penalty;
};

LadderTile::LadderTile(){
    reward=3;
}
LadderTile::LadderTile(int _noTile,int _reward):Tile(_noTile){
    reward=_reward;
}
LadderTile::LadderTile(int _noTile):Tile(_noTile){
    reward=3;
}
int LadderTile::getTypeOfTile() const{
    return 2;
}
int LadderTile::getReward() const{
    return reward;
}
void LadderTile::setReward(int _reward){
    reward=_reward;
}

#endif