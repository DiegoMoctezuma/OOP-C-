#include<iostream>
using namespace std;

class Persona {
  private: //atributos
    int edad;
    string nombre;
  public: // métodos
  Persona(int _edad, string _nombre){
    this->edad = _edad;
    this->nombre = _nombre;
  }
  void mostrarPersona()const{
    cout<<"Nombre: "<<this->nombre<<endl;
    cout<<"Edad: "<<this->edad<<endl;
  }
};

class Alumno: public Persona{
  private:
    string codigoAlumno;
    float notaFinal;
  public:
    Alumno(int _edad, string _nombre, string _codigoAlumno, float _notaFinal)
    :Persona(_edad,_nombre){ //Se requiere inicializar el objeto persona en la herencia.
      this->codigoAlumno = _codigoAlumno;
      this->notaFinal = _notaFinal;
    }
    void mostrarAlumno()const{
      mostrarPersona();
      cout<<"Código Alumno: "<<this->codigoAlumno<<endl;
      cout<<"Nota final: "<<this->notaFinal<<endl;
    }
};

int main(){
  Alumno alumno1(22,"Mario","12345",10);
  alumno1.mostrarAlumno();
  Persona persona1(21,"Pedro");
  persona1.mostrarPersona();

  return 0;
}
