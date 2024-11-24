#include<iostream>
using namespace std;

class Libro{
  private:
    string titulo,autor;
    int anioPublicacion;
    bool disponible;
  public:
    //Constructor
    Libro(string,string,int);
    //Setter
    void setTitulo(string);
    void setAutor(string);
    void setAnioPublicacion(int);
    void setDisponible(bool);
    //Getter
    string getTitulo();
    string getAutor();
    int getAnioPublicacion();
    bool getDisponible();
    //Métodos
    void prestar();
    void devolver();
    void mostrarInfo();
};

//Constructor
Libro::Libro(string _titulo, string _autor, int _anio){
  titulo = _titulo;
  autor = _autor;
  anioPublicacion = _anio;
  disponible = true;
}

//Setter
void Libro::setTitulo(string _titulo){
  titulo = _titulo;
}
void Libro::setAutor(string _autor){
  autor = _autor;
}
void Libro::setAnioPublicacion(int _anio){
  anioPublicacion = _anio;
}
void Libro::setDisponible(bool _disponible){
  disponible = _disponible;
}

//Getter
string Libro::getTitulo(){
  return titulo;
}
string Libro::getAutor(){
  return autor;
}
int Libro::getAnioPublicacion(){
  return anioPublicacion;
}
bool Libro::getDisponible(){
  return disponible;
}

//Métodos
void Libro::prestar(){
  if(disponible){
    disponible = false;
    cout<<"Libro '"<<titulo<<"' ha sido prestado exitosamente"<<endl;
  }else {
    cout<<"El libro '"<<titulo<<"' no está disponible."<<endl;
  }
}
void Libro::devolver(){
  if(!disponible){
    disponible = true;
    cout<<"El libro '"<< titulo <<"' ha sido devuelto exitosamente"<<endl;
  }else {
    cout<<"El libro '"<<titulo<<"' no está prestado."<<endl;
  }
}
void Libro::mostrarInfo(){
  cout<<"Titulo: "<<titulo<<" ,Autor: "<<autor<<" ,Año: "<<anioPublicacion<<" ,Disponible: "<<disponible<<endl;
}

int main(){
  Libro libro1("Hp","JK",2000);
  libro1.mostrarInfo();
  libro1.prestar();
  libro1.devolver();
  libro1.devolver();
  libro1.getTitulo();
  libro1.getAutor();
  libro1.getAnioPublicacion();
  libro1.getDisponible();

  libro1.setTitulo("Harry Potter");
  libro1.setAnioPublicacion(2001);
  libro1.mostrarInfo();
  libro1.prestar();
  libro1.prestar();
  return 0;
}
