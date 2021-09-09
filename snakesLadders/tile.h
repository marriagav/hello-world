#ifndef TILE_H
#define TILE_H

class Tile{
    public:
    Tile();
    Tile(int);
    int getNumberOfTile() const;
    char getTypeOfTile() const;
    void setTypeOfTile(char);
    void setNumberOfTile(int);
    void setReward(int);
    void setPenalty(int);
    int getPenalty()const;
    int getReward()const;
    friend int operator +(const Tile&,const Tile&);

    private:
    int numberOfTile;
    char typeOfTile; //0=normal, 1=snake, 2=ladder
    int reward;
    int penalty;
};

Tile::Tile(){
    numberOfTile=0;
    typeOfTile=0;
    reward=0;
    penalty=0;
}
Tile::Tile(int _noTile){
    numberOfTile=_noTile;
    typeOfTile=0;
    reward=0;
    penalty=0;
}
char Tile::getTypeOfTile() const{
    return typeOfTile;
}
int Tile::getNumberOfTile() const{
    return numberOfTile;
}
void Tile::setNumberOfTile(int _noTile){
    numberOfTile=_noTile;
}
void Tile::setTypeOfTile(char _type){
    typeOfTile=_type;
}
void Tile::setPenalty(int _pen){
    penalty=_pen;
}
int Tile::getPenalty()const{
    return penalty;
}
void Tile::setReward(int _rew){
    reward=_rew;
}
int Tile::getReward()const{
    return reward;
}
int operator +(const Tile& uno,const Tile& dos){ //sobrecarga de operadores
    int starting=uno.getNumberOfTile();
    char type=dos.getTypeOfTile();
    int ending=0;
    if (type==0){
        ending=dos.getNumberOfTile();
    }
    if (type==1){
        ending=dos.getNumberOfTile()-dos.getPenalty();
    }
    if (type==2){
        ending=dos.getNumberOfTile()+dos.getReward();
    };
    return ending;
}
#endif