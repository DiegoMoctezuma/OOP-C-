#include<iostream> 
using namespace std;

//Clase abstracta
class FiguraGeometica{
    private:
        int x,y;
    protected:
        int visible;
    public:
        FiguraGeometica(int _x = 100, int _y = 100){
            this->x = _x;
            this->y = _y;
            this->visible = 0;
        }
        virtual void pintar()const = 0;
        virtual void ocultar()const = 0;
        void trasladar(int _x,int _y){
            if(visible){
                ocultar();
                x = _x;
                y = _y;
                pintar();
            }else{
                x = _x;
                y = _y;
            }
        }
        //Getters
        int get_x(){
            return x;
        }
        int get_y(){
            return y;
        }
        int get_visible(){
            return visible;
        }
};

//Clases derivadas
class Circulo: public FiguraGeometica{
    private:
        float radio,pi;
    public:
        Circulo(int _x = 100, int _y = 100, float _radio = 10): FiguraGeometica(_x,_y){
            this->radio = _radio;
            this->pi = 3.1416;
        }
        void calculaArea(){
            cout << "Area del circulo: " << pi*radio*radio << endl;
        }
        void calculaPerimetro(){
            cout << "Perimetro del circulo: " << 2*pi*radio << endl;
        }
        void pintar(){
            visible = 1;
        }
};

int main(){
    return 0;
}