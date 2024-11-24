#pragma once
#include<vector>
#include"../../Generales/Sancion/sancion.hpp"

class GestorSanciones{
    private:
        vector<Sancion> sanciones;
    public:
        GestorSanciones();
        ~GestorSanciones();

        void agregarSancion(Sancion);
        void muestraSanciones()const;
        void marcarPagado(string);
        void mostrarSancionesPendientes()const;

        bool tieneSanciones(string)const;
        void mostrarSancionUsuario(string)const;
};

//Constructor
GestorSanciones::GestorSanciones(){

    ifstream archivoEntrada("/Users/mikitl/Documents/FES/POO/Proyecto/Archivos/Sanciones.bin", ios::binary);
    if (!archivoEntrada) {
        cerr << "No se encontró el archivo de sanciones o no se pudo abrir. Iniciando con lista vacía." << endl;
        return;
    }

    size_t cantidad;
    archivoEntrada.read(reinterpret_cast<char*>(&cantidad), sizeof(cantidad));

    for (size_t i = 0; i < cantidad; ++i) {
        Sancion sancion;  // Crear una instancia de Sancion

        size_t size;
        archivoEntrada.read(reinterpret_cast<char*>(&size), sizeof(size));
        string buffer(size, '\0');
        archivoEntrada.read(&buffer[0], size);

        // Leer y asignar ID de la sancion
        sancion.setId(buffer);

        // Leer y asignar ID del usuario
        archivoEntrada.read(reinterpret_cast<char*>(&size), sizeof(size));
        buffer.resize(size);
        archivoEntrada.read(&buffer[0], size);
        sancion.setIdUsuario(buffer);

        // Leer y asignar monto de la sancion
        double monto;
        archivoEntrada.read(reinterpret_cast<char*>(&monto), sizeof(monto));
        sancion.setCosto(monto);

        // Leer y asignar estado de la sancion
        bool estado;
        archivoEntrada.read(reinterpret_cast<char*>(&estado), sizeof(estado));
        sancion.setEstado(estado);

        // Leer y asignar descripcion de la sancion
        archivoEntrada.read(reinterpret_cast<char*>(&size), sizeof(size));
        buffer.resize(size);
        archivoEntrada.read(&buffer[0], size);
        sancion.setDescripcion(buffer);

        // Leer y asignar fecha de sancion
        archivoEntrada.read(reinterpret_cast<char*>(&size), sizeof(size));
        buffer.resize(size);
        archivoEntrada.read(&buffer[0], size);
        sancion.setFechaSancion(buffer);

        // Leer y asignar fecha de pago
        archivoEntrada.read(reinterpret_cast<char*>(&size), sizeof(size));
        buffer.resize(size);
        archivoEntrada.read(&buffer[0], size);
        sancion.setFechaPago(buffer);

        sanciones.push_back(sancion);
    }

    archivoEntrada.close();
}

//Destructor
GestorSanciones::~GestorSanciones(){
    ofstream archivoSalida("/Users/mikitl/Documents/FES/POO/Proyecto/Archivos/Sanciones.bin", ios::binary);
    if (!archivoSalida) {
        cerr << "Error al abrir el archivo binario para guardar sanciones." << endl;
        return;
    }

    // Guardar la cantidad de sanciones
    size_t cantidad = sanciones.size();
    archivoSalida.write(reinterpret_cast<const char*>(&cantidad), sizeof(cantidad));

    // Guardar cada sancion completa
    for (const auto& sancion : sanciones) {
        size_t size;
        string data;

        // Guardar ID de la sancion
        data = sancion.getId();
        size = data.size();
        archivoSalida.write(reinterpret_cast<const char*>(&size), sizeof(size));
        archivoSalida.write(data.c_str(), size);

        // Guardar ID del usuario
        data = sancion.getIdUsuario();
        size = data.size();
        archivoSalida.write(reinterpret_cast<const char*>(&size), sizeof(size));
        archivoSalida.write(data.c_str(), size);

        // Guardar monto de la sancion
        double monto = sancion.getCosto();
        archivoSalida.write(reinterpret_cast<const char*>(&monto), sizeof(monto));

        // Guardar estado de la sancion
        bool estado = sancion.getEstado();
        archivoSalida.write(reinterpret_cast<const char*>(&estado), sizeof(estado));

        // Guardar descripcion de la sancion
        data = sancion.getDescripcion();
        size = data.size();
        archivoSalida.write(reinterpret_cast<const char*>(&size), sizeof(size));
        archivoSalida.write(data.c_str(), size);

        // Guardar fecha de sancion
        data = sancion.getFechaSancion();
        size = data.size();
        archivoSalida.write(reinterpret_cast<const char*>(&size), sizeof(size));
        archivoSalida.write(data.c_str(), size);

        // Guardar fecha de pago
        data = sancion.getFechaPago();
        size = data.size();
        archivoSalida.write(reinterpret_cast<const char*>(&size), sizeof(size));
        archivoSalida.write(data.c_str(), size);
    }

    archivoSalida.close();
}

//Metodos
void GestorSanciones::agregarSancion(Sancion sancion){
    sanciones.push_back(sancion);
}
void GestorSanciones::muestraSanciones()const{
    if(sanciones.empty()){
        cout<< "No hay sanciones"<< endl;
        return;
    }
    cout<< "Sanciones: "<<endl;
    for(int i = 0; i < sanciones.size(); i++){
        cout<< "Sancion "<< i+1<<":"<< endl;
        sanciones[i].muestraDatos();
        cout<< endl;
    }
}
void GestorSanciones::marcarPagado(string id){
    for(int i = 0; i < sanciones.size(); i++){
        if(sanciones[i].getId() == id && !sanciones[i].getEstado()){
            sanciones[i].marcarPagado();
            return;
        }else{
            if(sanciones[i].getId() == id && sanciones[i].getEstado()){
                cout<< "La sancion ya ha sido pagada"<< endl;
                return;
            }
        }
    }
    cout<< "No se encontro la sancion"<< endl;
}

void GestorSanciones::mostrarSancionesPendientes()const{
    cout<< "Sanciones pendientes: "<< endl;
    for(int i = 0; i < sanciones.size(); i++){
        if(!sanciones[i].getEstado()){
            cout<< "Sancion "<< i+1<<":"<< endl;
            sanciones[i].muestraDatos();
            cout<< endl;
        }
    }
}

bool GestorSanciones::tieneSanciones(string id)const{
    for(int i = 0; i < sanciones.size(); i++){
        if(sanciones[i].getIdUsuario() == id && !sanciones[i].getEstado()){
            return true;
        }
    }
    return false;
}

void GestorSanciones::mostrarSancionUsuario(string id)const{
    cout<< "Sanciones del usuario: "<< id<< endl;
    for(int i = 0; i < sanciones.size(); i++){
        if(sanciones[i].getIdUsuario() == id){
            cout<< "Sancion "<< i+1<<":"<< endl;
            sanciones[i].muestraDatos();
            cout<< endl;
        }
    }
}