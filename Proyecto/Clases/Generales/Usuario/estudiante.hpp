#pragma once
#include<iostream>
#include"./usuario.hpp"

using namespace std;

class Estudiante:public Usuario{
    private:
        string institucion, matricula;
    public:
        Estudiante();
        Estudiante(string,string,string,int,string,string);
        ~Estudiante();

        string getInstitucion()const;
        string getMatricula()const;

        void setInstitucion(string);
        void setMatricula(string);

        void mostrarDatos()const;
};

//Constructor
Estudiante::Estudiante(){
    limitePrestamos = 0;
    institucion = "";
}
Estudiante::Estudiante(string nombre,string correo,string telefono,int cuentaBancaria,string institucion, string matricula):Usuario(nombre,correo,telefono,cuentaBancaria){
    this->limitePrestamos+=3;
    this->institucion = institucion;
    this->matricula = matricula;
}
//Destructor
Estudiante::~Estudiante(){}

//Getters
string Estudiante::getInstitucion()const{
    return institucion;
}
string Estudiante::getMatricula()const{
    return matricula;
}

//Setters
void Estudiante::setInstitucion(string institucion){
    this->institucion = institucion;
}
void Estudiante::setMatricula(string matricula){
    this->matricula = matricula;
}

//Metodos
void Estudiante::mostrarDatos()const{
    Usuario::mostrarDatos();
    cout<<"Matricula: "<<matricula<<endl;
    cout<<"Institucion: "<<institucion<<endl;
}