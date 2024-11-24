#include<iostream>
#include<vector>

using namespace std;

class Alimento{
    private:
        string tipoAlimento;
    public:
        Alimento(string _tipoAlimento){
            this->tipoAlimento = _tipoAlimento;
        }
        Alimento(){
            this->tipoAlimento = "Desconocido";
        }
        string getAlimento()const{
            return this->tipoAlimento;
        }
};

class Habitat{
    private:
        string tipo;
    public:
    Habitat(string _tipo){
        this->tipo = _tipo;
    }
    Habitat(){
        this->tipo = "Desconocido";
    }
    //Get
    string getTipo()const{
        return this->tipo;
    }
};

class Animal{
    protected://Permite a las clases derivadas acceder a los atributos de la clase.
        string nombre,especie;
        int edad;
        Alimento alimento;
        Habitat habitat;
    public:
        Animal(string _nombre, string _especie, int _edad, const Alimento &_alimento, const Habitat &_habitat){
            this->nombre = _nombre;
            this->especie = _especie;
            this->edad = _edad;
            this->alimento = _alimento;
            this->habitat = _habitat;
        }
        Animal(){
            this->nombre = "Desconocido";
            this->especie = "Desconocida";
            this->edad = 0;
        }
        //Setters
        void setNombre(string _nombre){
            this->nombre = _nombre;
        }
        void setEspecie(string _especie){
            this->especie = _especie;
        }
        void setEdad(int _edad){
            this->edad = _edad;
        }
        void setAlimento(const Alimento &_alimento){
            this->alimento = _alimento;
        }
        void setHabitat(const Habitat &_habitat){
            this->habitat = _habitat;
        }
        //Getters
        string getNombre()const{
            return this->nombre;
        }
        string getEspecie()const{
            return this->especie;
        }
        int getEdad()const{
            return this->edad;
        }
        Alimento getAlimento()const{
            return this->alimento;
        }
        Habitat getHabitat()const{
            return this->habitat;
        }
        //Método
        virtual void mostrarInfo(){
            cout<<"Nombre: "<<nombre<<", Especie: "<<especie<<", Edad: "<<edad<<", Alimento: "<<alimento.getAlimento()<<", Habitat: "<<habitat.getTipo()<<endl;
        }
        //Sobrecarga
        bool operator==(const Animal &otro)const{
            return(especie == otro.especie && nombre == otro.nombre);
        }
        //Funcion amiga
        friend void cambiarInformacion(Animal &,string,Habitat &);
};

class Mamifero:public Animal{
    private:
        bool tienePelo;
    public:
    Mamifero(string _nombre, string _especie, int _edad, const Alimento &_alimento,const Habitat &_habitat,bool _tienePelo)
    :Animal(_nombre,_especie,_edad, _alimento, _habitat){
        this->tienePelo = _tienePelo;
    }
    Mamifero(){
        this->tienePelo = false;
    }
    //Setter
    void setTienePelo(bool _tienePelo){
        this->tienePelo = _tienePelo;
    }
    //Getter
    bool getTienePelo()const{
        return this->tienePelo;
    }
    //Método
    void mostrarInfo(){
        Animal::mostrarInfo();
        cout<<"Tiene pelo: "<<(tienePelo ? "Si": "No")<<endl;
    }
};

class Ave:public Animal{
    private:
        bool puedeVolar;
    public:
    Ave(string _nombre, string _especie, int _edad, const Alimento &_alimento,const Habitat &_habitat,bool _puedeVolar)
    :Animal(_nombre,_especie,_edad,_alimento,_habitat){
        this->puedeVolar = _puedeVolar;
    }
    Ave(){
        this->puedeVolar = false;
    }
    //Setter
    void setpuedeVolar(bool _puedeVolar){
        this->puedeVolar = _puedeVolar;
    }
    //Getter
    bool getpuedeVolar()const{
        return this->puedeVolar;
    }
    //Método
    void mostrarInfo(){
        Animal::mostrarInfo();
        cout<<"Puede volar: "<<(puedeVolar ? "Si" : "No")<<endl;
    }
};

class Zoologico{
    private:
        vector<Animal*> animales;
    public:
    Zoologico(){}
    //Métodos
    void agregarAnimal(Animal* nuevoAnimal){
        animales.push_back(nuevoAnimal);
    }
    void mostrarInfo()const{
        if(animales.size() > 0){
            cout<<"****Animales: "<<animales.size()<<"****"<<endl;
            for(auto animal : animales){
                animal->mostrarInfo();
                cout<<endl;
            }
        }else{
            cout<<"No hay animales en el zoologico. :("<<endl;
        }
    }
    //Función amiga
    void cambiarInformacion(Animal &animal,string nombre,Habitat &habitat){
        animal.setNombre(nombre);
        animal.setHabitat(habitat);
    }
};

int main(){

    //Alimentos
    Alimento carne("Carne");
    Alimento semillas("Semillas");
    Alimento pescado("Pescado");
    Alimento plantas("Plantas");

    //Habitats
    Habitat selva("Selva");
    Habitat desierto("Desietro");
    Habitat acuatico("Acuatico");

    //Mamiferos
    Animal *jaguar = new Mamifero("Jaguar","Mamifero",10,carne,selva,true);
    Animal *camello = new Mamifero("Camello","Mamifero",6,plantas,desierto,true);
    Animal *elefante = new Mamifero("Elefante","Mamifero",15,plantas,selva,true);
    Animal *leon = new Mamifero("Leon","Mamifero",8,carne,selva,true);

    //Aves
    Animal *canario = new Ave("Canario","Ave",3,semillas,selva,true);
    Animal *pinguino = new Ave("Pinguino","Ave",7,pescado,acuatico,false);
    Animal *loro = new Ave("Loro","Ave",5,semillas,selva,true);
    Animal *aguila = new Ave("Aguila","Ave",4,carne,selva,true);

    //Zoologico
    Zoologico principal; 
    Zoologico secundario;

    cout<<"Zoo principal:"<<endl;
    principal.agregarAnimal(jaguar);
    principal.agregarAnimal(camello);
    principal.agregarAnimal(canario);
    principal.agregarAnimal(pinguino);
    principal.agregarAnimal(loro);
    principal.agregarAnimal(leon);
    principal.agregarAnimal(elefante);
    principal.agregarAnimal(aguila);
    principal.mostrarInfo();

    secundario.agregarAnimal(jaguar);
    secundario.cambiarInformacion(*jaguar,"Jaguar de la selva",acuatico);
    secundario.mostrarInfo();


    return 0;
}
