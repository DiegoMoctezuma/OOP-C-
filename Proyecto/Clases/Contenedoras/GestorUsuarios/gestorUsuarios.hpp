#pragma once
#include <fstream>
#include"../../Generales/Usuario/usuario.hpp"

class GestorUsuarios{
    private:
        vector<Usuario> usuarios;
    public:
        GestorUsuarios();
        ~GestorUsuarios();

        void agregarUsuario(Usuario);
        void mostrarUsuarios()const;
        void mostrarUsuariosConSanciones()const;
        
        void buscarUsuarioPorID(string)const;
        void buscarUsuarioPorNombre(string)const;
        void eliminarUsuario(string);
        void modificarUsuario(string);

        bool existeUsuario(string)const;
        bool listaVacia()const;
};

//Constructor
GestorUsuarios::GestorUsuarios(){
    ifstream archivoEntrada("/Users/mikitl/Documents/FES/POO/Proyecto/Archivos/Usuarios/Usuarios.bin", ios::binary);
    if (!archivoEntrada) {
        cerr << "No se encontró el archivo de invitados o no se pudo abrir. Iniciando con lista vacía." << endl;
        return;
    }

    // Leer la cantidad de invitados almacenados
    size_t cantidad;
    archivoEntrada.read(reinterpret_cast<char*>(&cantidad), sizeof(cantidad));
    if (!archivoEntrada) {
        cerr << "Error al leer la cantidad de usuarios." << endl;
        return;
    }

    // Leer cada invitado y agregarlo acl vector
    for (size_t i = 0; i < cantidad; ++i) {
        Usuario usuario;
        archivoEntrada.read(reinterpret_cast<char*>(&usuario), sizeof(Usuario));
        if (!archivoEntrada) {
            cerr << "Error al leer los datos del usuario." << endl;
            return;
        }
        usuarios.push_back(usuario);
    }

    archivoEntrada.close();
}

//Destructor
GestorUsuarios::~GestorUsuarios(){

    ofstream archivoSalida("/Users/mikitl/Documents/FES/POO/Proyecto/Archivos/Usuarios/Usuarios.bin", ios::binary);
    if (!archivoSalida) {
        cerr << "Error al abrir el archivo binario para guardar invitados." << endl;
        return;
    }

    // Guardar la cantidad de invitados
    size_t cantidad = usuarios.size();
    archivoSalida.write(reinterpret_cast<const char*>(&cantidad), sizeof(cantidad));

    // Guardar cada invitado completo
    for (const auto& usuario : usuarios) {
        archivoSalida.write(reinterpret_cast<const char*>(&usuario), sizeof(Usuario));
    }

    archivoSalida.close();
}

//Metodos
void GestorUsuarios::agregarUsuario(Usuario usuario){
    usuarios.push_back(usuario);
}

void GestorUsuarios::mostrarUsuarios()const{
    if(usuarios.empty()){
        cout<<"No hay usuarios registrados"<<endl;
        return;
    }
    cout<<"Usuarios: "<<usuarios.size()<<endl;
    for(int i = 0; i < usuarios.size(); i++){
        cout<<i+1<<".-:"<<endl;
        usuarios[i].mostrarDatos();
        cout<<endl;
    }
}

void GestorUsuarios::mostrarUsuariosConSanciones()const{
    cout<<"Usuarios con sanciones: "<<endl;
    for(int i = 0; i < usuarios.size(); i++){
        if(usuarios[i].getSanciones()){
            usuarios[i].mostrarDatos();
            cout<<endl;
        }
    }
}

void GestorUsuarios::buscarUsuarioPorID(string idUsuario)const{
    for(int i = 0; i < usuarios.size(); i++){
        if(usuarios[i].getIdUsuario() == idUsuario){
            usuarios[i].mostrarDatos();
        }
    }
}

void GestorUsuarios::buscarUsuarioPorNombre(string nombre)const{
    for(int i = 0; i < usuarios.size(); i++){
        if(usuarios[i].getNombre() == nombre){
            usuarios[i].mostrarDatos();
        }
    }
}

void GestorUsuarios::eliminarUsuario(string idUsuario){
    for(int i = 0; i < usuarios.size(); i++){
        if(usuarios[i].getIdUsuario() == idUsuario){
            usuarios.erase(usuarios.begin()+i);
        }
    }
}

void GestorUsuarios::modificarUsuario(string idUsuario){
    for(int i = 0; i < usuarios.size(); i++){
        if(usuarios[i].getIdUsuario() == idUsuario){
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
                    usuarios[i].setNombre(aux);
                    break;
                case 2:
                    cout<<"Correo: ";
                    cin>>aux;
                    usuarios[i].setCorreo(aux);
                    break;
                case 3:
                    cout<<"Telefono: ";
                    cin>>aux;
                    usuarios[i].setTelefono(aux);
                    break;
                case 4:
                    cout<<"Cuenta Bancaria: ";
                    cin>>auxInt2;
                    usuarios[i].setCuentaBancaria(auxInt2);
                    break;
                default:
                    cout<<"Opcion no valida"<<endl;
                    break;
            }
        }
    }
}

bool GestorUsuarios::existeUsuario(string idUsuario)const{
    for(int i = 0; i < usuarios.size(); i++){
        if(usuarios[i].getIdUsuario() == idUsuario){
            return true;
        }
    }
    return false;
}

bool GestorUsuarios::listaVacia()const{
    return usuarios.empty();
}