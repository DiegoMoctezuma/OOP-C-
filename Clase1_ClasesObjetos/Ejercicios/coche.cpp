#include<iostream>
using namespace std;

class Coche{
  private:
    string marca,modelo;
    int año;
  public:
    Coche();
    Coche(string,string,int);
    void mostarDetalles();
};

Coche::Coche(){
  marca = "Desconocida";
  modelo = "Generico";
  año = 2000;
}

Coche::Coche(string _marca, string _modelo, int _año){
  marca = _marca;
  modelo = _modelo;
  año = _año;
}

void Coche::mostarDetalles(){
  cout<<"Marca: "<<marca<<" ,Modelo: "<<modelo<<" ,Año: "<<año<<endl;
}

int main(){
  
  Coche objeto1;
  Coche objeto2("Audi","R8",2024);

  cout<<"Objeto 1: "<<endl;
  objeto1.mostarDetalles();

  cout<<"Objeto 2: "<<endl;
  objeto2.mostarDetalles();

  return 0;
}
