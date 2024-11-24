#include<iostream>
#include<vector>
using namespace std;

class Producto{
    protected:
        string nombre;
        double precio;
        int stock;
    public:
        Producto(string _nombre, double _precio, int _stock){
            this->nombre = _nombre;
            this->precio = _precio;
            this->stock = _stock;
        }
        Producto(){
            this->nombre = "";
            this->precio = 0;
            this->stock = 0;
        }
        virtual ~Producto() = default;
        virtual void mostrarInfo()const{
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"Precio: $"<<precio<<endl;
            cout<<"Stock: "<<stock<<endl;
        }
        bool vender(int cantidad){
            if(cantidad <= stock){
                return true;
            }else{
                cout<<"\n**** No hay suficiente stock para el producto: "<<nombre<<endl;
                return false;
            }
        }
        void disminuirStock(int cantidad){
            this->stock -= cantidad;
        }
        double getPrecio()const{
            return this->precio;
        }
        string getNombre()const{
            return this->nombre;
        }
        int getStock()const{
            return this->stock;
        }
};

class Smartphone: public Producto{
    private:
        string SO;
        int tamañoPantalla;
    public:
        Smartphone(string _nombre, double _precio, int _stock, string _SO, int _tamañoPantalla):Producto(_nombre,_precio,_stock){
            this->SO = _SO;
            this->tamañoPantalla = _tamañoPantalla;
        }
        void mostrarInfo()const{
            Producto::mostrarInfo();
            cout<<"Sistema operativo: "<<SO<<endl;
            cout<<"Tamaño de la pantalla: "<<tamañoPantalla<<" px"<<endl;
        }
};

class Laptop: public Producto{
    private:
        int tamañoPantalla, cantidadRAM;
    public:
        Laptop(string _nombre, double _precio, int _stock, int _ram, int _tamañoPantalla):Producto(_nombre,_precio,_stock){
            this->cantidadRAM = _ram;
            this->tamañoPantalla = _tamañoPantalla;
        }
        void mostrarInfo()const{
            Producto::mostrarInfo();
            cout<<"RAM instalada: "<<cantidadRAM<<" GB"<<endl;
            cout<<"Tamaño de la pantalla: "<<tamañoPantalla<<" px"<<endl;
        }
};

class Tablet: public Producto{
    private:
        int resPantalla, capacidadBateria;
    public:
        Tablet(string _nombre, double _precio, int _stock, int _bateria, int _resPantalla):Producto(_nombre,_precio,_stock){
            this->capacidadBateria = _bateria;
            this->resPantalla = _resPantalla;
        }
        void mostrarInfo()const{
            Producto::mostrarInfo();
            cout<<"Capacidad de la bateria: "<<capacidadBateria<<" mhA"<<endl;
            cout<<"Resolucion de la pantalla: "<<resPantalla<<endl;
        }
};

class Carrito{
    private:
        vector<Producto *> productos;
        vector<int> cantidades;
        int totalProductos;
        int capacidad;
    public:
        Carrito(int _capacidad){
            this->totalProductos = 0;
            this->capacidad = _capacidad;
        }
        ~Carrito(){
            for(auto producto : productos){
                delete producto;
            }
            productos.clear();
            cantidades.clear();
        }
        void agregarProducto(Producto *producto, int cantidad){
            if(producto->vender(cantidad)){
                if(totalProductos < capacidad){
                    this->productos.push_back(producto);
                    this->cantidades.push_back(cantidad);
                    totalProductos++;
                }else{
                    cout<<"Carrito lleno."<<endl;
                }
            }
        }
        void mostrarCarrito()const{
            if(!productos.empty()){
                for(int i = 0; i < productos.size(); i++){
                    cout<<"Producto "<<i+1<<":"<<endl;
                    productos[i]->mostrarInfo();
                    cout<<"Cantidad: "<<cantidades[i]<<endl;
                    cout<<"-------------------------"<<endl;
                }
            }else{
                cout<<"Carro vacio."<<endl;
            }
        }
        double calcularTotal(){
            if(!productos.empty()){
                double total = 0;
                for(int i = 0; i < productos.size(); i++){
                    total += productos[i]->getPrecio() * cantidades[i];
                }
                return total;
            }else{
                return 0;
            }
        }
        void comprar(){
            if(!productos.empty()){
                double total = calcularTotal();
                cout<<"Total a pagar: $"<<total<<endl;
                cout<<"Compra realizada."<<endl;
                for(int i = 0; i < productos.size(); i++){
                    productos[i]->disminuirStock(cantidades[i]);
                }
                productos.clear();
                cantidades.clear();
                totalProductos = 0;
            }else{
                cout<<"Carro vacio."<<endl;
            }
        }
};

class Cliente{
    private:
        string nombre;
        Carrito carrito;
    public:
        Cliente(string _nombre, int _capacidad = 10):carrito(_capacidad){
            this->nombre = _nombre;
        }
        void agregarProducto(Producto *producto, int cantidad){
            this->carrito.agregarProducto(producto,cantidad);
        }
        void mostrarCarrito()const{
            this->carrito.mostrarCarrito();
        }
        void finalizarCompra(){
            this->carrito.comprar();
        }
        string getNombre(){
            return this->nombre;
        }
};

int main(){

    Producto *s1 = new Smartphone("Samsung Galaxy S21", 1000, 1, "Android", 1080);
    Producto *s2 = new Smartphone("Samsung Galaxy S22", 1300, 10, "Android", 1080);
    Producto *l1 = new Laptop("Dell Inspiron", 800, 5, 8, 1080);
    Producto *t1 = new Tablet("Samsung Galaxy Tab", 600, 7, 5000, 1080);

    Cliente c1("Pepe");
    c1.agregarProducto(s1,2);
    c1.agregarProducto(s2,5);
    c1.agregarProducto(l1,1);
    c1.agregarProducto(t1,1);

    cout<<"-------------------------"<<endl;
    cout<<"Carrito de compras de "<<c1.getNombre()<<":"<<endl;
    cout<<"-------------------------"<<endl;
    c1.mostrarCarrito();
    c1.finalizarCompra();
    c1.mostrarCarrito();

    cout<<"-------------------------"<<endl;
    cout<<"Stock de "<<s1->getNombre()<<":"<<s1->getStock()<<endl;
    cout<<"Stock de "<<s2->getNombre()<<":"<<s2->getStock()<<endl;
    cout<<"Stock de "<<l1->getNombre()<<":"<<l1->getStock()<<endl;
    cout<<"Stock de "<<t1->getNombre()<<":"<<t1->getStock()<<endl;

    return 0;
}