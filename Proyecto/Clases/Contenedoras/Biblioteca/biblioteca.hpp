#pragma once
#include"../CatalogoLibros/catalogo.hpp"
#include"../GestorUsuarios/gestorUsuarios.hpp"
#include"../GestorUsuarios/gestorInvitados.hpp"
#include"../GestorUsuarios/gestorEstudiantes.hpp"
#include"../GestorPrestamos/prestamos.hpp"
#include"../GestorSanciones/sanciones.hpp"
#include <iostream>
#include <string>

using namespace std;

class Biblioteca{
    private:
        CatalogoLibros catalogoLibros;
        GestorUsuarios gestorUsuarios;
        GestorInvitados gestorInvitados;
        GestorEstudiantes gestorEstudiantes;
        GestorPrestamos gestorPrestamos;
        GestorSanciones gestorSanciones;
    public:
        // Métodos relacionados con usuarios
        void registrarUsuario();
        void eliminarUsuario(const string& idUsuario);
        void buscarUsuario(const string& idUsuario);
        void listarUsuarios();

        // Métodos relacionados con el catálogo de libros
        void agregarLibro();
        void eliminarLibro(const string& isbn);
        void buscarLibro(const string& isbn);
        void listarLibros();
        void listarLibrosDisponibles();

        // Métodos relacionados con préstamos
        bool realizarPrestamo(const string& idUsuario, const string& isbn);
        bool devolverLibro(const string& idUsuario, const string& isbn);
        void listarPrestamosActivos();

        // Métodos relacionados con sanciones
        void registrarSancion();
        void sancionesUsuario(const string& idUsuario);
        void consultarSanciones();
        void sancionesPendientes();

        // Métodos de informes y estadísticas
        void generarInformeUsuarios();   // Usuarios registrados y activos
        void generarInformeLibros();     // Estado del catálogo
        void generarInformePrestamos(); // Detalles de préstamos activos y vencidos
        void generarInformeSanciones(); // Resumen de sanciones activas
};

// Métodos relacionados con usuarios
void Biblioteca::registrarUsuario() {
    string nombre, correo, telefono, matricula, institucion;
    int cuentaBancaria, tipo;
    cout << "Registrar: 1.-Usuario 2.-Estudiante 3.-Invitado" << endl;
    cin >> tipo;

    // Captura de datos comunes
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Correo: ";
    getline(cin, correo);
    cout << "Telefono: ";
    getline(cin, telefono);

    switch (tipo) {
        case 1: {
            cout << "Cuenta Bancaria: ";
            cin >> cuentaBancaria;
            Usuario usuario(nombre, correo, telefono, cuentaBancaria);
            gestorUsuarios.agregarUsuario(Usuario(usuario)); // Registrar usuario
            break;
        }
        case 2: {
            cout << "Institucion: ";
            getline(cin, institucion);
            cout << "Matricula: ";
            getline(cin, matricula);
            cout << "Cuenta Bancaria: ";
            cin >> cuentaBancaria;
            Estudiante estudiante(nombre, correo, telefono, cuentaBancaria, institucion, matricula);
            gestorEstudiantes.agregarEstudiante(Estudiante(estudiante)); // Registrar estudiante
            break;
        }
        case 3: {
            Invitado invitado(nombre, correo, telefono);
            gestorInvitados.registrarInvitado(invitado); // Registrar invitado
            break;
        }
        default:
            cout << "Tipo de usuario no válido." << endl;
            break;
    }

    cout << "\n------Usuario registrado con éxito------" << endl;
    cout << endl;
}

void Biblioteca::buscarUsuario(const string& idUsuario){
    cout<<"----------------------------------------------"<<endl;
    gestorUsuarios.buscarUsuarioPorID(idUsuario);
    gestorEstudiantes.buscarEstudianteID(idUsuario);
    gestorInvitados.buscarInvitadoPorID(idUsuario);
    cout<<"----------------------------------------------"<<endl;
}

void Biblioteca::eliminarUsuario(const string& idUsuario){

    if(gestorEstudiantes.listaVacia() && gestorUsuarios.listaVacia() && gestorInvitados.listaVacia()){
        cout<<"No hay usuarios registrados"<<endl;
        return;
    }

    if(!gestorUsuarios.listaVacia() && gestorUsuarios.existeUsuario(idUsuario)){
        gestorUsuarios.eliminarUsuario(idUsuario);
        cout<<"Usuario eliminado con éxito"<<endl;
        cout<<endl;
    }else if(!gestorEstudiantes.listaVacia() && gestorEstudiantes.existeEstudiante(idUsuario)){
        gestorEstudiantes.eliminarEstudiante(idUsuario);
        cout<<"Estudiante eliminado con éxito"<<endl;
        cout<<endl;
    }else if(!gestorInvitados.listaVacia() && gestorInvitados.existeInvitado(idUsuario)){
        gestorInvitados.eliminarInvitado(idUsuario);
        cout<<"Invitado eliminado con éxito"<<endl;
        cout<<endl;
    }else{
        cout<<"Usuario no encontrado"<<endl;
    }
}

void Biblioteca::listarUsuarios(){
    cout<<endl;
    cout<<"-------------------Usuarios-------------------"<<endl;
    gestorUsuarios.mostrarUsuarios();
    gestorEstudiantes.mostrarEstudiante();
    gestorInvitados.mostrarInvitados();
    cout<<"----------------------------------------------"<<endl;
    cout<<endl;

}

