#include<iostream>
using namespace std;

class Persona{
  protected:
    string nombre;
    int edad;
  public:
    Persona(string _nombre, int _edad){
      this->nombre = _nombre;
      this->edad = _edad;
    }
    Persona(){
      this->nombre = "";
      this->edad = 0;
    }
    virtual void mostrar(){
      cout<<"Nombre: "<<nombre<<", Edad: "<<edad<<endl;
    }
};

class Alumno: public Persona{
  private:
    float notaFinal;

  public:
    Alumno(string _nombre, int _edad, float _nota):Persona(_nombre,_edad){
      this->notaFinal = _nota;
    }
    void mostrar(){
      mostrar();
      cout<<"Nota final: "<<notaFinal<<endl;
    }
};

class Profesor: public Persona{
  private:
    string materia;
  public:
    Profesor(string _nombre, int _edad, string _materia):Persona(_nombre,_edad){
      this->materia = _materia;
    }
    void mostrar(){
      cout<<"Materia: "<<materia<<endl;
    }
};

int main(){
  
  Persona *vector[3];
  
  vector[0] = new Alumno("Pepe",20,8.8);
  vector[0]->mostrar();

  vector[1] = new Alumno("Jose",18,7);
  vector[1]->mostrar();

  vector[2] = new Profesor("Martin",40,"POO");
  vector[2]->mostrar();

  return 0;
}
