#ifndef AUTOMATICGAME_H
#define AUTOMATICGAME_H
#include "myGame.h"

class AutomaticGame:public MyGame{
    public:
    AutomaticGame();
    AutomaticGame(Board, Dice,int,int);
    virtual void startGame() override;

    private:
};

AutomaticGame::AutomaticGame(){}
AutomaticGame::AutomaticGame(Board _myBoard,Dice _myDice, int _numberOfPlayers, int _noOfTurns):MyGame(_myBoard,_myDice,_numberOfPlayers,_noOfTurns){}
void AutomaticGame::startGame(){
    std::cout<<"Game:\n";
    while (gameEnded()==false){
        std::cout<<turn(whatTurn());
    };
}
#endif