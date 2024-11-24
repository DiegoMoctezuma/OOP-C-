#include<iostream>
using namespace std;

template <class T>
class Comparador{
    public:
        bool igual(T a, T b){
            return a == b;
        }
        bool mayor(T a, T b){
            return a > b;
        }
        bool menor(T a, T b){
            return a < b;
        }
        void comparar(T a, T b){
            cout<< a <<" = "<< b << " : " << (igual(a,b)?"Si":"No") << endl;
            cout<< a <<" > "<< b << " : " << (mayor(a,b)?"Si":"No") << endl;
            cout<< a <<" < "<< b << " : " << (menor(a,b)?"Si":"No") << endl;
        }
};

int main(){

    Comparador<int> c;
    cout<<"Enteros"<<endl;
    c.comparar(5,5);

    Comparador<float> c2;
    cout<<"\nFlotantes"<<endl;
    c2.comparar(9.5,5.5);

    Comparador<string> c3;
    cout<<"\nCadenas"<<endl;
    c3.comparar("Hola","Mundo");

    return 0;
}