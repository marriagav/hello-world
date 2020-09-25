#include <string>
#include <vector>
#include "Aeropuerto.h"
using std::string;
using std::vector;

class Sistema{
    //atributes
    private:
    vector<Aeropuerto> aereopuertos;
    vectror<Usuario> usuarios;
    public:
    //constructors
    Sistema();
    //with arguments aereopuertos
    Sistema(vector<Aeropuerto> const&);
    //getters and setters
    vector<Aeropuerto> getAeropuertos();
    void setAeropuertos(vector<Aeropuerto> const&);
    vector<Usuario> getUsuarios();
    //Other methods
    void agregarUsuario();
    void cobrar(int const&); //argumento: suma de kilometros
};
