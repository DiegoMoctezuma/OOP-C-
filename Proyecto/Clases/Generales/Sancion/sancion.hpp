#pragma once
#include "../../../Funciones/idRandom.hpp"
#include"../Fecha/fecha.hpp"

using namespace std;

class Sancion{
    private:
        float costo;
        string descripcion,id, idUsuario,fechaSancion,fechaPago;
        bool estado;
    public:
        Sancion();
        Sancion(float, string, string);

        void setCosto(float);
        void setDescripcion(string);
        void setFechaSancion(string);
        void setFechaPago(string);
        void setEstado(bool);
        void setIdUsuario(string);
        void setId(string);

        float getCosto()const;
        string getDescripcion()const;
        string getFechaSancion()const;
        string getFechaPago()const;
        string getId()const;
        string getIdUsuario()const;
        bool getEstado()const;

        void muestraDatos()const;
        void marcarPagado();
};

//Constructor
Sancion::Sancion(){
    this->costo = 0;
    this->descripcion = "Sin descripcion";
    this->estado = false;
    this->id = generarID(10);
}
Sancion::Sancion(float _costo, string _descripcion, string idU){
    this->costo = _costo;
    this->descripcion = _descripcion;
    Fecha fechaSancion;
    fechaSancion.setFechaActual();
    this->fechaSancion = fechaSancion.fechaString();
    this->estado = false;
    this->id = generarID(10);
    this->idUsuario = idU;
}

//Setters
void Sancion::setCosto(float _costo){
    costo = _costo;
}
void Sancion::setDescripcion(string _descripcion){
    descripcion = _descripcion;
}
void Sancion::setFechaSancion(string _fechaSancion){
    fechaSancion = _fechaSancion;
}
void Sancion::setFechaPago(string _fechaPago){
    fechaPago = _fechaPago;
}
void Sancion::setEstado(bool _estado){
    estado = _estado;
}
void Sancion::setIdUsuario(string _idUsuario){
    idUsuario = _idUsuario;
}
void Sancion::setId(string _id){
    id = _id;
}

//Getters
float Sancion::getCosto()const{
    return costo;
}
string Sancion::getDescripcion()const{
    return descripcion;
}
string Sancion::getFechaSancion()const{
    return fechaSancion;
}
string Sancion::getFechaPago()const{
    return fechaPago;
}
bool Sancion::getEstado()const{
    return estado;
}
string Sancion::getId()const{
    return id;
}
string Sancion::getIdUsuario()const{
    return idUsuario;
}

//Metodos
void Sancion::muestraDatos()const{
    cout << "Costo: " << costo << endl;
    cout << "Descripcion: " << descripcion << endl;
    cout << "Fecha de sancion: " << fechaSancion << endl;
    cout << "Estado: " << (estado?"Pagada":"Sin pagar") << endl;
}
void Sancion::marcarPagado(){
    estado = true;
    Fecha fechaPago;
    fechaPago.setFechaActual();
    this->fechaPago = fechaPago.fechaString();
}