#include<iostream>
using namespace std;

class Autor{
  private:
    string nombre, nacionalidad;
  public:
    //Constructor
    Autor(string _nombre, string _nacionalidad){
      this->nombre = _nombre;
      this->nacionalidad = _nacionalidad;
    }
    Autor(){
      this->nombre = "Desconocido";
      this->nacionalidad = "Desconocida";
    }
    //Destructor
    ~Autor(){}
    //Setters
    void setNombre(string _nombre){
      this->nombre = _nombre;
    }
    void setNacionalidad(string _nacionalidad){
      this->nacionalidad = _nacionalidad;
    }
    //Getters
    string getNombre()const{
      return this->nombre;
    }
    string getNacionalidad()const{
      return this->nacionalidad;
    }
    //Métodos
    void mostrarInformacion()const{
      cout<<"Autor: "<<this->nombre<<", Nacionalidad: "<<this->nacionalidad<<endl;
    }
};

class Libro{
  private:
    string titulo;
    Autor autor;
    int anioPublicacion;
  public:
    //Constructor
    Libro(string _titulo, const Autor &_autor, int _anioPublicacion){
      this->titulo = _titulo;
      this->autor = _autor;
      this->anioPublicacion = _anioPublicacion;
    }
    Libro(){
      this->titulo = "";
      this->anioPublicacion = 0;
    }
    //Setters
    void setTitulo(string _titulo){
      this->titulo = _titulo;
    }
    void setAutor(Autor _autor){
      this->autor = _autor;
    }
    void setAnioPublicacion(int _anioPublicacion){
      this->anioPublicacion = _anioPublicacion;
    }
    //Getters
    string getTitulo()const{
      return this->titulo;
    }             
    Autor getAutor()const{
      return this->autor;
    }
    int getAnioPublicacion()const{
      return this->anioPublicacion;
    }
    //Métodos
    void mostrarInformacion()const{
      cout<<"Titulo: "<<this->titulo<<", Año de publicacion: "<<this->anioPublicacion<<endl;
      this->autor.mostrarInformacion();
    }
};

class Biblioteca{
  private:
    Libro *libros;
    unsigned int numLibros;
    int capacidad;
  public:
    //Constructor
    Biblioteca(){
      this->capacidad = 10;
      this->libros = new Libro[this->capacidad];
      this->numLibros = 0;
    }
    //Destructor
    ~Biblioteca(){
      delete[] this->libros;
    }
    //Métodos
    void agregarLibro(const Libro &_libro){
      if(this->numLibros < this->capacidad){
        this->libros[this->numLibros] = _libro;
        this->numLibros++;
      }else{
        this->capacidad+=10;
        Libro *nuevoArreglo = new Libro[this->capacidad];
        for(int i = 0; i < this->numLibros; i++){
          nuevoArreglo[i] = this->libros[i];
        }
        delete[] this->libros;
        this->libros = nuevoArreglo;
        this->libros[this->numLibros] = _libro;
        this->numLibros++;
      }
    }
    void eliminarLibro(Libro _libro){
      string aux;
      if(this->libros != 0){
        for(int i = 0; i < this->numLibros; i++){
          aux = this->libros[i].getTitulo();
          if(_libro.getTitulo() == aux){
            for(int j = i; j < this->numLibros ; j++){
              this->libros[j] = this->libros[j + 1];
            }
            cout<<"Libro '"<<aux<<"' eliminado."<<endl;
            this->numLibros--;
            break;
          }
        }
      }else{
        cout<<"No hay libros en la biblioteca."<<endl;
      }
    }
    void mostrarLibros()const{
      if(this->numLibros != 0){
        for(int i = 0; i < this->numLibros; i++){
          cout<<"Libro "<<i+1<<":"<<endl;
          this->libros[i].mostrarInformacion();
          cout<<endl;
        }
      }else{
        cout<<"No hay libros en la biblioteca"<<endl;
      }
    }
};

int main(){
    Autor MiguelDeCervantes("Miguel de Cervantes Saavedra", "España");
    Autor JoanneRowling("Joanne Rowling","Reino Unido");
    Autor anonimo;

    Libro DonQuijote("Don Quijote de la Mancha",MiguelDeCervantes,1605);
    Libro RinconeteCortadillo("Rinconete y Cortadillo", MiguelDeCervantes, 1613);
    Libro HarryPotterPiedra("Harry Potter y la piedra filosofal",JoanneRowling,1997);
    Libro HarryPotterReliquias("Harry Potter y las reliquias de la muerte",JoanneRowling,2007);
    Libro Tomo1("Tomo 1 Programación",anonimo,2000);
    Libro Tomo2("Tomo 2 Programación",anonimo,2000);

    Biblioteca vacia;
    Biblioteca principal;

    principal.agregarLibro(DonQuijote);
    principal.agregarLibro(RinconeteCortadillo);
    principal.agregarLibro(HarryPotterPiedra);
    principal.agregarLibro(HarryPotterReliquias);
    principal.agregarLibro(Tomo1);
    principal.agregarLibro(Tomo2);

    cout<<"Biblioteca 1:"<<endl;
    vacia.mostrarLibros();

    cout<<"\nBiblioteca 2:"<<endl;
    principal.mostrarLibros();
    
    cout<<"***Eliminación***"<<endl;
    principal.eliminarLibro(Tomo1);
    principal.mostrarLibros();
    
    //vacia.~Biblioteca();
    //principal.~Biblioteca();
    //MiguelDeCervantes.~Autor();

  return 0;
}
