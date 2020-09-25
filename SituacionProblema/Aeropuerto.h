#include <string>
#include <vector>
#include "Aerolinea.h"
using std::string;
using std::vector;

class Aeropuerto{
    //atributes
    private:
    string id, ciudad;
    vector<Aerolinea> aerolineas;
    public:
    //constructors
    Aeropuerto();
    //with arguments id,ciudad,aerolineas
    Aeropuerto(string const&,string const&,vector<Aerolinea> const&);
    //getters and setters
    string getId();
    string getCiudad();
    vector<Aerolinea> getAerolineas();
    void setId(string const&);
    void setCiudad(string const&);
    void setAerolineas(vector<Aerolinea> const&);
};
