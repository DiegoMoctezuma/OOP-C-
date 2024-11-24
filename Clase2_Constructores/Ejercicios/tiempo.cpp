#include<iostream>
using namespace std;

class Hora{
  private:
    int segundos,minutos,horas;
  public:
    Hora(int,int,int); //Constructor 1
    Hora(long); //Constructor 2 - SIEMPRE DEBEN TENER DIFERENTES PARAMETROS
    void mostrarHora();
    ~Hora(); //Destructor
};

//Constructor 1
Hora::Hora(int _segundos, int _minutos, int _horas){
  segundos = _segundos;
  minutos = _minutos;
  horas = _horas;
}
//Constructor 2
Hora::Hora(long tiempoS){
  horas = int(tiempoS / 3600);
  minutos = int((tiempoS - (horas * 3600)) / 60);
  segundos = int(tiempoS - (minutos * 60 + horas * 3600 ));
}

//Destructor
Hora::~Hora(){}//Simpre va vacío

void Hora::mostrarHora(){
  cout<<"Son las "<<horas<<"h:"<<minutos<<"m:"<<segundos<<"s"<<endl;
}

int main(){
  
  Hora objeto1 = Hora(40,4,10);
  Hora objeto2(36280);

  cout<<"Objeto 1: ";
  objeto1.mostrarHora();
  cout<<"Objeto 2: ";
  objeto2.mostrarHora();

  return 0;
}
