#pragma once
#include <fstream>
#include"../../Generales/Usuario/invitado.hpp"

class GestorInvitados{
    private:
        vector<Invitado> invitados;
    public:
        GestorInvitados();
        ~GestorInvitados();

        void registrarInvitado(const Invitado&);
        void eliminarInvitado(string);
        void buscarInvitadoPorID(string)const;

        void mostrarInvitados()const;
        void verificarInvitado(string)const;
        void mostrarInvitadosActivos()const;
        void mostrarInvitadosExpirados()const;

        bool existeInvitado(string)const;
        bool listaVacia()const;
};

//Destructor
GestorInvitados::GestorInvitados() {
    ifstream archivoEntrada("/Users/mikitl/Documents/FES/POO/Proyecto/Archivos/Usuarios/Invitados.bin", ios::binary);
    if (!archivoEntrada) {
        cerr << "No se encontró el archivo de invitados o no se pudo abrir. Iniciando con lista vacía." << endl;
        return;
    }

    // Leer la cantidad de invitados almacenados
    size_t cantidad;
    archivoEntrada.read(reinterpret_cast<char*>(&cantidad), sizeof(cantidad));

    // Leer cada invitado y agregarlo al vector
    for (size_t i = 0; i < cantidad; ++i) {
        Invitado invitado;
        archivoEntrada.read(reinterpret_cast<char*>(&invitado), sizeof(Invitado));
        invitados.push_back(invitado);
    }

    archivoEntrada.close();
}

GestorInvitados::~GestorInvitados() {

    ofstream archivoSalida("/Users/mikitl/Documents/FES/POO/Proyecto/Archivos/Usuarios/Invitados.bin", ios::binary);
    if (!archivoSalida) {
        cerr << "Error al abrir el archivo binario para guardar invitados." << endl;
        return;
    }

    // Guardar la cantidad de invitados
    size_t cantidad = invitados.size();
    archivoSalida.write(reinterpret_cast<const char*>(&cantidad), sizeof(cantidad));

    // Guardar cada invitado completo
    for (const auto& invitado : invitados) {
        archivoSalida.write(reinterpret_cast<const char*>(&invitado), sizeof(Invitado));
    }

    archivoSalida.close();
}

void GestorInvitados::registrarInvitado(const Invitado& invitado){
    invitados.push_back(invitado);
}

void GestorInvitados::eliminarInvitado(string idUsuario){
    for(int i = 0; i < invitados.size(); i++){
        if(invitados[i].getIdUsuario() == idUsuario){
            invitados.erase(invitados.begin()+i);
        }
    }
}

void GestorInvitados::buscarInvitadoPorID(string idUsuario)const{
    for(int i = 0; i < invitados.size(); i++){
        if(invitados[i].getIdUsuario() == idUsuario){
            invitados[i].mostrarDatos();
        }
    }
}

void GestorInvitados::mostrarInvitados()const{
    if(invitados.size() == 0){
        cout<<"No hay invitados registrados"<<endl;
        return;
    }
    cout<<"Invitados: "<<invitados.size()<<endl;
    for(int i = 0; i < invitados.size(); i++){
        cout<<i+1<<".-:"<<endl;
        invitados[i].mostrarDatos();
        cout<<endl;
    }
}

void GestorInvitados::verificarInvitado(string idUsuario)const{
    for(int i = 0; i < invitados.size(); i++){
        if(invitados[i].getIdUsuario() == idUsuario){
            if(!invitados[i].esActivo()){
                cout<<"Invitado Expirado"<<endl;
            }else{
                cout<<"Invitado Activo"<<endl;
            }
            return;
        }
    }
    cout<<"Invitado no encontrado"<<endl;
}

void GestorInvitados::mostrarInvitadosActivos()const{
    cout<<"Invitados Activos: "<<endl;
    for(int i = 0; i < invitados.size(); i++){
        if(invitados[i].esActivo()){
            invitados[i].mostrarDatos();
        }
    }
}

void GestorInvitados::mostrarInvitadosExpirados()const{
    cout<<"Invitados Expirados: "<<endl;
    for(int i = 0; i < invitados.size(); i++){  
        if(!invitados[i].esActivo()){
            invitados[i].mostrarDatos();
        }
    }
}

bool GestorInvitados::existeInvitado(string idUsuario)const{
    for(int i = 0; i < invitados.size(); i++){
        if(invitados[i].getIdUsuario() == idUsuario){
            return true;
        }
    }
    return false;
}

bool GestorInvitados::listaVacia()const{
    return invitados.empty();
}