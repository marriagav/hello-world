#ifndef MYGAME_H
#define MYGAME_H
#include <stdexcept> 
#include <ostream>
#include "dice.h"
#include "board.h"
#include "turn.h"

using std::ostream;

class MyGame{
    public:
    MyGame();
    MyGame(Board, Dice,int, int);
    void buildMyGame();
    void startPlayers();
    std::string turn(int);
    int whatTurn();
    bool gameEnded() const;
    void setGameState(bool);
    virtual void startGame() =0;

    private:
    Board myBoard;
    Dice gameDice;
    int numberOfPlayers;
    int turnNo;
    int noOfTurns;
    std::vector<Player> players;
    bool ended=false;
};

MyGame::MyGame(){
    myBoard=Board();
    gameDice=Dice();
    numberOfPlayers=2;
    turnNo=1;
    noOfTurns=60;
    startPlayers();
}
MyGame::MyGame(Board _myBoard,Dice _myDice, int _numberOfPlayers, int _noOfTurns){
    myBoard=_myBoard;
    gameDice=_myDice;
    numberOfPlayers=_numberOfPlayers;
    turnNo=1;
    noOfTurns=_noOfTurns;
    startPlayers();
}
bool MyGame::gameEnded() const{
    return ended;
}
void MyGame::setGameState(bool _ended){
    ended=_ended;
}

void MyGame::startPlayers(){
    for (int i = 0; i < numberOfPlayers; i++)
        {
            players.push_back(Player(i+1,myBoard.getBoardTiles()[0]));
        };
}
std::string MyGame::turn(int _playerNumber){
    std::string type;
    std::string message;
    Tile currentTile=players[_playerNumber-1].getTile();
    int roll=gameDice.roll();
    int advance=roll+currentTile.getNumberOfTile()-1;
    if (advance>=myBoard.getBoardTiles().back().getNumberOfTile()){
        advance=myBoard.getBoardTiles().back().getNumberOfTile();
    }
    Tile endTile=myBoard.getBoardTiles()[advance];
    int no_tile=endTile.getNumberOfTile();
    no_tile=currentTile+endTile; //sobrecarga de operadores
    if (endTile.getTypeOfTile()==1){
        type="S";
    }
    if (endTile.getTypeOfTile()==2){
        type="L";
    }
    if (endTile.getTypeOfTile()==0){
        type="N";
    };
    players[_playerNumber-1].setTile(myBoard.getBoardTiles()[no_tile-1]);
    if (players[_playerNumber-1].getTile().getNumberOfTile()==0 && turnNo!=1){
        players[_playerNumber-1].setTile(myBoard.getBoardTiles().back().getNumberOfTile());
    };
    Turn turno=Turn(_playerNumber,currentTile,roll,players[_playerNumber-1].getTile(),type,turnNo);
    std::cout<<turno<<std::endl; //sobrecarga de operadores
    if (players[_playerNumber-1].getTile().getNumberOfTile()==myBoard.getBoardTiles().back().getNumberOfTile()){
        message=" \nThe game ends. Player number "+ std::to_string(_playerNumber) + " won!\n";
        ended=true;
    }
    if (turnNo>=noOfTurns){
        message=" \nThe game ends. Number of turns finished\n";
        ended=true;
    };
    
    turnNo+=1;
    return message;
}

int MyGame::whatTurn(){
    int whosTurn=turnNo%numberOfPlayers;
    if (whosTurn==0){
        whosTurn=numberOfPlayers;
    };
    return whosTurn;
}

#endif