#include<iostream>

using namespace std;

class Fecha{
  private:
    int dia,mes,anio;
  public:
    Fecha(int,int,int); //Primer constructor
    Fecha(long); //Segundo constructor
    void mostrarFecha();
    ~Fecha(); //Destructor
};

Fecha::Fecha(int _dia, int _mes, int _anio){
  dia = _dia;
  mes = _mes;
  anio = _anio;
}

Fecha::Fecha(long fecha){
  anio = int (fecha/10000);
  mes = int((fecha - anio * 10000)/100);
  dia = int(fecha - anio * 10000 - mes * 100);
}

//Destructor
Fecha::~Fecha(){}

void Fecha::mostrarFecha(){
  cout<<"La fecha es: "<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

int main(){
  
  Fecha objeto1 = Fecha(9,9,2024);
  Fecha objeto2(20240909);

  objeto1.mostrarFecha();
  objeto2.mostrarFecha();

  objeto1.~Fecha();
  objeto2.~Fecha();

  return 0;
}
