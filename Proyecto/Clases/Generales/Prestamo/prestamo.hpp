#pragma once
#include <iostream>
#include "../Libro/libro.hpp"
#include "../Usuario/usuario.hpp"
#include "../Fecha/fecha.hpp"
#include "../Sancion/sancion.hpp"
#include "../../Contenedoras/GestorSanciones/sanciones.hpp"
#include "../../../Funciones/idRandom.hpp"

using namespace std;

class Prestamo {
    private:
        string idLibro, idUsuario, fechaPrestamo, fechaDevolucion, fechaLimite;
        string idPrestamo;

    public:
        Prestamo();
        Prestamo(const string& idLibro, const string& idUsuario);
        ~Prestamo();

        string getLibro() const;
        string getUsuario() const;
        string getFechaPrestamo() const;
        string getFechaDevolucion() const;
        string getFechaLimite() const;
        string getIdPrestamo() const;

        void setLibro(const string& idLibro);
        void setUsuario(const string& idUsuario);
        void setFechaPrestamo(const string& fechaPrestamo);
        void setFechaDevolucion(const string& fechaDevolucion);
        void setFechaLimite(const string& fechaLimite);
        void setIdPrestamo(const string& idPrestamo);

        void mostrarDatos() const;
        void registrarDevolucion();

        bool estaAtrasado() const;
        bool esActivo() const;
};

// Constructor
Prestamo::Prestamo() {
    this->idPrestamo = generarID(9);
}

Prestamo::Prestamo(const string& idLibro, const string& idUsuario) {
    Fecha hoy;
    hoy.setFechaActual();
    this->idLibro = idLibro;
    this->idUsuario = idUsuario;
    this->fechaPrestamo = hoy.fechaString();
    hoy.sumarDias(15);
    this->fechaLimite = hoy.fechaString();
    this->idPrestamo = generarID(9);
}

// Destructor
Prestamo::~Prestamo() {}

// Getters
string Prestamo::getLibro() const {
    return idLibro;
}

string Prestamo::getUsuario() const {
    return idUsuario;
}

string Prestamo::getFechaPrestamo() const {
    return fechaPrestamo;
}

string Prestamo::getFechaDevolucion() const {
    return fechaDevolucion;
}

string Prestamo::getFechaLimite() const {
    return fechaLimite;
}

string Prestamo::getIdPrestamo() const {
    return idPrestamo;
}

// Setters
void Prestamo::setLibro(const string& idLibro) {
    this->idLibro = idLibro;
}

void Prestamo::setUsuario(const string& idUsuario) {
    this->idUsuario = idUsuario;
}

void Prestamo::setFechaPrestamo(const string& fechaPrestamo) {
    this->fechaPrestamo = fechaPrestamo;
}

void Prestamo::setFechaDevolucion(const string& fechaDevolucion) {
    this->fechaDevolucion = fechaDevolucion;
}

void Prestamo::setFechaLimite(const string& fechaLimite) {
    this->fechaLimite = fechaLimite;
}

void Prestamo::setIdPrestamo(const string& idPrestamo) {
    this->idPrestamo = idPrestamo;
}

// Métodos
void Prestamo::mostrarDatos() const {
    cout << "ID Libro: " << idLibro << endl;
    cout << "ID Usuario: " << idUsuario << endl;
    cout << "Fecha de Prestamo: " << fechaPrestamo << endl;
    cout << "Fecha de Devolucion: " << (fechaDevolucion == "" ? "Sin devolver" : fechaDevolucion) << endl;
    cout << "Fecha Limite: " << fechaLimite << endl;
}

void Prestamo::registrarDevolucion() {
    Fecha hoy;
    hoy.setFechaActual();
    fechaDevolucion = hoy.fechaString();
}

bool Prestamo::estaAtrasado() const {
    Fecha hoy, fechaLimiteN(fechaLimite);
    hoy.setFechaActual();
    return fechaLimiteN < hoy;
}

bool Prestamo::esActivo() const {
    if(fechaDevolucion == "") {
        return true;
    }else {
        return false;
    }
}