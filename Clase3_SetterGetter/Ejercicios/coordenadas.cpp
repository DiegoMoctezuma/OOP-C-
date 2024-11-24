#include<iostream>
using namespace std;

class Coord{
  private:
    int x;
    int y;
  public:
    //Constructores
    Coord(){
      this-> x = 0;
      this-> y = 0;
    }
    Coord(int _x, int _y){
      this-> x = _x;
      this-> y = _y;
    }
    //Métodos
    void mostrarInformacion()const{
      cout<<"("<<this->x<<","<<this->y<<")";
    }
};

class Circulo{
  private:
    Coord centro;
    int radio;
  public:
    //Constructores
    Circulo(){
      this->centro = Coord(0,0);
      this->radio = 1;
    }
    Circulo(Coord _centro, int _radio){
      this->centro = _centro;
      this->radio = _radio;
    }
    //Setters
    void setCentro(Coord _centro){
      this->centro = _centro;
    }               
    void setRadio(int _radio){
      this->radio = _radio;
    }
    //Métodos
    void mostrarInformacion()const{
      cout<<"Centro: ";
      this->centro.mostrarInformacion();
      cout<<", Radio: "<<this->radio<<endl;
    }
};

int main(){
  Circulo circuloUnitario;
  cout<<"Los datos del circulo unitario son: "<<endl;
  circuloUnitario.mostrarInformacion();

  Coord punto1(2,5);
  Circulo circulo1(punto1,215);
  cout<<"Los datos del circulo uno son: "<<endl;
  circulo1.mostrarInformacion();

  return 0;
}
