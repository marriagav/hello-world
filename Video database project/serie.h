#ifndef SERIE_H
#define SERIE_H
#include "video.h"
#include <vector>
//#include "capitulo.h"

class Serie:public Video{
    private:
    int noTemporadas;
    std::vector<Capitulo> capitulos;

    public:
    int getNoTemporadas()const{
        return noTemporadas;
    };
    std::vector<Capitulo> getCapitulos()const{
        return capitulos;
    };
    void setNoTemporadas(int dur){
        noTemporadas = dur;
    };
    void setCapitulos(std::vector<Capitulo> caps){
        capitulos = caps;
    };

    Serie();
    Serie(string, string, int, string);
    Serie(string, string,string, int, int, std::vector<Capitulo>);
    virtual string getTipoVideo()const override;
    virtual void muestraDatos()const override;
    virtual void pideUsuario() override;
    virtual void agregaCapitulo(Capitulo) override;
    virtual void muestraCapitulos(string)const override;
    void sortChapter(Capitulo);
    virtual void mostrarCalificacionesCapitulos()const override;
};

Serie::Serie(){
    noTemporadas=0;
    std::vector<Capitulo> vect(0, Capitulo());
    capitulos=vect;
}

Serie::Serie(string nombre, string gen,string cal, int anio, int temp, std::vector<Capitulo> caps):
Video(nombre,gen,cal,anio){
    noTemporadas=temp;
    capitulos=caps;
}

Serie::Serie(string nombre, string gen, int temp, string _id):
Video(nombre,gen,"Sin calificar",_id){
    noTemporadas=temp;
    //capitulos=caps;
    //setAnioLanzamiento(calculaAnio(_id));
}

string Serie::getTipoVideo()const{
    return "Serie";
}

void Serie::muestraDatos()const{
    std::cout<<"El tipo de video es: "<<"Serie"<<"\n";
    std::cout<<"El nombre de la serie es: "<<getNombreVideo()<<"\n";
    std::cout<<"El género de la serie es: "<<getGenero()<<"\n";
    std::cout<<"La calificación de la serie es: "<<getCalificacion()<<"\n";
    std::cout<<"El año de la serie es: "<<getAnioLanzamiento()<<"\n";
    std::cout<<"Número de temporadas: "<<noTemporadas<<"\n";
    std::cout<<"Número de capítulos: "<<capitulos.size()<<"\n";
    //std::cout<<"-------------\n ";
}

void Serie::pideUsuario(){
    string input;
    std::cout<<"Nombre de Serie: ";
    std::getline (std::cin, input);
    setNombreVideo(input);
    std::cout<<"Género de Serie: ";
    std::getline (std::cin,input);
    setGenero(input);
    std::cout<<"Calificación de Serie: ";
    string cali;
    std::getline (std::cin,cali);
    setCalificacion(cali);
    std::cout<<"Año de Serie: ";
    string anio;
    std::getline (std::cin,anio);
    setAnioLanzamiento(stoi(anio));
    std::cout<<"Número de temporadas: ";
    string noTemps;
    std::getline (std::cin,noTemps);
    noTemporadas=stoi(noTemps);
}

void Serie::agregaCapitulo(Capitulo cap){
    capitulos.push_back(cap);
}

void Serie::muestraCapitulos(string cali)const{
    if (cali=="all"){
        for (int i = 0; i < capitulos.size(); i++){
            std::cout<<"Capitulo "<<i+1<<":\n";
            std::cout<<capitulos[i]<<std::endl; //sobrecaraga de operadores
            std::cout<<"-------------\n";
            }
    }
    else{
        int cont=0;
         for (int i = 0; i < capitulos.size(); i++){
            if (capitulos[i].getCalificacion()==cali){
                std::cout<<"Capitulo:\n";
                std::cout<<capitulos[i]<<std::endl; //sobrecaraga de operadores
                std::cout<<"-------------\n";
                cont+=1;
            }
        }
        //manejo de excepciones
        if (cont==0){
            throw std::out_of_range(cali + " inválido, no hay capitulos con esa calificación"); 
        }
    }
}
void::Serie::mostrarCalificacionesCapitulos()const{
    std::vector<string> calificacionesTotales; 
     string actual;
            
            for (int i = 0; i < capitulos.size(); i++){
                actual=capitulos[i].getCalificacion();
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
void Serie::sortChapter(Capitulo cap){
    if (cap.getID()==getID()){
        agregaCapitulo(cap);
    }
    
}

#endif