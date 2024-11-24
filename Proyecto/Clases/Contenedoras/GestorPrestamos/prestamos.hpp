#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "../../Generales/Prestamo/prestamo.hpp"

using namespace std;

class GestorPrestamos {
    private:
        vector<Prestamo> prestamos;

    public:
        GestorPrestamos();
        ~GestorPrestamos();

        void agregarPrestamo(const Prestamo& prestamo);
        string finalizarPrestamo(const string& idUsuario, const string& isbn);
        void mostrarPrestamos() const;

        bool verificarSancion(const string& idPrestamo);
        void buscarPorUsuario(const string& idUsuario) const;
        void buscarPorIsbn(const string& isbn) const;

        void mostrarPrestamosActivos() const;
        void mostrarPrestamosAtrasados() const; //No devuelto

        Sancion aplicarSancion(const string& idPrestamo);
};

// Constructor
GestorPrestamos::GestorPrestamos(){
    ifstream archivoEntrada("/Users/mikitl/Documents/FES/POO/Proyecto/Archivos/Prestamos.bin", ios::binary);
    if (!archivoEntrada) {
        cerr << "No se encontró el archivo de prestamos o no se pudo abrir. Iniciando con lista vacía." << endl;
        return;
    }

    size_t cantidad;
    archivoEntrada.read(reinterpret_cast<char*>(&cantidad), sizeof(cantidad));

    for (size_t i = 0; i < cantidad; ++i) {
        Prestamo prestamo;  // Crear una instancia de Prestamo

        size_t size;
        archivoEntrada.read(reinterpret_cast<char*>(&size), sizeof(size));
        string buffer(size, '\0');
        archivoEntrada.read(&buffer[0], size);

        // Leer y asignar ID del usuario
        prestamo.setUsuario(buffer);

        // Leer y asignar ISBN del libro
        archivoEntrada.read(reinterpret_cast<char*>(&size), sizeof(size));
        buffer.resize(size);
        archivoEntrada.read(&buffer[0], size);
        prestamo.setLibro(buffer);

        // Leer y asignar fecha de prestamo
        archivoEntrada.read(reinterpret_cast<char*>(&size), sizeof(size));
        buffer.resize(size);
        archivoEntrada.read(&buffer[0], size);
        prestamo.setFechaPrestamo(buffer);

        // Leer y asignar fecha de devolución
        archivoEntrada.read(reinterpret_cast<char*>(&size), sizeof(size));
        buffer.resize(size);
        archivoEntrada.read(&buffer[0], size);
        prestamo.setFechaDevolucion(buffer);

        // Leer y asignar fecha limite
        archivoEntrada.read(reinterpret_cast<char*>(&size), sizeof(size));
        buffer.resize(size);
        archivoEntrada.read(&buffer[0], size);
        prestamo.setFechaLimite(buffer);

        // Leer y asignar ID del prestamo
        archivoEntrada.read(reinterpret_cast<char*>(&size), sizeof(size));
        buffer.resize(size);
        archivoEntrada.read(&buffer[0], size);
        prestamo.setIdPrestamo(buffer);

        prestamos.push_back(prestamo);
    }

    archivoEntrada.close();
}

GestorPrestamos::~GestorPrestamos(){
    ofstream archivoSalida("/Users/mikitl/Documents/FES/POO/Proyecto/Archivos/Prestamos.bin", ios::binary);
    if (!archivoSalida) {
        cerr << "Error al abrir el archivo binario para guardar prestamos." << endl;
        return;
    }

    // Guardar la cantidad de prestamos
    size_t cantidad = prestamos.size();
    archivoSalida.write(reinterpret_cast<const char*>(&cantidad), sizeof(cantidad));

    // Guardar cada prestamo completo
    for (const auto& prestamo : prestamos) {
        size_t size;
        string data;

        // Guardar ID del usuario
        data = prestamo.getUsuario();
        size = data.size();
        archivoSalida.write(reinterpret_cast<const char*>(&size), sizeof(size));
        archivoSalida.write(data.c_str(), size);

        // Guardar ISBN del libro
        data = prestamo.getLibro();
        size = data.size();
        archivoSalida.write(reinterpret_cast<const char*>(&size), sizeof(size));
        archivoSalida.write(data.c_str(), size);

        // Guardar fecha de prestamo
        data = prestamo.getFechaPrestamo();
        size = data.size();
        archivoSalida.write(reinterpret_cast<const char*>(&size), sizeof(size));
        archivoSalida.write(data.c_str(), size);

        // Guardar fecha de devolución
        data = prestamo.getFechaDevolucion();
        size = data.size();
        archivoSalida.write(reinterpret_cast<const char*>(&size), sizeof(size));
        archivoSalida.write(data.c_str(), size);

        // Guardar fecha limite
        data = prestamo.getFechaLimite();
        size = data.size();
        archivoSalida.write(reinterpret_cast<const char*>(&size), sizeof(size));
        archivoSalida.write(data.c_str(), size);

        // Guardar ID del prestamo
        data = prestamo.getIdPrestamo();
        size = data.size();
        archivoSalida.write(reinterpret_cast<const char*>(&size), sizeof(size));
        archivoSalida.write(data.c_str(), size);

    }

    archivoSalida.close();
}

