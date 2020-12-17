#ifndef BOARD_H
#define BOARD_H
//#include "dice.h"
#include "player.h"
#include <vector>
#include <random>
#include <iostream>

class Board{
    public:
    Board();
    Board(int,int,int,int,int/*,int/*,Dice*/);
    int getLaderReward() const;
    int getSnakePenalty() const;
    void buildBoard();
    std::vector<Tile> getBoardTiles()const;
    void printBoard() const;
    int getSize()const;

    private:
    int size;
    int numberOfSnakes;
    int numberOfLadders;
    //int numberOfPlayers;
    int laderReward;
    int snakePenalty;
    //std::vector<Player> players;
    std::vector<Tile> boardTiles;
    //Dice boardDice;
};

Board::Board(){
    numberOfLadders=3;
    numberOfSnakes=3;
    //numberOfPlayers=2;
    laderReward=3;
    snakePenalty=3;
    //boardDice=Dice();
    size=30;
    Board::buildBoard();
}
Board::Board(int _size,int _numberOfSnakes,int _numberOfLadders,int _laderReward,int _snakePenalty){
    size=_size;
    numberOfSnakes=_numberOfSnakes;
    numberOfLadders=_numberOfLadders;
    //numberOfPlayers=_numberOfPlayers;
    laderReward=_laderReward;
    snakePenalty=_snakePenalty;
    //boardDice=_dice;
    Board::buildBoard();

}
std::vector<Tile> Board::getBoardTiles()const{
    return boardTiles;
}
int Board::getLaderReward()const{
    return laderReward;
}
int Board::getSize()const{
    return size;
}
int Board::getSnakePenalty()const{
    return snakePenalty;
}
void Board::buildBoard(){
    for (int i = 0; i < size; i++)
    {
        boardTiles.push_back(Tile(i+1));
    };
    for (int i = 0; i < numberOfLadders; i++)
    {
        int position=rand() % size-laderReward + 1;
        //Tile * ptr= &boardTiles[position];
        while (boardTiles[position].getTypeOfTile()!=0){
            position=rand() % size-laderReward + 1;
        }
        boardTiles[position].setTypeOfTile(2);
        boardTiles[position].setReward(laderReward);
    };
    for (int i = 0; i < numberOfSnakes; i++)
    {
        int position=rand() % size + snakePenalty+1;
        if (boardTiles[position].getNumberOfTile()==boardTiles.back().getNumberOfTile()){
            position=rand() % size + snakePenalty+1;
        };
        while (boardTiles[position].getTypeOfTile()!=0){
            position=rand() % size + snakePenalty+1;
            if (boardTiles[position].getNumberOfTile()==boardTiles.back().getNumberOfTile()){
            position=rand() % size + snakePenalty+1;
            };
        }
        /*||boardTiles[position].getNumberOfTile()==boardTiles.back().getNumberOfTile()*/
        boardTiles[position].setTypeOfTile(1);
        boardTiles[position].setPenalty(snakePenalty);
    };
    /*for (int i = 0; i < numberOfPlayers; i++)
    {
        players.push_back(Player(i+1,boardTiles[0]));
    };*/
}
void Board::printBoard() const{
    std::cout<<"Board:\n";
    for (int i = 0; i < size; i++)
    {
        if (i%3==0 && i>0){
            std::cout<<"\n";
        };
        std::string type="";
        if (boardTiles[i].getTypeOfTile()==0){
            type="N";
        }
        if (boardTiles[i].getTypeOfTile()==1){
            type="S";
        }
        if (boardTiles[i].getTypeOfTile()==2){
            type="L";
        }
        std::cout<<boardTiles[i].getNumberOfTile()<<"-"<<type<<" ";
    };
    std::cout<<"\n";
    std::cout<<"----------------";
    std::cout<<"\n";

}

#endif