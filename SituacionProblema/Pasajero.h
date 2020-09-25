#include <string>
using std::string;

class Pasajero{
    //atributes
    private:
    string name;
    string seat;
    int phone;
    public:
    //constructors
    Pasajero();
    //with arguments name/seat/phone
    Pasajero(string const&,string const&,int const&);
    //getters and setters
    string getName();
    string getSeat();
    int getPhone();
    void setName(string const&);
    void setSeat(string const&);
    void setPhone(int const&);
};
