#include<iostream>
#include<map>
using namespace std;

class Dict{
    private:
        map<string,string> datos;
    public:
        //Agregar una clave al datos
        void agregarDato(string clave, string valor){
            datos[clave] = valor;
        }
        void mostrarDatos()const{
            for(auto par:datos){
                cout<<par.first<<": "<<par.second<<endl;
            }
        }
        void encontrarDato(string clave){
            if(datos.find(clave) != datos.end()){
                cout<<clave<<": "<<datos[clave]<<endl;
            }else{
                cout<<"Clave no encontrada."<<endl;
            }
        }
};

int main(){
    Dict diccionario;
    diccionario.agregarDato("nombre","Juan");
    diccionario.agregarDato("edad","25");
    diccionario.agregarDato("ciudad","Lima");
    
    diccionario.mostrarDatos();
    diccionario.encontrarDato("nombre");
    diccionario.encontrarDato("ciudad");
    diccionario.encontrarDato("pais");

    return 0;
}