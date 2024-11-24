#include<iostream>
using namespace std;

class Complejo{
  private:
    float real,imaginaria;
  public:
  Complejo(float _real, float _imaginaria){
    this->real = _real;
    this->imaginaria = _imaginaria;
  }
  Complejo(){
    this->real = 0;
    this->imaginaria = 0;
  }
  float getReal()const{
    return real;
  }
  float getImaginario()const{
    return imaginaria;
  }

  //Método
  Complejo suma(Complejo c2){
    float realN,imaginariaN;
    realN = real + c2.getReal();
    imaginariaN = imaginaria + c2.getImaginario();
    Complejo nuevo(realN,imaginariaN);
    return nuevo;
  }
  
  //Sobrecarga de operador
  Complejo operator+(Complejo c2){
    float realN,imaginariaN;

    realN = real + c2.getReal();
    imaginariaN = imaginaria + c2.getImaginario();

    Complejo nuevo(realN,imaginariaN);
    return nuevo;
  }
  Complejo operator++(){
    real++;
    imaginaria++;
    return *this;
  }

  bool operator==(Complejo c2){
    float realN = c2.getReal(), imaginariaN = c2.getImaginario();
    if(real == realN && imaginaria == imaginariaN){
      return true;
    }else{
      return false;
    }
  }

  void mostrarInfo()const{
    cout<<real<<" + ("<<imaginaria<<")i"<<endl;
  }

};

int main(){
  
  Complejo c1(2.5,8);
  Complejo c2(3,1.9);

  Complejo c3 = c1.suma(c2);
  Complejo c4 = c1 + c2;
  Complejo c5 = ++c1; //El operador unario redefinido se pone del lado izquierdo

  c3.mostrarInfo();
  c4.mostrarInfo();
  c5.mostrarInfo();

  bool b1 = c3 == c4;
  bool b2 = c3 == c5;

  cout<< b1<<endl;
  cout<<b2<<endl;


  return 0;
}
