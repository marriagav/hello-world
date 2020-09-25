#include <string>
#include <vector>
#include "Vuelo.h"
using std::string;
using std::vector;

class Avion{
    //atributes
    private:
    string modelo;
    int gasolina,anio;
    vector<Vuelo> vuelos;
    public:
    //constructors
    Avion();
    //with arguments modelo,gasolina,anio,vuelos
    Avion(string const&,int const&,int const&,vector<Vuelo> const&);
    //getters and setters
    string getModelo();
    int getGasolina();
    int getAnio();
    vector<Vuelo> getVuelos();
    void setModelo(string const&);
    void setGasolina(int const&);
    void setAnio(int const&);
    void setVuelos(vector<Vuelo> const&);
    //Other methods
};
