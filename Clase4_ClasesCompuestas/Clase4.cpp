#include<iostream>
using namespace std;

class Persona{
  private:
    string nombre;
    int edad;
  public:
    Persona(string _nombre, int _edad){
      this-> nombre = _nombre;
      this-> edad = _edad;
    }
    //Constructor copia
    Persona(const Persona &p){
      this-> nombre = p.nombre;
      this-> edad = p.edad;
    }
    //const -> Garantiza que no se van a modificar la información
    void Saludar()const{
      cout<<"Nombre: "<<this->nombre<<" Edad: "<<this->edad<<endl;
    }
};

class Libro{
  private:
    string titulo,autor;
    int anioPublicacion;
    bool disponible;
  public:
    //Constructor
    Libro(string _titulo = "",string _autor = "",int _anio = 0);
    //Setter
    void setTitulo(string);
    void setAutor(string);
    void setAnioPublicacion(int);
    void setDisponible(bool);
    //Getter
    string getTitulo()const;
    string getAutor()const;
    int getAnioPublicacion()const;
    bool getDisponible()const;
    //Métodos
    void prestar();
    void devolver();
    void mostrarInfo()const;
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
string Libro::getTitulo()const{
  return titulo;
}
string Libro::getAutor()const{
  return autor;
}
int Libro::getAnioPublicacion()const{
  return anioPublicacion;
}
bool Libro::getDisponible()const{
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
void Libro::mostrarInfo()const{
  cout<<"Titulo: "<<titulo<<" ,Autor: "<<autor<<" ,Año: "<<anioPublicacion<<" ,Disponible: "<<disponible<<endl;
}

class Biblioteca{
  private:
    string nombre;
    Libro libros[100]; //Clase compuesta
    int cantidadLibros;
  public:
    Biblioteca(string _nombre){
      this-> nombre = _nombre;
      this-> cantidadLibros = 0;
    }
    void agregarLibro(const Libro &_libro){
      this->libros[this->cantidadLibros] = _libro;
      this->cantidadLibros++;
    }
    //Getter
    void getCantidadLibros()const{
      cout<<"Número de libros: "<<this->cantidadLibros<<endl;
    }
    void getInformacionLibros()const{
      for(int i = 0; i < this-> cantidadLibros; i++){
        cout<<"Libro: "<< i+1 <<endl;
        libros[i].mostrarInfo();
      }
    }
};

int main(){
  Persona persona1("Carlos",25);
  Persona personaCopia = persona1; //Genera objetos nuevos - no asigna informacion de un objeto a otro
  cout<<"Constructor copia: "<<endl;
  personaCopia.Saludar();

  cout<<"Biblioteca: "<<endl;
  Libro libro1("T-UNO","A-UNO",100);
  Libro libro2("T-DOS","A-DOS",200);
  Libro libro3("T-TRES","A-TRES",300);
  Libro libro4("T-CUATRO","A-CUATRO",400);

  Biblioteca principal("Biblioteca principal");
  principal.agregarLibro(libro1);
  principal.agregarLibro(libro2);
  principal.agregarLibro(libro3);
  principal.agregarLibro(libro4);
  principal.getCantidadLibros();
  principal.getInformacionLibros();

  return 0;
}
