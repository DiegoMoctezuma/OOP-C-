#include<iostream>
using namespace std;

class Punto{
  private:
    int x,y;

  public:
    Punto();
    //Setter --> Agrega informacion
    void setPunto(int,int);
    //Get --> Accede a la informacion
    int getPuntox();
    int getPuntoy();
};

Punto::Punto(){}

//Setter
void Punto::setPunto(int _x, int _y){
  x = _x;
  y = _y;
}

//Getter
int Punto::getPuntox(){
  return x;
}

int Punto::getPuntoy(){
  return y;
}

int main(){
  
  Punto punto1;
    //punto1.x = 15 --> Error, el atributo x es privado
  punto1.setPunto(10,20);

  cout<<"Punto: ("<<punto1.getPuntox()<<","<<punto1.getPuntoy()<<")"<<endl;

  return 0;
}

