#include<iostream>
using namespace std;

//Estructura de la pila
template<class TIPO>
class PilaDinamica{ //Clase con diferentes tipos de datos - evita la duplicación de código
    private:
        typedef struct nodo{
            TIPO dato;
            struct nodo *p;
        }nod;
        nod *tope;
    public:
        PilaDinamica(){
            tope = NULL;
        }
        void push(){
            TIPO ndato;
            nod *nuevo = new nod;
            if(nuevo == NULL){
                cout << "No hay memoria disponible" << endl;
                return;
            }
            cout << "Ingrese el dato: ";
            cin >> ndato;
            nuevo->dato = ndato;
            if(tope == NULL){
                nuevo->p = NULL;
            }else{
                nuevo->p = tope;
            }
            tope = nuevo;
        }
        void pop(){
            nod *aux = tope;
            if(tope == NULL){
                cout << "La pila está vacía" << endl;
                return;
            }
            tope = aux->p;
            cout<<"Elemento eliminado: "<<aux->dato<<endl;
            delete(aux);
        }
        void imprimirPila(){
            nod *aux = tope;
            cout<<"Pila: ";
            if(tope == NULL){
                cout<<"La pila está vacía"<<endl;
                return;
            }
            while(aux != NULL){
                cout<<aux->dato<<" ";
                aux = aux->p;
            }
        }
        ~PilaDinamica(){
            while(tope != NULL){
                pop();
            }
        }
};

int main(){

    PilaDinamica<int> pilaEnteros;
    for(int i = 0; i < 5; i++){
        pilaEnteros.push();
    }
    pilaEnteros.~PilaDinamica();

    PilaDinamica<string> pilaCadenas;
    for(int i = 0; i < 5; i++){
        pilaCadenas.push();
    }
    pilaCadenas.~PilaDinamica();

    return 0;
}