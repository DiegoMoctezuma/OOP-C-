#include<iostream>
using namespace std;

class Vehiculo{
    protected:
        string marca;
        int anio;
        double precio;
    public:
        Vehiculo(string _marca, int _anio, float _precio){
            this->marca = _marca;
            this->anio = _anio;
            this->precio = _precio;
        }
        virtual void mostrarDescripcion()const{
            cout<<"Marca: "<<marca<<", Año: "<<anio<<", Precio: $"<<precio<<endl;
        }
        friend float aplicarDescuento(Vehiculo &, float);
};

class Automovil: public Vehiculo{
    private:
        int numeroPuertas;
    public:
        Automovil(string _marca, int _anio, float _precio, int _numeroPuertas):
            Vehiculo(_marca,_anio,_precio),numeroPuertas(_numeroPuertas){}
        void mostrarDescripcion()const{
            cout<<"- Automovil"<<endl;
            Vehiculo::mostrarDescripcion();
            cout<<"Numero de puertas: "<<numeroPuertas<<endl;
        }
};

class Motocicleta: public Vehiculo{
    private:
        int cilindrada;
    public:
        Motocicleta(string _marca, int _anio, float _precio, int _cilindrada):
            Vehiculo(_marca,_anio,_precio),cilindrada(_cilindrada){}
        void mostrarDescripcion()const{
            cout<<"- Motocicleta"<<endl;
            Vehiculo::mostrarDescripcion();
            cout<<"Cilindrada: "<<cilindrada<<"cc"<<endl;
        }
};

class Bicicleta: public Vehiculo{
    private:
        bool cambios;
    public:
        Bicicleta(string _marca, int _anio, float _precio, bool _cambios):
            Vehiculo(_marca,_anio,_precio),cambios(_cambios){}
        void mostrarDescripcion()const{
            cout<<"- Bicicleta"<<endl;
            Vehiculo::mostrarDescripcion();
            cout<<"Tiene cambios: "<<(cambios?"Si":"No")<<endl;
        }
};

class Cliente{
    private:
        string nombre, id;
    public:
    Cliente(string _nombre, string _id):nombre(_nombre),id(_id){}
    void mostrarInfoCliente()const{
        cout<<"Cliente: "<<nombre<<", ID: "<<id<<endl;
    }
};

class Venta{
    private:
        Cliente cliente;
        Vehiculo *vehiculo;
    public:
        Venta(Cliente &_cliente, Vehiculo *_vehiculo):cliente(_cliente),vehiculo(_vehiculo){}
        void mostrarVenta()const{
            cliente.mostrarInfoCliente();
            vehiculo->mostrarDescripcion(); //Polimorfismo
        }
};

//Funcion amiga
float aplicarDescuento(Vehiculo &vehiculo, float porcentaje){
    return vehiculo.precio * (1 - porcentaje/100);
}

int main(){
    float precio = 0;

    Vehiculo *Ferrari = new Automovil("La Ferrari",2000,10000,2);
    Vehiculo *Kawa = new Motocicleta("Kawasaki Ninja",2024,50000,636);
    Vehiculo *BiciNormal = new Bicicleta("Generica",2024,2000,true);

    Cliente Martin("Martin","12ekjk-3j23l9-lkl347");
    Venta ventaUno(Martin,Ferrari);

    cout<<"\nDescripcion de los productos: "<<endl;
    Ferrari->mostrarDescripcion();
    Kawa->mostrarDescripcion();
    BiciNormal->mostrarDescripcion();

    cout<<"\nDescripcion de la venta: "<<endl;
    ventaUno.mostrarVenta();

    cout<<"\nDescuento en un producto: "<<endl;
    precio = aplicarDescuento(*Kawa,50);
    cout<<"Nuevo precio de la Kawa: $"<<precio<<endl;

    //Liberacion de memoria
    delete Ferrari;
    delete Kawa;
    delete BiciNormal;

    return 0;
}