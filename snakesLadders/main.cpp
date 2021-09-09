
#include <iostream>
#include "automaticGame.h"
#include "manualGame.h"
using std::cout;
using std::stoi;

int main(){
    MyGame *mg;

    std::string typeOfGame="";
    std::string noOfTiles="";
    std::string noOfLadders="";
    std::string noOfSnakes="";
    std::string ladderBonus="";
    std::string snakePenalty="";
    std::string diceSides="";
    std::string noOfPlayers="";
    std::string noOfTurns="";

    std::cout<<"Configuración del juego:\n";
    std::cout<<"Tipo de juego (M) Manual o (A) Automático: ";
    std::getline (std::cin,typeOfGame);
    std::cout<<"Número total de casillas: ";
    std::getline (std::cin,noOfTiles);
    std::cout<<"Número de escaleras: ";
    std::getline (std::cin,noOfLadders);
    std::cout<<"Número de serpientes: ";
    std::getline (std::cin,noOfSnakes);
    std::cout<<"Bonus por escalera: ";
    std::getline (std::cin,ladderBonus);
    std::cout<<"Castigo por serpiente: ";
    std::getline (std::cin,snakePenalty);
    std::cout<<"Número de lados del dado: ";
    std::getline (std::cin,diceSides);
    std::cout<<"Número de jugadores: ";
    std::getline (std::cin,noOfPlayers);
    std::cout<<"Número total de turnos: ";
    std::getline (std::cin,noOfTurns);
    
    Board board1=Board(stoi(noOfTiles),stoi(noOfSnakes),stoi(noOfLadders), stoi(ladderBonus),stoi(snakePenalty));
    board1.printBoard();
    
    if (typeOfGame=="A"){
        mg= new AutomaticGame(board1,Dice(stoi(diceSides)),stoi(noOfPlayers),stoi(noOfTurns));
    }
    else if (typeOfGame=="M"){
        mg= new ManualGame(board1,Dice(stoi(diceSides)),stoi(noOfPlayers),stoi(noOfTurns));
    };
    mg->startGame();
    return 0;
}