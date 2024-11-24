#include<iostream>
using namespace std;

//Clase abstracta
class Dispositivo{
    protected:
        string id;
        bool estado;
    public:
        Dispositivo(string _id){
            this->id = _id;
            this->estado = false;
        }
        void encender(){
            estado = true;
        }
        void apagar(){
            estado = false;
        }
        virtual void mostrarInfo()const = 0;
};

//Clase Conectividad Wifi
class ConectividadWiFi{
    protected:
        string redWiFi;
    public:
        ConectividadWiFi(){
            this->redWiFi = "";
        }
        void conectarWiFi(string _redWiFi){
            this->redWiFi = _redWiFi;
        }
        void desconectarWiFi(){
            this->redWiFi = "";
        }
        void mostrarConectividad()const{
            if(redWiFi != ""){
                cout << "Conectado a: " << redWiFi << endl;
            }else{
                cout << "Sin conexion WiFI" << endl;
            }
        }
};

//Clases derivadas
class Camara: public Dispositivo, public ConectividadWiFi{
    private:
        int resolicion;
    public:
        Camara(string _id, int _resolucion): Dispositivo(_id){
            this->resolicion = _resolucion;
        }
        void mostrarInfo()const{
            cout << "\nID: " << id << endl;
            cout << "Estado: " << (estado?"Encendido":"Apagado") << endl;
            cout << "Resolucion: " << resolicion << " px" << endl;
            ConectividadWiFi::mostrarConectividad();
        }
}; 

class Termostato: public Dispositivo{
    private:
        float temperatura;
    public:
        Termostato(string _id, float _temperatura): Dispositivo(_id){
            this->temperatura = _temperatura;
        }
        void mostrarInfo()const{
            cout << "\nID: " << id << endl;
            cout << "Estado: " << (estado?"Encendido":"Apagado") << endl;
            if(estado){
                cout << "Temperatura: " << temperatura << "°C" << endl;
            }else{
                cout << "Temperatura: Sin información" << endl;
            }
        }
};


int main(){
    Camara camara1("Camara1", 1080);
    camara1.encender();
    camara1.conectarWiFi("PC-Puma");
    camara1.mostrarInfo();
    camara1.apagar();
    camara1.desconectarWiFi();

    cout << endl;
    Termostato termostato1("Termostato1", 25.5);
    termostato1.encender();
    termostato1.mostrarInfo();
    termostato1.apagar();

    cout << "\nApagando: " <<endl;
    camara1.mostrarInfo();
    termostato1.mostrarInfo();

    return 0;
}