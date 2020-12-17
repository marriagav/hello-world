#ifndef CAPITULO_H
#define CAPITULO_H
#include <string>
#include<iostream>
//#include "serie.h"
using std::string;
using std::ostream;

class Capitulo{
    private:
    string duracion;
    int temporada;
    int noCapitulo;
    string titulo;
    string idSerie;
    string idCapitulo;
    string calificacion;

    public:
    int getNoCapitulo()const{
        return noCapitulo;
    };
    int getTemporada()const{
        return temporada;
    };
    string getDuracion()const{
        return duracion;
    };
    string getTitulo()const{
        return titulo;
    };
    string getID()const{
        return idSerie;
    };
    string getCalificacion()const{
        return calificacion;
    };
    void setNoCapitulo(int cap){
        noCapitulo = cap;
    };
    void setTemporada(int temp){
        temporada = temp;
    };
    void setDuracion(string dur){
        duracion = dur;
    };
    void setTitulo(string titu){
        titulo=titu;
    };

    Capitulo();
    Capitulo(int, string, string, string, string, string);
    Capitulo(int, int, string, string);

    void imprimeCapitulo()const;
    void pideCapituloUsuario();
    friend ostream &operator <<(ostream& salida, const Capitulo); //sobrecarga de operadores
    int calculaDatosRestantes(string);
};

Capitulo::Capitulo(){
    duracion="0";
    temporada=0;
    titulo="";
    noCapitulo=0;
    calificacion="Sin calificar";
}
Capitulo::Capitulo(int cap, int temp, string dur, string titu){
    noCapitulo = cap;
    temporada = temp;
    duracion = dur;
    titulo=titu;
    calificacion="Sin calificar";
}

Capitulo::Capitulo(int temp, string dur, string titu,string _idSer,string _idCap,string _cali){
    //noCapitulo = cap;
    temporada = temp;
    duracion = dur;
    titulo=titu;
    idSerie=_idSer;
    idCapitulo=_idCap;
    calificacion=_cali;
    noCapitulo=calculaDatosRestantes(_idCap);
}
//sobrecarga de operadores:
ostream &operator <<(ostream& salida, const Capitulo c1){
    salida<<"Nombre del capítulo: "<<c1.titulo<<"\n"
    <<"Temporada del capítulo: "<<c1.temporada<<"\n"
    <<"Número de capítulo: "<<c1.noCapitulo<<"\n"
    <<"Duración del capítulo: "<<c1.duracion<<"\n"
    <<"Calificacion del capítulo: "<<c1.calificacion<<"\n";
    return salida;
} 

/*void Capitulo::imprimeCapitulo()const{
    std::cout<<"Nombre del capítulo: "<<titulo<<"\n";
    std::cout<<"Temporada del capítulo: "<<temporada<<"\n";
    std::cout<<"Número de capítulo: "<<noCapitulo<<"\n";
    std::cout<<"Duración del capítulo: "<<duracion<<"\n";
    std::cout<<"-------------\n";
}*/ //código anterior sin sobrecarga de operadores

void Capitulo::pideCapituloUsuario(){
    std::cout<<"Nombre del capítulo: ";
    string name;
    std::getline (std::cin,name);
    titulo=name;
    std::cout<<"Temporada del capítulo: ";
    string temp;
    std::getline (std::cin,temp);
    temporada=stoi(temp);
    std::cout<<"Número del capítulo: ";
    string num;
    std::getline (std::cin,num);
    noCapitulo=stoi(num);
    std::cout<<"Duración del capítulo: ";
    string dur;
    std::getline (std::cin,dur);
    duracion=dur;
}

int Capitulo::calculaDatosRestantes(string _id){
    char noString=_id.back();
    int number=(int)(noString)-48;
    return number;
    //20110125-S01E01
    /*char stringNo=getCodigo().at(i);
    int number=(int)(stringNo)-48;
    */
}


#endif