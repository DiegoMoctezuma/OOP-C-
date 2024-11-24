#include"./Clases/Contenedoras/Biblioteca/biblioteca.hpp"
#include<stdio.h>

void switchUsuarios(Biblioteca &);
void switchLibros(Biblioteca &);
void switchPrestamos(Biblioteca &);
void switchSanciones(Biblioteca &);
void switchInformes(Biblioteca &);

int main(){

    Biblioteca bibliotecaCentral;

    int opcion = 0, tipo = 0;
    string idUsuario, isbn;

    do{
        system("clear");
        cout<<"Bienvenido a la biblioteca central"<<endl;
        cout<<"1.- Usuarios"<<endl;
        cout<<"2.- Libros"<<endl;
        cout<<"3.- Prestamos"<<endl;
        cout<<"4.- Sanciones"<<endl;
        cout<<"5.- Informes"<<endl;
        cout<<"6.- Salir"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;
        system("clear");

        switch(opcion){
            case 1:
                switchUsuarios(bibliotecaCentral);
            break;
            case 2:
                switchLibros(bibliotecaCentral);
            break;
            case 3:
                switchPrestamos(bibliotecaCentral);
            break;
            case 4:
                switchSanciones(bibliotecaCentral);
            break;
            case 5:
                switchInformes(bibliotecaCentral);
            break;
            case 6:
                cout<<"Adios!"<<endl;
            break;
            default:
                cout<<"Opcion no valida"<<endl;
        }

    }while(opcion != 6);

    return 0;
}

void switchUsuarios(Biblioteca &bibliotecaCentral){
    int tipo = 0;
    string idUsuario;
    do{
        cout<<"1.- Registrar usuario"<<endl;
        cout<<"2.- Buscar usuario"<<endl;
        cout<<"3.- Eliminar usuario"<<endl;
        cout<<"4.- Listar usuarios"<<endl;
        cout<<"5.- Salir"<<endl;
        cout<<"Opcion: ";
        cin>>tipo;
        switch(tipo){
            case 1:
                system("clear");
                bibliotecaCentral.registrarUsuario();
                break;
            case 2:
                system("clear");
                cout<<"ID Usuario: ";
                cin>>idUsuario;
                bibliotecaCentral.buscarUsuario(idUsuario);
                break;
            case 3:
                system("clear");
                cout<<"ID Usuario: ";
                cin>>idUsuario;
                bibliotecaCentral.eliminarUsuario(idUsuario);
                break;
            case 4:
                system("clear");
                bibliotecaCentral.listarUsuarios();
                break;
            default:
                cout<<"Opcion no valida"<<endl;
                break;
        }
    }while(tipo != 5);
}

void switchLibros(Biblioteca &bibliotecaCentral){
    int tipo = 0;
    string isbn;
    do{
        cout<<"1.- Registrar libro"<<endl;
        cout<<"2.- Buscar libro"<<endl;
        cout<<"3.- Eliminar libro"<<endl;
        cout<<"4.- Listar libros"<<endl;
        cout<<"5.- Salir"<<endl;
        cout<<"Opcion: ";
        cin>>tipo;
        switch(tipo){
            case 1:
                system("clear");
                bibliotecaCentral.agregarLibro();
                break;
            case 2:
                system("clear");
                cout<<"ISBN: ";
                cin>>isbn;
                bibliotecaCentral.buscarLibro(isbn);
                break;
            case 3:
                system("clear");
                cout<<"ISBN: ";
                cin>>isbn;
                bibliotecaCentral.eliminarLibro(isbn);
                break;
            case 4:
                system("clear");
                bibliotecaCentral.listarLibros();
                break;
            case 5:
                break;
            default:
                cout<<"Opcion no valida"<<endl;
                break;
        }
    }while(tipo != 5);
}

void switchPrestamos(Biblioteca &bibliotecaCentral){
    int tipo = 0;
    string idUsuario, isbn;
    do{
        cout<<"1.- Prestar libro"<<endl;
        cout<<"2.- Devolver libro"<<endl;
        cout<<"3.- Listar prestamos activos"<<endl;
        cout<<"4.- Salir"<<endl;
        cout<<"Opcion: ";
        cin>>tipo;
        switch(tipo){
            case 1:
                system("clear");
                cout<<"ID Usuario: ";
                cin>>idUsuario;
                cout<<"ISBN: ";
                cin>>isbn;
                bibliotecaCentral.realizarPrestamo(idUsuario, isbn);
                break;
            case 2:
                system("clear");
                cout<<"ID Usuario: ";
                cin>>idUsuario;
                cout<<"ISBN: ";
                cin>>isbn;
                if(bibliotecaCentral.devolverLibro(idUsuario, isbn)){
                    cout<<"Libro devuelto"<<endl;
                }
                break;
            case 3:
                system("clear");
                bibliotecaCentral.listarPrestamosActivos();
                break;
            case 4:
                break;
            default:
                cout<<"Opcion no valida"<<endl;
                break;
        }
    }while(tipo != 4);
}

void switchSanciones(Biblioteca &bibliotecaCentral){
    int tipo = 0;
    string idUsuario;
    do{
        cout<<"1.- Registrar sancion"<<endl;
        cout<<"2.- Consultar sanciones"<<endl;
        cout<<"3.- Sanciones pendientes"<<endl;
        cout<<"4.- Sanciones de usuario"<<endl;
        cout<<"5.- Salir"<<endl;
        cout<<"Opcion: ";
        cin>>tipo;
        switch(tipo){
            case 1:
                system("clear");
                bibliotecaCentral.registrarSancion();
                break;
            case 2:
                system("clear");
                bibliotecaCentral.consultarSanciones();
                break;
            case 3:
                system("clear");
                bibliotecaCentral.sancionesPendientes();
                break;
            case 4:
                system("clear");
                cout<<"ID Usuario: ";
                cin>>idUsuario;
                bibliotecaCentral.sancionesUsuario(idUsuario);
                break;
            case 5:
                break;
            default:
                cout<<"Opcion no valida"<<endl;
                break;
        }
    }while(tipo != 5);
}

void switchInformes(Biblioteca &bibliotecaCentral){
    int tipo = 0;
    do{
        cout<<"1.- Generar informe de usuarios"<<endl;
        cout<<"2.- Generar informe de libros"<<endl;
        cout<<"3.- Generar informe de prestamos"<<endl;
        cout<<"4.- Generar informe de sanciones"<<endl;
        cout<<"5.- Salir"<<endl;
        cout<<"Opcion: ";
        cin>>tipo;
        switch(tipo){
            case 1:
                system("clear");
                bibliotecaCentral.generarInformeUsuarios();
                break;
            case 2:
                system("clear");
                bibliotecaCentral.generarInformeLibros();
                break;
            case 3:
                system("clear");
                bibliotecaCentral.generarInformePrestamos();
                break;
            case 4:
                system("clear");
                bibliotecaCentral.generarInformeSanciones();
                break;
            case 5:
                break;
            default:
                cout<<"Opcion no valida"<<endl;
                break;
        }
    }while(tipo != 5);
}
