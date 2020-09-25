#include <string>
using std::string;

class Usuario{
    //atributes
    private:
    string nombreCompleto, contrasenia, tarjetaDeCredito,direccion, mail;
    int telefono, sumaDeKilometros;
    vector<Reservacion> reservas;
    public:
    //constructors
    Usuario();
    //with arguments nombreCompleto, contrasenia, tarjetaDeCredito,direccion, mail, telefono, sumaDeKilometros
    Usuario(string const&,string const&,string const&,string const&,string const&,int const&,int const&);
    //getters and setters
    string getNombreCompleto();
    string getContrasenia();
    string getTarjetaDeCredito();
    string getDireccion();
    string getMail();
    int getTelefono();
    int getSumaDeKilometros();
    vector<Reservacion> getReservas();
    void setNombreCompleto(string const&);
    void setContrasenia(string const&);
    void setTarjetaDeCredito(string const&);
    void setDireccion(string const&);
    void setMail(string const&);
    void setTelefono(int const&);
    void setSumaDeKilometros(int const&);
    //Other methods
    void buscarVuelo(string const&); //argumento: termino de busqueda
    void ingresarSesion(string const&,string const&); //argumentos: usuario, contrasenia
    string mostrarDetallesDeVuelo(string const&); //argumento: codigo de vuelo
    void reservarVuelo();
};
