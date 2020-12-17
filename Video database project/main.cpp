#include "programa.h"
#include <string>

int main(){
    Programa programa2=Programa("datosPeliculas.txt","datosSeries.txt","datosCapitulos.txt");
    programa2.menu();
    
    return 0;
};