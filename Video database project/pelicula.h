#ifndef PELICULA_H
#define PELICULA_H
#include "video.h"
//#include "capitulo.h"

class Pelicula:public Video{
    private:
    string premios;
    string duracion;

    public:
    string getPremios()const{
        return premios;
    };
    string getDuracion()const {
        return duracion;
    };
    void setPremios(string prem){
        premios = prem;
    };
    void setDuracion(string dur){
        duracion = dur;
    };

    Pelicula();
    Pelicula(string, string, string, string,string);
    Pelicula(string, string, string, int, string, string);
    virtual string getTipoVideo()const override;
    virtual void muestraDatos()const override;
    virtual void pideUsuario() override;
    virtual void muestraCapitulos(string)const override;
    virtual void agregaCapitulo(Capitulo) override;
    virtual void mostrarCalificacionesCapitulos()const override;
    //friend ostream &operator <<(ostream& salida, const Pelicula); //sobrecarga de operadores fallida
};

Pelicula::Pelicula(){
    premios="";
    duracion="0";
}
Pelicula::Pelicula(string nombre, string gen,string cal, int anio, string dur, string prem):
Video(nombre,gen,cal,anio){
    premios=prem;
    duracion=dur;
}
Pelicula::Pelicula(string nombre, string gen,string cal, string dur, string _id):
Video(nombre,gen,cal,_id){
    premios="";
    duracion=dur;
    
}
void Pelicula::muestraDatos()const{
    std::cout<<"El tipo de video es: "<<"Película"<<"\n";
    std::cout<<"El nombre de la película es: "<<getNombreVideo()<<"\n";
    std::cout<<"El género de la película es: "<<getGenero()<<"\n";
    std::cout<<"La calificación de la película es: "<<getCalificacion()<<"\n";
    std::cout<<"El año de la película es: "<<getAnioLanzamiento()<<"\n";
    std::cout<<"La duración de la película es: "<<duracion<<"\n";
    std::cout<<"Premios: "<<premios<<"\n";
    std::cout<<"-------------\n ";
}
string Pelicula::getTipoVideo()const{
    return "Película";
}
/*ostream &operator <<(ostream& salida, const Pelicula p1){
    salida<<"El tipo de video es: "<<"Película"<<"\n"<<"El nombre de la película es: "<<p1.getNombreVideo()<<"\n"
    <<"El género de la película es: "<<p1.getGenero()<<"\n"<<"La calificación de la película es: "<<p1.getCalificacion()<<"\n"
    <<"El año de la película es: "<<p1.getAnioLanzamiento()<<"\n"<<"La duración de la película es: "<<p1.duracion<<"\n"
    <<"Premios: "<<p1.premios<<"\n";
    return salida;
}*/
void Pelicula::pideUsuario(){
    string input;
    std::cout<<"Nombre de Película: ";
    std::getline (std::cin, input);
    setNombreVideo(input);
    std::cout<<"Género de Película: ";
    std::getline (std::cin,input);
    setGenero(input);
    std::cout<<"Calificación de Película: ";
    string cali;
    std::getline (std::cin,cali);
    setCalificacion(cali);
    std::cout<<"Año de Película: ";
    string anio;
    std::getline (std::cin,anio);
    setAnioLanzamiento(stoi(anio));
    std::cout<<"Duración de Película: ";
    string dura;
    std::getline (std::cin,dura);
    duracion=dura;
    std::cout<<"Premios de Película: ";
    string prem;
    std::getline (std::cin,prem);
    premios=prem;
}
void Pelicula::muestraCapitulos(string cali) const{
    std::cout<<"No tiene capitulos";
}
void Pelicula::agregaCapitulo(Capitulo cap){
    muestraCapitulos("non");
}
void Pelicula::mostrarCalificacionesCapitulos() const{
    muestraCapitulos("non");
}

#endif