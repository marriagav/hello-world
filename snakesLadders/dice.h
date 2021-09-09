#ifndef DICE_H
#define DICE_H
#include <random>

class Dice{
    public:
    int getNumberOfOptions() const;
    void setNumberOfOptions(int);
    int roll();
    Dice();
    Dice(int);

    private:
    int numberOfOptions;
};

Dice::Dice(){
    numberOfOptions=6;
}

Dice::Dice(int _no){
    numberOfOptions=_no;
}

int Dice::getNumberOfOptions() const{
    return numberOfOptions;
}

void Dice::setNumberOfOptions(int _no){
    numberOfOptions=_no;
}

int Dice::roll(){
    int rollNo;
    rollNo = rand() % numberOfOptions + 1;
    return rollNo;
}
#endif