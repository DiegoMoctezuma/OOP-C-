#pragma once
#include <fstream>
#include"../../Generales/Usuario/estudiante.hpp"

class GestorEstudiantes{
    private:
        vector<Estudiante> estudiantes;
    public:
        GestorEstudiantes();
        ~GestorEstudiantes();

        void agregarEstudiante(Estudiante);
        void mostrarEstudiante()const;
        void mostrarEstudiantesConSanciones()const;
        
        void buscarEstudianteID(string)const;
        void buscarEstudiantePorNombre(string)const;
        void eliminarEstudiante(string);
        void modificarEstudiante(string);

        bool existeEstudiante(string)const;
        bool listaVacia()const;
};

//Constructor
GestorEstudiantes::GestorEstudiantes(){
    ifstream archivoEntrada("/Users/mikitl/Documents/FES/POO/Proyecto/Archivos/Usuarios/Estudiantes.bin", ios::binary);
    if (!archivoEntrada) {
        cerr << "No se encontró el archivo de invitados o no se pudo abrir. Iniciando con lista vacía." << endl;
        return;
    }

    // Leer la cantidad de invitados almacenados
    size_t cantidad;
    archivoEntrada.read(reinterpret_cast<char*>(&cantidad), sizeof(cantidad));

    // Leer cada invitado y agregarlo acl vector
    for (size_t i = 0; i < cantidad; ++i) {
        Estudiante estudiante;
        archivoEntrada.read(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante));
        estudiantes.push_back(estudiante);
    }

    archivoEntrada.close();
}

//Destructor
GestorEstudiantes::~GestorEstudiantes(){
    
    ofstream archivoSalida("/Users/mikitl/Documents/FES/POO/Proyecto/Archivos/Usuarios/Estudiantes.bin", ios::binary);
    if (!archivoSalida) {
        cerr << "Error al abrir el archivo binario para guardar invitados." << endl;
        return;
    }

    // Guardar la cantidad de invitados
    size_t cantidad = estudiantes.size();
    archivoSalida.write(reinterpret_cast<const char*>(&cantidad), sizeof(cantidad));

    // Guardar cada invitado completo
    for (const auto& usuario : estudiantes) {
        archivoSalida.write(reinterpret_cast<const char*>(&usuario), sizeof(Estudiante));
    }

    archivoSalida.close();
}

//Metodos
void GestorEstudiantes::agregarEstudiante(Estudiante usuario){
    estudiantes.push_back(usuario);
}

void GestorEstudiantes::mostrarEstudiante()const{
    if(estudiantes.empty()){
        cout<<"No hay estudiantes registrados"<<endl;
        return;
    }
    cout<<"Estudiantes: "<<estudiantes.size()<<endl;
    for(int i = 0; i < estudiantes.size(); i++){
        cout<<i+1<<".-:"<<endl;
        estudiantes[i].mostrarDatos();
        cout<<endl;
    }
}

void GestorEstudiantes::mostrarEstudiantesConSanciones()const{
    cout<<"Estudiantes con sanciones: "<<endl;
    for(int i = 0; i < estudiantes.size(); i++){
        if(estudiantes[i].getSanciones()){
            estudiantes[i].mostrarDatos();
            cout<<endl;
        }
    }
}

void GestorEstudiantes::buscarEstudianteID(string idUsuario)const{
    for(int i = 0; i < estudiantes.size(); i++){
        if(estudiantes[i].getIdUsuario() == idUsuario){
            estudiantes[i].mostrarDatos();
        }
    }
}

void GestorEstudiantes::buscarEstudiantePorNombre(string nombre)const{
    for(int i = 0; i < estudiantes.size(); i++){
        if(estudiantes[i].getNombre() == nombre){
            estudiantes[i].mostrarDatos();
        }
    }
}

void GestorEstudiantes::eliminarEstudiante(string idUsuario){
    for(int i = 0; i < estudiantes.size(); i++){
        if(estudiantes[i].getIdUsuario() == idUsuario){
            estudiantes.erase(estudiantes.begin()+i);
        }
    }
}

void GestorEstudiantes::modificarEstudiante(string idUsuario){
    for(int i = 0; i < estudiantes.size(); i++){
        if(estudiantes[i].getIdUsuario() == idUsuario){
            string aux;
            int auxInt,auxInt2;
            cout<<"Campo a modificar: ";
            cout<<"1.-Nombre"<<endl;
            cout<<"2.-Correo"<<endl;
            cout<<"3.-Telefono"<<endl;
            cout<<"4.-Cuenta Bancaria"<<endl;
            cout<<"Opcion: ";
            cin>>auxInt;
            switch(auxInt){
                case 1:
                    cout<<"Nombre: ";
                    cin>>aux;
                    estudiantes[i].setNombre(aux);
                    break;
                case 2:
                    cout<<"Correo: ";
                    cin>>aux;
                    estudiantes[i].setCorreo(aux);
                    break;
                case 3:
                    cout<<"Telefono: ";
                    cin>>aux;
                    estudiantes[i].setTelefono(aux);
                    break;
                case 4:
                    cout<<"Cuenta Bancaria: ";
                    cin>>auxInt2;
                    estudiantes[i].setCuentaBancaria(auxInt2);
                    break;
                default:
                    cout<<"Opcion no valida"<<endl;
                    break;
            }
        }
    }
}

bool GestorEstudiantes::existeEstudiante(string idUsuario)const{
    for(int i = 0; i < estudiantes.size(); i++){
        if(estudiantes[i].getIdUsuario() == idUsuario){
            return true;
        }
    }
    return false;
}

bool GestorEstudiantes::listaVacia()const{
    return estudiantes.empty();
}