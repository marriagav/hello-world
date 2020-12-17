#ifndef VIDEO_H
#define VIDEO_H
#include<string>
#include<iostream>
#include "capitulo.h"
using std::ostream;
using std::string;

class Video{
    //atributos
    private:
    //string tipoVideo;
    string nombreVideo;
    string genero;
    string calificacion;
    string id;
    int anioLanamiento;
    //int duracion;
    //metodos
    public:
    //getters
    string getID()const{
        return id;
    }
    string getGenero()const{
        return genero;
    };
    string getCalificacion()const{
        return calificacion;
    };
    int getAnioLanzamiento()const{
        return anioLanamiento;
    };
    /*int getDuracion()const{
        return duracion;
    };*/
    //setters
    /*void setTipoVideo(string tipo){
        tipoVideo=tipo;
    };*/
    void setNombreVideo(string nombre){
        nombreVideo=nombre;
    };
    void setGenero(string gen){
        genero=gen;
    };
    void setCalificacion(string cal){
        calificacion=cal;
    };
    void setAnioLanzamiento(int anio){
        anioLanamiento=anio;
    };
    /*void setDuracion(int dur){
        duracion=dur;
    };*/
    //constructores
    Video();
    Video(/*string tipo,*/string, string,string, string);
    Video(/*string tipo,*/string, string,string, int);
    //sin cal
    Video(/*string tipo,*/string, string, int);

    //otros métodos
    string calificaVideo(const string&);
    string getNombreVideo()const{
        return nombreVideo;
    };
    int calculaAnio(string);

    //funciones virtual para polimorfismo
    virtual void muestraDatos()const=0;
    virtual void pideUsuario()=0;
    virtual string getTipoVideo()const=0;
    virtual void muestraCapitulos(string)const=0;
    virtual void agregaCapitulo(Capitulo)=0;
    virtual void mostrarCalificacionesCapitulos()const=0;
};
//implementación
Video::Video(){
    //tipoVideo="";
    nombreVideo="";
    genero="";
    calificacion="";
    anioLanamiento=0;
    id="";
    //duracion=0;
}
Video::Video(/*string tipo,*/string nombre, string gen,string cal/*,int dur*/, string _id){
    //tipoVideo=tipo;
    nombreVideo=nombre;
    genero=gen;
    calificacion=cal;
    anioLanamiento=calculaAnio(_id);
    id=_id;
    //duracion=dur;
}
Video::Video(/*string tipo,*/string nombre, string gen,string cal, int anio/*,int dur*/){
    //tipoVideo=tipo;
    nombreVideo=nombre;
    genero=gen;
    calificacion=cal;
    anioLanamiento=anio;
    //duracion=dur;
}
Video::Video(/*string tipo,*/string nombre, string gen, int anio/*, int dur*/){
    //tipoVideo=tipo;
    nombreVideo=nombre;
    genero=gen;
    calificacion="";
    anioLanamiento=anio;
    //duracion=dur;
}
string Video::calificaVideo(const string& cali){
    calificacion=cali;
    return calificacion;
}
int Video::calculaAnio(string _id){
    string anioString=_id.substr(0,4);
    anioLanamiento=stoi(anioString);
    return anioLanamiento;
}


#endif