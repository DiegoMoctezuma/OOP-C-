#pragma once
#include<vector>
#include <fstream>
#include"../../Generales/Libro/libro.hpp"

class CatalogoLibros{
    private:
        vector<Libro> libros;
    public:
        CatalogoLibros();
        ~CatalogoLibros();

        void agregarLibro(Libro);
        void eliminarLibro(string);
        void mostrarLibros()const;
        void buscarPorTitulo(string)const;
        void buscarPorAutor(string)const;
        void buscarPorCategoria(string)const;
        void buscarPorIsbn(string)const;
        void listarDisponibles()const;

        void marcarDisponible(string);
        void marcarNoDisponible(string);

        bool existeLibro(string)const;
        bool estaDisponible(string)const;
};

//Constructor
CatalogoLibros::CatalogoLibros(){
    ifstream archivoEntrada("/Users/mikitl/Documents/FES/POO/Proyecto/Archivos/Libros.bin", ios::binary);
    if (!archivoEntrada) {
        cerr << "No se encontró el archivo de libros o no se pudo abrir. Iniciando con lista vacía." << endl;
        return;
    }

    size_t cantidad;
    archivoEntrada.read(reinterpret_cast<char*>(&cantidad), sizeof(cantidad));

    for (size_t i = 0; i < cantidad; ++i) {
        Libro libro;  // Crear una instancia de Libro

        size_t size;
        char buffer[1024];

        // Leer y asignar título
        archivoEntrada.read(reinterpret_cast<char*>(&size), sizeof(size));
        archivoEntrada.read(buffer, size);
        libro.setTitulo(string(buffer, size));

        // Leer y asignar autor
        archivoEntrada.read(reinterpret_cast<char*>(&size), sizeof(size));
        archivoEntrada.read(buffer, size);
        libro.setAutor(string(buffer, size));

        // Leer y asignar categoría
        archivoEntrada.read(reinterpret_cast<char*>(&size), sizeof(size));
        archivoEntrada.read(buffer, size);
        libro.setCategoria(string(buffer, size));

        // Leer y asignar ISBN
        archivoEntrada.read(reinterpret_cast<char*>(&size), sizeof(size));
        archivoEntrada.read(buffer, size);
        libro.setIsbn(string(buffer, size));

        // Leer y asignar año de publicación
        int anioPublicacion;
        archivoEntrada.read(reinterpret_cast<char*>(&anioPublicacion), sizeof(anioPublicacion));
        libro.setAnio(anioPublicacion);

        //Leer y asignar disponibilidad
        bool disponible;
        archivoEntrada.read(reinterpret_cast<char*>(&disponible), sizeof(disponible));
        if(disponible){
            libro.marcarDisponible();
        }else{
            libro.marcarNoDisponible();
        }

        // Agregar el libro al vector
        libros.push_back(libro);
    }
}

CatalogoLibros::~CatalogoLibros(){
    ofstream archivoSalida("/Users/mikitl/Documents/FES/POO/Proyecto/Archivos/Libros.bin", ios::binary);
    if (!archivoSalida) {
        cerr << "Error al abrir el archivo binario para guardar invitados." << endl;
        return;
    }

    // Guardar la cantidad de invitados
    size_t cantidad = libros.size();
    archivoSalida.write(reinterpret_cast<const char*>(&cantidad), sizeof(cantidad));

    // Guardar cada libro completo
    for (const auto& libro : libros) {
        size_t size;
        string data;

        // Guardar título
        data = libro.getTitulo();
        size = data.size();
        archivoSalida.write(reinterpret_cast<const char*>(&size), sizeof(size));
        archivoSalida.write(data.c_str(), size);

        // Guardar autor
        data = libro.getAutor();
        size = data.size();
        archivoSalida.write(reinterpret_cast<const char*>(&size), sizeof(size));
        archivoSalida.write(data.c_str(), size);

        // Guardar categoría
        data = libro.getCategoria();
        size = data.size();
        archivoSalida.write(reinterpret_cast<const char*>(&size), sizeof(size));
        archivoSalida.write(data.c_str(), size);

        // Guardar ISBN
        data = libro.getIsbn();
        size = data.size();
        archivoSalida.write(reinterpret_cast<const char*>(&size), sizeof(size));
        archivoSalida.write(data.c_str(), size);

        // Guardar año de publicación
        int anioPublicacion = libro.getAnio();
        archivoSalida.write(reinterpret_cast<const char*>(&anioPublicacion), sizeof(anioPublicacion));

        // Guardar disponibilidad
        bool disponible = libro.getDisponible();
        archivoSalida.write(reinterpret_cast<const char*>(&disponible), sizeof(disponible));
    }

    archivoSalida.close();
}


