#pragma once
#include "../../../Funciones/idRandom.hpp"
#include<vector>

using namespace std;

class Usuario{
    protected:
        string nombre,idUsuario,correo,telefono;
        int cuentaBancaria, limitePrestamos, prestamosActuales;
        bool sancionado;
    public:
        Usuario();
        Usuario(string,string,string,int);
        ~Usuario();

        string getNombre()const;
        string getIdUsuario()const;
        string getCorreo()const;
        string getTelefono()const;
        int getCuentaBancaria()const;
        int getLimitePrestamos()const;
        bool getSanciones()const;
        int getPrestamosActuales()const;

        void setNombre(string);
        void setCorreo(string);
        void setTelefono(string);
        void setCuentaBancaria(int);
        void setIDUsuario(string);

        virtual void mostrarDatos()const;
        void agregarPrestamo();
};

//Constructor
Usuario::Usuario(){
    nombre = "";
    idUsuario = generarID(12);
    correo = "";
    telefono = "";
    cuentaBancaria = 0;
    limitePrestamos = 2;
}
Usuario::Usuario(string nombre,string correo,string telefono,int cuentaBancaria){
    this->nombre = nombre;
    this->idUsuario = generarID(12);
    this->correo = correo;
    this->telefono = telefono;
    this->cuentaBancaria = cuentaBancaria;
    this->limitePrestamos = 2;
}
//Destructor
Usuario::~Usuario(){}

//Getters
string Usuario::getNombre()const{
    return nombre;
}
string Usuario::getIdUsuario()const{
    return idUsuario;
}
string Usuario::getCorreo()const{
    return correo;
}
string Usuario::getTelefono()const{
    return telefono;
}
int Usuario::getCuentaBancaria()const{
    return cuentaBancaria;
}
int Usuario::getLimitePrestamos()const{
    return limitePrestamos;
}
bool Usuario::getSanciones()const{
    if(sancionado){
        return true;
    }
    return false;
}
int Usuario::getPrestamosActuales()const{
    return prestamosActuales;
}

//Setters
void Usuario::setNombre(string nombre){
    this->nombre = nombre;
}
void Usuario::setCorreo(string correo){
    this->correo = correo;
}
void Usuario::setTelefono(string telefono){
    this->telefono = telefono;
}
void Usuario::setCuentaBancaria(int cuentaBancaria){
    this->cuentaBancaria = cuentaBancaria;
}
void Usuario::setIDUsuario(string idUsuario){
    if(idUsuario.size() == 12){
        this->idUsuario = idUsuario;
    }
}

//Metodos
void Usuario::mostrarDatos()const{
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Id Usuario: "<<idUsuario<<endl;
    cout<<"Correo: "<<correo<<endl;
    cout<<"Telefono: "<<telefono<<endl;
    cout<<"Cuenta Bancaria: "<<(cuentaBancaria != 0 ? to_string(cuentaBancaria) : "Sin registro")<<endl;
    cout<<"Limite de prestamos: "<<(limitePrestamos == 0 ? "No puede realizar prestamos" : to_string(limitePrestamos))<<endl;
}

void Usuario::agregarPrestamo(){
    prestamosActuales++;
}