// Métodos relacionados con el catálogo de libros
void Biblioteca::agregarLibro(){
    string titulo="", autor="", categoria="";
    int anio=0;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Titulo: ";
    getline(cin, titulo);
    cout << "Autor: ";
    getline(cin, autor);
    cout << "Categoria: ";
    getline(cin, categoria);
    cout << "Año: ";
    cin >> anio;

    Libro libro(titulo, autor, categoria, anio);
    catalogoLibros.agregarLibro(libro);

    cout<<"\n-----Libro agregado con éxito-----"<<endl;
    cout<<endl;
}

void Biblioteca::eliminarLibro(const string& isbn){
    catalogoLibros.eliminarLibro(isbn);
}

void Biblioteca::buscarLibro(const string& isbn){
    catalogoLibros.buscarPorIsbn(isbn);
}

void Biblioteca::listarLibros(){
    catalogoLibros.mostrarLibros();
}

void Biblioteca::listarLibrosDisponibles(){
    cout<<"---------------Libros Disponibles---------------"<<endl;
    catalogoLibros.listarDisponibles();
    cout<<"----------------------------------------------"<<endl;
}

// Métodos relacionados con préstamos
bool Biblioteca::realizarPrestamo(const string& idUsuario, const string& isbn){
    if(!gestorUsuarios.existeUsuario(idUsuario) && !gestorEstudiantes.existeEstudiante(idUsuario) && !catalogoLibros.existeLibro(isbn)){
        cout<<"Usuario o libro no encontrado"<<endl;
        return false;
    }
    if(gestorSanciones.tieneSanciones(idUsuario)){
        cout<<"Usuario con sanciones sin pagar"<<endl;
        return false;
    }
    if(!catalogoLibros.estaDisponible(isbn)){
        cout<<"Libro no disponible"<<endl;
        return false;
    }
    Prestamo prestamo(isbn, idUsuario);
    gestorPrestamos.agregarPrestamo(prestamo);
    catalogoLibros.marcarNoDisponible(isbn);
    return true;
}

bool Biblioteca::devolverLibro(const string& idUsuario, const string& isbn){
    if(!gestorUsuarios.existeUsuario(idUsuario) && !gestorEstudiantes.existeEstudiante(idUsuario) && !catalogoLibros.existeLibro(isbn)){
        cout<<"Usuario o libro no encontrado"<<endl;
        return false;
    }
    string idPrestamo = gestorPrestamos.finalizarPrestamo(idUsuario, isbn);
    if(gestorPrestamos.verificarSancion(idPrestamo)){
        gestorSanciones.agregarSancion(gestorPrestamos.aplicarSancion(idPrestamo));
    }
    return true;
}

void Biblioteca::listarPrestamosActivos(){
    cout<<"-------------------Prestamos Activos-------------------"<<endl;
    gestorPrestamos.mostrarPrestamos();
    cout<<"-------------------------------------------------------"<<endl;
}

// Métodos relacionados con sanciones
void Biblioteca::registrarSancion(){
    float costo;
    string descripcion, idUsuario;
    cout<<"ID Usuario: ";
    cin>>idUsuario;
    cout<<"Costo: ";
    cin>>costo;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"Descripcion: ";
    getline(cin, descripcion);
    if(gestorUsuarios.existeUsuario(idUsuario) || gestorEstudiantes.existeEstudiante(idUsuario)){
        Sancion sancion(costo, descripcion, idUsuario);
        gestorSanciones.agregarSancion(sancion);
    }else{
        cout<<"Usuario no encontrado"<<endl;
    }
}

void Biblioteca::consultarSanciones(){
    cout<<"-------------------Sanciones-------------------"<<endl;
    return gestorSanciones.muestraSanciones();
    cout<<"----------------------------------------------"<<endl;
}

void Biblioteca::sancionesPendientes(){
    return gestorSanciones.mostrarSancionesPendientes();
}

void Biblioteca::sancionesUsuario(const string& idUsuario){
    if(gestorSanciones.tieneSanciones(idUsuario)){
        gestorSanciones.mostrarSancionUsuario(idUsuario);
    }else{
        cout<<"El usuario no tiene sanciones"<<endl;
    }
}

// Métodos de informes
void Biblioteca::generarInformeUsuarios(){
    cout<<"-------------------Usuarios-------------------"<<endl;
    cout<<"Usuarios registrados: "<<endl;
    gestorUsuarios.mostrarUsuarios();
    cout<<"Estudiantes registrados: "<<endl;
    gestorEstudiantes.mostrarEstudiante();
    cout<<"Invitados registrados: "<<endl;
    gestorInvitados.mostrarInvitados();
    cout<<"----------------------------------------------"<<endl;
}

void Biblioteca::generarInformeLibros(){
    cout<<"-------------------Libros-------------------"<<endl;
    cout<<"Libros registrados: "<<endl;
    catalogoLibros.mostrarLibros();
    cout<<"Libros disponibles: "<<endl;
    catalogoLibros.listarDisponibles();
    cout<<"----------------------------------------------"<<endl;
}

void Biblioteca::generarInformePrestamos(){
    cout<<"-------------------Prestamos-------------------"<<endl;
    gestorPrestamos.mostrarPrestamosActivos();
    cout<<"----------------------------------------------"<<endl;
}

void Biblioteca::generarInformeSanciones(){
    cout<<"-------------------Sanciones-------------------"<<endl;
    gestorSanciones.mostrarSancionesPendientes();
    cout<<"----------------------------------------------"<<endl;
}