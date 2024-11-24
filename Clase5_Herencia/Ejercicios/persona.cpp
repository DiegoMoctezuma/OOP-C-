#include<iostream>
using namespace std;

class Persona{
    private:
        string nombre;
        int edad;
    public:
    Persona(string _nombre, int _edad){
        this->nombre = _nombre;
        this->edad = _edad;
    }
    void mostrarPersona()const{
        cout<<"Nombre: "<<this->nombre<<", Edad: "<<this->edad<<endl;
    }
};

class Empleado: public Persona{
    private:
        float salario;
        int codigoEmpleado;
    public:
    Empleado(string _nombre, int _edad, float _salario, int _codigoEmpleado):Persona(_nombre, _edad){
        this->salario = _salario;
        this->codigoEmpleado = _codigoEmpleado;
    }
    void mostrarEmpleado()const{
        mostrarPersona();
        cout<<"Salario: "<<this->salario<<", Codigo Empleado: "<<this->codigoEmpleado<<endl;
    }
};

class Estudiante: public Persona{
    private:
        float promedio;
        int codigoEstudiante;
    public:
    Estudiante(string _nombre, int _edad, float _promedio, int _codigoEstudiante):Persona(_nombre, _edad){
        this->promedio = _promedio;
        this->codigoEstudiante = _codigoEstudiante;
    }
    void mostrarEstudiante()const{
        mostrarPersona();
        cout<<"Promedio: "<<this->promedio<<", Codigo Estudiante: "<<this->codigoEstudiante<<endl;
    }
};

class Universitario: public Estudiante{
    private:
        string carrera;
    public:
    Universitario(string _nombre, int _edad, float _promedio, int _codigoEstudiante, string _carrera):Estudiante(_nombre, _edad, _promedio, _codigoEstudiante){
        this->carrera = _carrera;
    }
    void mostrarUniversitario()const{
        mostrarEstudiante();
        cout<<"Carrera: "<<this->carrera<<endl;
    }
};

int main(){
    Persona p1("Juan", 20);
    p1.mostrarPersona();
    cout<<endl;
    Empleado e1("Pedro", 30, 1000, 123);
    e1.mostrarEmpleado();
    cout<<endl;
    Estudiante es1("Maria", 25, 8.5, 456);
    es1.mostrarEstudiante();
    cout<<endl;
    Universitario u1("Ana", 22, 9.0, 789, "MAC");
    u1.mostrarUniversitario();

    return 0;
}