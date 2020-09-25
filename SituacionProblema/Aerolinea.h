#include <string>
#include <vector>
#include "Avion.h"
using std::string;
using std::vector;

class Aerolinea{
    //atributes
    private:
    string abreviatura,hub;
    vector<Avion> aviones;
    public:
    //constructors
    Aerolinea();
    //with arguments abreviatura,hub, aviones
    Aerolinea(string const&,string const&, vector<Avion> const&);
    //getters and setters
    string getAbreviatura();
    string getHub();
    vector<Avion> getAviones();
    void setAbreviatura(string const&);
    void setHub(string const&);
    void setAviones(vector<Avion> const&);
};
