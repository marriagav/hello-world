#ifndef PROGRAMA_H
#define PROGRAMA_H
#include <vector>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <bits/stdc++.h>
#include "pelicula.h"
#include "serie.h"
using std::vector;
using std::string;

class Programa{
    //atributos
    private:
    vector<Video*>listaPeliculas;
    vector<Video*>listaSeries;
    vector<vector<Video*>> videos;
    std::ifstream pelisFile;
    std::ifstream seriesFile;
    std::ifstream episodiosFile;
    //metodos
    public:
    //getters
    //setters
    //constructores
    Programa();
    Programa(Pelicula&,Serie&);
    Programa(const string&,const string&,const string&);

    //otros métodos
    void agregaPelicula(Pelicula*);
    void agregaSerie(Serie*);
    void menu();

};
//implementación
Programa::Programa(){
    listaPeliculas.push_back(new Pelicula());
    listaSeries.push_back(new Serie());
    videos.push_back(listaPeliculas);
    videos.push_back(listaSeries);

}
Programa::Programa(Pelicula& peli1,Serie& serie1){
    listaPeliculas.push_back(&peli1);
    listaSeries.push_back(&serie1);
    videos.push_back(listaPeliculas);
    videos.push_back(listaSeries);
}
//trabajando en:
Programa::Programa(const string& datosPelis,const string& datosSeries,const string& datosCapitulos){
        videos.push_back(listaPeliculas);
        videos.push_back(listaSeries);
        pelisFile.open(datosPelis);
        std::string id="";
        std::string title="";
        std::string duracion="";
        std::string genero="";
        std::string calificacion="";
        if (pelisFile.is_open()){   
            //std::cout << "Unable to open file";
            while (!pelisFile.eof()) {
                std::getline(pelisFile,id,',');
                std::getline(pelisFile,title,',');
                std::getline(pelisFile,duracion,',');
                std::getline(pelisFile,genero,',');
                std::getline(pelisFile,calificacion,'\n');
                Pelicula* vid=new Pelicula(title,genero,calificacion,duracion,id);
                //vid->calculaAnio(id);
                agregaPelicula(vid);
                //string nombre, string gen,string cal, string dur, string _id
            }; 
        pelisFile.close();
        }
        else {std::cout << "Unable to open file";};
        
        //vector <Serie> series;
        seriesFile.open(datosSeries);
        id="";
        title="";
        genero="";
        std::string temporadas="";
        if (seriesFile.is_open()){   
            //std::cout << "Unable to open file";
            while (!seriesFile.eof()) {
                std::getline(seriesFile,id,',');
                std::getline(seriesFile,title,',');
                std::getline(seriesFile,genero,',');
                std::getline(seriesFile,temporadas,'\n');
                //std::cout<<id<<title<<genero<<temporadas;
                Serie* vid=new Serie(title,genero,std::stoi(temporadas),id);
                agregaSerie(vid);
                //series.push_back(*vid);
                //string nombre, string gen, int temp, string _id
            }; 
        seriesFile.close();
        }
        else {std::cout << "Unable to open file";};

 
        episodiosFile.open(datosCapitulos);
        std::string capid="";
        std::string seriesid="";
        title="";
        duracion="";
        calificacion="";
        std::string temporada="";
        if (episodiosFile.is_open()){   
            //std::cout << "Unable to open file";
            while (!episodiosFile.eof()) {
                std::getline(episodiosFile,seriesid,',');
                std::getline(episodiosFile,capid,',');
                std::getline(episodiosFile,title,',');
                std::getline(episodiosFile,duracion,',');
                std::getline(episodiosFile,calificacion,',');
                std::getline(episodiosFile,temporada,'\n');
                Capitulo cap=Capitulo(std::stoi(temporada),duracion,title,seriesid,capid,calificacion);
                for (int i = 0; i < videos[1].size(); i++)
                {
                    if (cap.getID()==videos[1][i]->getID()){
                        videos[1][i]->agregaCapitulo(cap);
                        //videos[1][i]->muestraCapitulos();
                    }
                    
                }
                //int temp, string dur, string titu,string _idSer,string _idCap,string _cali
            }; 
        episodiosFile.close();
        }
        else {std::cout << "Unable to open file";};

}
void Programa::agregaPelicula(Pelicula* nuevaPeli){
    videos[0].push_back(nuevaPeli);
}
void Programa::agregaSerie(Serie* nuevaSerie){
    videos[1].push_back(nuevaSerie);
}
void Programa::menu(){
    string respuesta;
    while(respuesta!="3"){
        std::cout<<"¿Qué deseas hacer?\n";
        std::cout<<"(0) Todos los videos\n";
        std::cout<<"(1) Sección películas\n";
        std::cout<<"(2) Sección series\n";
        std::cout<<"(3) Salir\n";
        std::getline (std::cin,respuesta);
        if (respuesta=="0"){
                string respuesta;
            while(respuesta!="4"){
                std::cout<<"(1) Orden predeteminado\n";
                std::cout<<"(2) Por calificación\n";
                std::cout<<"(3) Por género\n";
                std::cout<<"(4) Regresar\n";
                std::getline (std::cin,respuesta);
                if (respuesta=="1"){
                    for (int z = 0; z < videos.size(); z++){
                        for (int i = 0; i < videos[z].size(); i++)
                            {
                                std::cout<<"Video "<<":\n";
                                videos[z][i]->muestraDatos();
                            }   
                    }  
                    std::cout<<"-------------\n ";  
                }

                // arreglar esto
                if (respuesta=="2"){
                    vector <int> ratings;
                    //vector <Video*> porRating;
                    string rate;
                    double rates;
                    int ratio;
                    for (int z = 0; z < videos.size(); z++){
                        for (int i = 0; i < videos[z].size(); i++)
                            {
                                rate=videos[z][i]->getCalificacion();
                                if (rate != "Sin calificar"){
                                    rates=stod(rate);
                                    ratio=int(rates*10);
                                    if (!(std::find(ratings.begin(), ratings.end(), ratio) != ratings.end())){
                                        ratings.push_back(ratio);
                                    }
                                }
                                
                            } 
                    }
                    std::sort(ratings.begin(), ratings.end(), std::greater<int>());
                    //string rater;
                    vector<Video*> allVids;
                        for (int z = 0; z < videos.size(); z++){
                            for (int i = 0; i < videos[z].size(); i++){  
                                allVids.push_back(videos[z][i]);
                            }  
                        }

                    for (int y=0; y<ratings.size();y++){
                        //std::cout<<ratings[y];
                        for (int i = 0; i < allVids.size(); i++){
                                rate=allVids[i]->getCalificacion(); 
                                if (rate != "Sin calificar"){
                                    rates=stod(rate);
                                    ratio=int(rates*10);
                                    if (ratio==ratings[y]){
                                        std::cout<<"Video "<<":\n";
                                        allVids[i]->muestraDatos();
                                    }
                                }
                        }
                    }
                    
                    //ya quedo;
                    for (int z = 0; z < videos.size(); z++){
                            for (int i = 0; i < videos[z].size(); i++)
                                {    
                                    if (videos[z][i]->getCalificacion()=="Sin calificar"){
                                    std::cout<<"Video "<<":\n";
                                    videos[z][i]->muestraDatos();
                                    }
                                }   
                        }  
                      
                    
                }
                if (respuesta=="3"){
                    vector <string> listGeneros;
                    string gen;
                    string cali;
                    string current;
                    std::cout<<"¿Qué genero?\n";
                    for (int z = 0; z < videos.size(); z++){
                    for (int i = 0; i < videos[z].size(); i++)
                    {
                        current=videos[z][i]->getGenero();
                        if (!(std::find(listGeneros.begin(), listGeneros.end(), current) != listGeneros.end())){
                            //std::cout<<"("<<i+1<<") "<<videos[z][i]->getGenero();
                            //std::cout<<"\n";
                            listGeneros.push_back(current);
                        }
                    };
                    };
                    //imprimir lista de generos
                    for (int i = 0; i < listGeneros.size(); i++)
                    {
                        std::cout<<"("<<i+1<<") "<<listGeneros[i];
                        std::cout<<"\n";
                    }
                    
                    std::getline (std::cin,gen);
                    for (int z = 0; z < videos.size(); z++){
                        for (int i = 0; i < videos[z].size(); i++)
                            {
                                if (videos[z][i]->getGenero()==listGeneros[stoi(gen)-1]){
                                std::cout<<"Video "<<":\n";
                                videos[z][i]->muestraDatos();
                                }
                            }   
                    }  
                }
                /*if (respuesta=="4"){
                    break;
                }*/
            }
        }
        if (respuesta=="1"){
            string respuesta;
            while(respuesta!="4"){
                std::cout<<"¿Qué deseas hacer?\n";
                std::cout<<"(1) Consultar películas\n";
                std::cout<<"(2) Agregar una película\n";
                std::cout<<"(3) Calificar una película\n";
                std::cout<<"(4) Regresar\n";
                std::getline (std::cin,respuesta);
                if (respuesta=="1"){
                    string respuesta;
                    while(respuesta!="3"){
                        std::cout<<"(1) Orden predeteminado\n";
                        std::cout<<"(2) Con cierta calificación\n";
                        std::cout<<"(3) Regresar\n";
                        std::getline (std::cin,respuesta);
                        if (respuesta=="1"){
                            for (int i = 0; i < videos[0].size(); i++)
                            {
                                //std::cout<<*videos[0][i]; //no se cómo hacer que una función friend sea virtual
                                std::cout<<"Video "<<i+1<<":\n";
                                videos[0][i]->muestraDatos();
                            }
                            std::cout<<"-------------\n ";
                            }
                        if (respuesta=="2"){
                            string cali;
                            int contador=0;
                            std::cout<<"¿Qué calificación quieres ver (número del 0 al 10)?\n";
                            //manejo de excepciones
                            try{
                                std::getline (std::cin,cali);
                                for (int i = 0; i < videos[0].size(); i++){
                                    if (videos[0][i]->getCalificacion()==cali){
                                        videos[0][i]->muestraDatos();
                                        contador+=1;
                                    }
                                };
                                if (contador==0){
                                    throw std::out_of_range(cali + " inválido, no hay películas con esa calificación");
                                }
                            }
                            catch (std::out_of_range &excp){
                            std::cout<<excp.what()<<std::endl;
                            vector<string> calificacionesTotales;
                            string actual;
                                std::cout<<"Solo existen Películas con las siguientes calificaciones:"<<std::endl;
                                for (int i = 0; i < videos[0].size(); i++){
                                    actual=videos[0][i]->getCalificacion();
                                    if(!(std::find(calificacionesTotales.begin(), calificacionesTotales.end(), actual) != calificacionesTotales.end())){
                                        calificacionesTotales.push_back(actual);
                                    }
                                }
                                for (int i = 0; i < calificacionesTotales.size(); i++)
                                {
                                    std::cout<<calificacionesTotales[i]<<". ";
                                }
                                
                                std::cout<<std::endl;
                            }

                        }
                        /*if (respuesta=="3"){
                            break;
                        }*/
                    }
                }
                if (respuesta=="2"){
                    Pelicula* vid=new Pelicula();
                    vid->pideUsuario();
                    agregaPelicula(vid);
                    std::cout<<"-------------\n ";
                }
                if (respuesta=="3"){
                    string vid;
                    string cali;
                    std::cout<<"¿Qué película deseas calificar?\n";
                    for (int i = 0; i < videos[0].size(); i++)
                    {
                        std::cout<<"("<<i+1<<") "<<videos[0][i]->getNombreVideo();
                        std::cout<<"\n";
                    };
                    std::getline (std::cin,vid);
                    std::cout<<"¿Qué calificación le pones?\n";
                    std::getline (std::cin,cali);
                    videos[0][stoi(vid)-1]->calificaVideo(cali);
                    std::cout<<"-------------\n ";
                }
                /*if (respuesta=="4"){
                    break;
                }*/
            }
        }
        if (respuesta=="2"){
            string respuesta;
            while(respuesta!="5"){
                std::cout<<"¿Qué deseas hacer?\n";
                std::cout<<"(1) Consultar series\n";
                std::cout<<"(2) Agregar una serie\n";
                std::cout<<"(3) Calificar una serie\n";
                std::cout<<"(4) Ver capitulos de una serie\n";
                std::cout<<"(5) Regresar\n";
                std::getline (std::cin,respuesta);
                if (respuesta=="1"){
                    for (int i = 0; i < videos[1].size(); i++)
                    {
                        std::cout<<"Video "<<i+1<<":\n";
                        videos[1][i]->muestraDatos();
                        //std::cout<<"Capitulos:\n";
                        //videos[1][i]->muestraCapitulos();
                    }
                    std::cout<<"-------------\n ";
                }
                if (respuesta=="2"){
                    Serie* vid=new Serie();
                    vid->pideUsuario();
                    agregaSerie(vid);
                    std::cout<<"-------------\n ";
                }
                if (respuesta=="3"){
                    string vid;
                    string cali;
                    std::cout<<"¿Qué serie deseas calificar?\n";
                    for (int i = 0; i < videos[1].size(); i++)
                    {
                        std::cout<<"("<<i+1<<") "<<videos[1][i]->getNombreVideo();
                        std::cout<<"\n";
                    };
                    std::getline (std::cin,vid);
                    std::cout<<"¿Qué calificación le pones?\n";
                    std::getline (std::cin,cali);
                    videos[1][stoi(vid)-1]->calificaVideo(cali);
                    std::cout<<"-------------\n ";
                }
                if (respuesta=="4"){
                    string vid;
                    std::cout<<"¿De qué serie deseas ver capitulos?\n";
                    for (int i = 0; i < videos[1].size(); i++)
                    {
                        std::cout<<"("<<i+1<<") "<<videos[1][i]->getNombreVideo();
                        std::cout<<"\n";
                    };
                    std::getline (std::cin,vid);
                    string respuest;
                    std::cout<<"(1) Orden predeteminado\n";
                    std::cout<<"(2) Con cierta calificación\n";
                    std::cout<<"(3) Regresar\n";
                    std::getline (std::cin,respuest);
                    if (respuest=="1"){
                    videos[1][stoi(vid)-1]->muestraCapitulos("all");
                    std::cout<<"-------------\n ";
                    }
                    if (respuest=="2"){
                        string cali;
                        std::cout<<"¿Qué calificación quieres ver (número del 0 al 10)?\n";
                        try{
                        std::getline (std::cin,cali);
                        videos[1][stoi(vid)-1]->muestraCapitulos(cali);
                        }
                        //manejo de excepciones
                        catch(std::out_of_range &excp){ 
                            std::cout<<excp.what()<<std::endl;
                            std::cout<<"Solo existen capítulos con las siguientes calificaciones:"<<std::endl;
                            videos[1][stoi(vid)-1]->mostrarCalificacionesCapitulos();
                        }
                    }
                    if (respuest=="3"){
                        break;
                    }
                    
                }
                /*if (respuesta=="5"){
                    break;
                }*/
            }
        }
        /*if (respuesta=="3"){ 
                break;
        }*/
    }

}

#endif