// Métodos
void GestorPrestamos::agregarPrestamo(const Prestamo& prestamo) {
    prestamos.push_back(prestamo);
}

string GestorPrestamos::finalizarPrestamo(const string& idUsuario, const string& isbn) {
    for (size_t i = 0; i < prestamos.size(); ++i) {
        if (prestamos[i].getUsuario() == idUsuario && prestamos[i].getLibro() == isbn) {
            prestamos[i].registrarDevolucion();
            prestamos.erase(prestamos.begin() + i);
            cout << "Prestamo finalizado con exito" << endl;
            return prestamos[i].getIdPrestamo();
        }
    }
    cout << "No se encontro el prestamo" << endl;
    return "";
}

void GestorPrestamos::mostrarPrestamos() const {
    if(prestamos.empty()){
        cout << "No hay prestamos registrados" << endl;
        return;
    }
    for (int i = 0; i < prestamos.size(); ++i) {
        cout << "Prestamo " << i + 1 << ":" << endl;
        prestamos[i].mostrarDatos();
        cout << endl;
    }
}

void GestorPrestamos::buscarPorUsuario(const string& idUsuario) const {
    for (int i = 0; i < prestamos.size(); ++i) {
        if (prestamos[i].getUsuario() == idUsuario) {
            prestamos[i].mostrarDatos();
        }
    }
}

void GestorPrestamos::buscarPorIsbn(const string& isbn) const {
    for (int i = 0; i < prestamos.size(); ++i) {
        if (prestamos[i].getLibro() == isbn) {
            prestamos[i].mostrarDatos();
        }
    }
}

void GestorPrestamos::mostrarPrestamosActivos() const {
    Fecha actual;
    actual.setFechaActual();
    cout << "Prestamos activos:" << endl;
    for (int i = 0; i < prestamos.size(); ++i) {
        if (prestamos[i].esActivo()) {
            cout << "Prestamo " << i + 1 << ":" << endl;
            prestamos[i].mostrarDatos();
            cout << endl;
        }
    }
}

void GestorPrestamos::mostrarPrestamosAtrasados() const {
    cout << "Prestamos atrasados:" << endl;
    for (int i = 0; i < prestamos.size(); ++i) {
        if (prestamos[i].estaAtrasado()) {
            cout << "Prestamo " << i + 1 << ":" << endl;
            prestamos[i].mostrarDatos();
            cout << endl;
        }
    }
}

bool GestorPrestamos::verificarSancion(const string& idPrestamo) {
    for (int i = 0; i < prestamos.size(); ++i) {
        if(prestamos[i].getIdPrestamo() == idPrestamo){
            Fecha hoy;
            hoy.setFechaActual();
            Fecha fechaLimite(prestamos[i].getFechaLimite());
            if (fechaLimite < hoy) {
                return true;
            }
        }
    }
    return false;
}

Sancion GestorPrestamos::aplicarSancion(const string& idPrestamo) {
    for (int i = 0; i < prestamos.size(); ++i) {
        if(prestamos[i].getIdPrestamo() == idPrestamo){
            Fecha hoy;
            hoy.setFechaActual();
            Fecha fechaLimite(prestamos[i].getFechaLimite());
            int diasRetraso = fechaLimite.diasDiferecia(hoy);
            Sancion sancion(22.37*diasRetraso, "Retraso de "+to_string(diasRetraso)+"dias de retraso.", prestamos[i].getUsuario());
            return sancion;
        }
    }
    Sancion sancion;
    return sancion;
}