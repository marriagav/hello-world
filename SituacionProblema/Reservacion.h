#include <string>
using std::string;

class Reservacion{
    //atributes
    private:
    int numeroDePersonas;
    string nombres;
    public:
    //constructors
    Reservacion();
    //with arguments numero de personas,nombres
    Reservacion(int const&,string const&);
    //getters and setters
    string getNombres();
    int getNumeroDePersonas();
    void setNombres(string const&);
    void setnumeroDePersonas(int const&);
    //Other methods 
    void cancelarVuelo();
};
