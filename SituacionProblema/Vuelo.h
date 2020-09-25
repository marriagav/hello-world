#include <string>
#include <vector>
#include "Pasajero.h"
using std::string;
using std::vector;

class Vuelo{
    //atributes
    private:
    string desde,hasta,fecha,codigoDeVuelo;
    float precio,distancia;
    vector<Pasajero> pasajeros;
    int hora;
    public:
    //constructors
    Vuelo();
    //with arguments desde,hasta,precio,distancia,pasajeros,fecha,hora
    Vuelo(string const&,string const&,float const&,float const&,vector<Pasajero> const&,string const&,int const&);
    //getters and setters
    string getDesde();
    string getHasta();
    float getPrecio();
    float getDistancia();
    vector<Pasajero> getPasajeros();
    string getFecha();
    int getHora();
    string getCodigoDeVuelo();
    void setDesde(string const&);
    void setHasta(string const&);
    void setPrecio(float const&);
    void setDistancia(float const&);
    void setPasajeros(vector<Pasajero> const&);
    void setFecha(string const&);
    void setHora(int const&);
    void setCodigoDeVuelo(string const&);
};