void CatalogoLibros::agregarLibro(Libro libro){
    libros.push_back(libro);
}

void CatalogoLibros::eliminarLibro(string isbn){
    bool encontrado = false;
    for(int i = 0; i < libros.size(); i++){
        if(libros[i].getIsbn() == isbn){
            libros.erase(libros.begin()+i);
            cout<<"Libro eliminado con éxito."<<endl;
            encontrado = true;
        }
    }
    if(!encontrado){
        cout<<"No se encontró el libro con el ISBN: "<<isbn<<endl;
    }
}

void CatalogoLibros::mostrarLibros()const{
    for(int i = 0; i < libros.size(); i++){
        cout<<i+1<<".-:"<<endl;
        libros[i].muestraDatos();
        cout<<endl;
    }
}

void CatalogoLibros::buscarPorTitulo(string titulo)const{
    for(int i = 0; i < libros.size(); i++){
        if(libros[i].getTitulo() == titulo){
            libros[i].muestraDatos();
        }
    }
}

void CatalogoLibros::buscarPorAutor(string autor)const{
    for(int i = 0; i < libros.size(); i++){
        if(libros[i].getAutor() == autor){
            libros[i].muestraDatos();
        }
    }
}

void CatalogoLibros::buscarPorCategoria(string categoria)const{
    for(int i = 0; i < libros.size(); i++){
        if(libros[i].getCategoria() == categoria){
            libros[i].muestraDatos();
        }
    }
}

void CatalogoLibros::buscarPorIsbn(string isbn)const{
    bool encontrado = false;
    for(int i = 0; i < libros.size(); i++){
        if(libros[i].getIsbn() == isbn){
            libros[i].muestraDatos();
            encontrado = true;
        }
    }
    if(!encontrado){
        cout<<"No se encontró el libro con el ISBN: "<<isbn<<endl;
    }
}

void CatalogoLibros::listarDisponibles()const{
    if(libros.size() == 0){
        cout<<"No hay libros en el catálogo"<<endl;
        return;
    }
    for(int i = 0; i < libros.size(); i++){
        if(libros[i].getDisponible()){
            cout<<i+1<<".-:"<<endl;
            libros[i].muestraDatos();
            cout<<endl;
        }
    }
}

void CatalogoLibros::marcarDisponible(string isbn){
    for(int i = 0; i < libros.size(); i++){
        if(libros[i].getIsbn() == isbn){
            libros[i].marcarDisponible();
        }
    }
}

void CatalogoLibros::marcarNoDisponible(string isbn){
    for(int i = 0; i < libros.size(); i++){
        if(libros[i].getIsbn() == isbn){
            libros[i].marcarNoDisponible();
        }
    }
}

bool CatalogoLibros::existeLibro(string isbn)const{
    for(int i = 0; i < libros.size(); i++){
        if(libros[i].getIsbn() == isbn){
            return true;
        }
    }
    return false;
}

bool CatalogoLibros::estaDisponible(string isbn)const{
    for(int i = 0; i < libros.size(); i++){
        if(libros[i].getIsbn() == isbn && libros[i].getDisponible()){
            return true;
        }
    }
    return false;
}