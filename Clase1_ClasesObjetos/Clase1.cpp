#include<iostream>
using namespace std;

//Declaración de la clase
class Rectangulo{
  private:
    float base;
    float altura;

  public:
    Rectangulo(float,float); //Constructor
    void perimetro();
    void area();
};

//Funcionalidad de los métodos
Rectangulo::Rectangulo(float _base, float _altura){
  base = _base;
  altura = _altura;
}

void Rectangulo::perimetro(){
  cout<<"El perimetro es: "<<2*altura + 2*base<<" u"<<endl;
}

void Rectangulo::area(){
  cout<<"El area es: "<<base*altura<<" u^2"<<endl;
}

//Principal
int main(){
  
  Rectangulo objeto1 = Rectangulo(2.5,5);
  Rectangulo objeto2(2,5);

  cout<<"Rectangulo 1: "<<endl;
  objeto1.perimetro();
  objeto1.area();

  cout<<"Rectangulo 2: "<<endl;
  objeto2.perimetro();
  objeto2.area();

  return 0;
}
