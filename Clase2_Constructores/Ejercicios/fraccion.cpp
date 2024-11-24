#include<iostream>
using namespace std;

class Fraccion{
  private:
    int numerador,denominador;

  public:
    Fraccion();
    Fraccion(int,int);
    void mostrar();
};

Fraccion::Fraccion(){
  numerador = 1;
  denominador = 1;
}

Fraccion::Fraccion(int _numerador, int _denominador){
  numerador = _numerador;
  denominador = _denominador;
}

void Fraccion::mostrar(){
  cout<<numerador<<"/"<<denominador<<endl;
}

int main(){

  Fraccion objeto1;
  Fraccion objeto2(24,3);

  cout<<"Objeto 1: ";
  objeto1.mostrar();

  cout<<"Objeto 2: ";
  objeto2.mostrar();

  return 0;
}
