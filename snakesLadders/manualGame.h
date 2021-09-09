#ifndef MANUALGAME_H
#define MANUALGAME_H
#include "myGame.h"

class ManualGame:public MyGame{
    public:
    ManualGame();
    ManualGame(Board, Dice,int,int);
    virtual void startGame() override;

    private:
};

ManualGame::ManualGame(){}
ManualGame::ManualGame(Board _myBoard,Dice _myDice, int _numberOfPlayers, int _noOfTurns):MyGame(_myBoard,_myDice,_numberOfPlayers,_noOfTurns){}
void ManualGame::startGame(){
    std::cout<<"Game:\n";
    while (gameEnded()==false){
        try{ //manejo de excepciones
            std::string action="";
            std::cout<<"Jugador #" << whatTurn() << " ¿Qué deseas hacer?\n";
            std::cout<<"(1) Tirar dado\n";
            std::cout<<"(2) Salir\n";
            std::getline (std::cin,action);
            if (stoi(action)!=2 && stoi(action)!=1){
                throw std::out_of_range(action + " invalido, ingresa un número que sea 1 o 2");
            }
            if (action=="1"){
                std::cout<<turn(whatTurn());
            }
            if (action=="2"){
                std::cout<<"Game Finished \n";
                setGameState(true);
                break;
            }
        }
        catch(std::out_of_range &exe){
            std::cout<<exe.what()<<std::endl;
        }
    };
}
#endif