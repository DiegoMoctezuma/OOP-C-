#pragma once
#include <iostream>
#include<time.h>
using namespace std;

class Fecha{
    private:
        int dia,mes,anio;
    public:
        Fecha();
        Fecha(string);
        Fecha(int,int,int);
        ~Fecha();

        int getDia()const;
        int getMes()const;
        int getAnio()const;

        void setDia(int);
        void setMes(int);
        void setAnio(int);

        int diasDiferecia(Fecha)const;
        string fechaString()const;
        bool operator<(Fecha)const;

        Fecha getFechaActual()const;
        void setFechaActual();
        void sumarDias(int);
};

//Constructor
Fecha::Fecha(){
    dia = 0;
    mes = 0;
    anio = 0;
}
Fecha::Fecha(string fechaInString){
    string dia = "",mes = "",anio = "";
    int i = 0;
    while(fechaInString[i] != '/'){
        dia += fechaInString[i];
        i++;
    }
    i++;
    while(fechaInString[i] != '/'){
        mes += fechaInString[i];
        i++;
    }
    i++;
    while(i < fechaInString.size()){
        anio += fechaInString[i];
        i++;
    }
    this->dia = stoi(dia);
    this->mes = stoi(mes);
    this->anio = stoi(anio);
}
Fecha::Fecha(int dia,int mes,int anio){
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}
//Destructor
Fecha::~Fecha(){}

//Getters
int Fecha::getDia()const{
    return dia;
}
int Fecha::getMes()const{
    return mes;
}
int Fecha::getAnio()const{
    return anio;
}

//Setters
void Fecha::setDia(int dia){
    this->dia = dia;
}
void Fecha::setMes(int mes){
    this->mes = mes;
}
void Fecha::setAnio(int anio){
    this->anio = anio;
}

//Metodos
int Fecha::diasDiferecia(Fecha fecha)const{
    int dias = 0;
    if(fecha.anio == anio){
        if(fecha.mes == mes){
            dias = fecha.dia - dia;
        }else{
            dias = (30 - dia) + fecha.dia;
        }
    }else{
        dias = (30 - dia) + fecha.dia;
        dias += (fecha.mes - mes - 1) * 30;
        dias += (fecha.anio - anio) * 365;
    }
    return dias;
}
string Fecha::fechaString()const{
    return to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
}

//Sobrecarga de operadores
bool Fecha::operator<(Fecha fecha)const{
    if(anio < fecha.anio){
        return true;
    }else if(anio == fecha.anio){
        if(mes < fecha.mes){
            return true;
        }else if(mes == fecha.mes){
            if(dia < fecha.dia){
                return true;
            }
        }
    }
    return false;
}

Fecha Fecha::getFechaActual()const{
    time_t t = time(0);
    struct tm *tiempo = localtime(&t);
    return Fecha(tiempo->tm_mday,tiempo->tm_mon + 1,tiempo->tm_year + 1900);
}

void Fecha::setFechaActual(){
    time_t t = time(0);
    struct tm *tiempo = localtime(&t);
    this->dia = tiempo->tm_mday;
    this->mes = tiempo->tm_mon + 1;
    this->anio = tiempo->tm_year + 1900;
}

void Fecha::sumarDias(int dias){
    for(int i = 0; i < dias; i++){
        if(dia == 30){
            dia = 1;
            if(mes == 12){
                mes = 1;
                anio++;
            }else{
                mes++;
            }
        }else{
            dia++;
        }
    }
}