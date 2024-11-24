#pragma once
#include "../../../Funciones/idRandom.hpp"
using namespace std;

class Libro {
    private:
        string titulo, autor, isbn, categoria;
        int anio;
        bool disponible;
    public:
        Libro();
        Libro(string, string, string, int);

        void setTitulo(string);
        void setAutor(string);
        void setAnio(int);
        void setCategoria(string);
        void setIsbn(string);

        string getTitulo()const;
        string getAutor()const;
        string getCategoria()const;
        string getIsbn()const;
        int getAnio()const;
        bool getDisponible()const;

        void muestraDatos()const;
        void marcarDisponible();
        void marcarNoDisponible();
};

//Constructor
Libro::Libro() {
    titulo = "Sin titulo";
    autor = "Sin autor";
    categoria = "Sin categoria";
    anio = 0;
    disponible = true;
    isbn = generarID(11);
}
Libro::Libro(string _titulo, string _autor, string _categoria, int _anio) {
    titulo = _titulo;
    autor = _autor;
    anio = _anio;
    categoria = _categoria;
    disponible = true;
    isbn = generarID(11);
}

//Setters
void Libro::setTitulo(string _titulo) {
    titulo = _titulo;
}
void Libro::setAutor(string _autor) {
    autor = _autor;
}
void Libro::setAnio(int _anio) {
    anio = _anio;
}
void Libro::setCategoria(string _categoria) {
    categoria = _categoria;
}
void Libro::setIsbn(string _isbn) {
    isbn = _isbn;
}

//Getters
string Libro::getTitulo()const {
    return titulo;
}
string Libro::getAutor()const {
    return autor;
}
string Libro::getCategoria()const {
    return categoria;
}
string Libro::getIsbn()const {
    return isbn;
}
int Libro::getAnio()const {
    return anio;
}
bool Libro::getDisponible()const {
    return disponible;
}

//Metodos
void Libro::muestraDatos()const {
    cout << "Titulo: " << titulo << endl;
    cout << "Autor: " << autor << endl;
    cout << "Categoria: " << categoria << endl;
    cout << "Anio: " << anio << endl;
    cout << "Disponible: " << (disponible ? "Si" : "No") << endl;
    cout << "ISBN: " << isbn << endl;
}
void Libro::marcarDisponible() {
    disponible = true;
}
void Libro::marcarNoDisponible() {
    disponible = false;
}