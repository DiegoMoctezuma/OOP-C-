#pragma once
#include<iostream>
#include"./usuario.hpp"
#include"../Fecha/fecha.hpp"

using namespace std;

class Invitado:public Usuario{
    private:
        Fecha fechaExpiracion;
    public:
        Invitado();
        Invitado(string,string,string);
        ~Invitado();

        Fecha getFechaExpiracion()const;

        void setFechaExpiracion(Fecha);

        void mostrarDatos()const;
        bool esActivo()const;
};

//Constructor
Invitado::Invitado():Usuario(){
    this->fechaExpiracion.setFechaActual();
    this->fechaExpiracion.sumarDias(14);
    this->limitePrestamos = 0;
}
Invitado::Invitado(string nombre,string correo,string telefono):Usuario(nombre,correo,telefono,0){
    this->fechaExpiracion.setFechaActual();
    this->fechaExpiracion.setDia(this->fechaExpiracion.getDia()+7);
    this->limitePrestamos = 0;
}
//Destructor
Invitado::~Invitado(){}

//Getters
Fecha Invitado::getFechaExpiracion()const{
    return fechaExpiracion;
}
bool Invitado::esActivo()const{
    Fecha actual;
    if(fechaExpiracion < actual.getFechaActual()){
        return false;
    }
    return true;
}

//Setters
void Invitado::setFechaExpiracion(Fecha fechaExpiracion){
    this->fechaExpiracion = fechaExpiracion;
}

//Metodos
void Invitado::mostrarDatos()const{
    Usuario::mostrarDatos();
    cout<<"Fecha de Expiracion: "<<fechaExpiracion.fechaString()<<endl;
}