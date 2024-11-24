#include<iostream>
using namespace std;

/* EXAMEN
    Herencia - multiple y simple
    Composicion
    Funciones amigas 
*/

template <class T>
class Calculadora{
    private:
        T a,b;
    public:
        T suma(){
            return a+b;
        }
        T resta(){
            return a-b;
        }
        T multiplicacion(){
            return a*b;
        }
        T division(){
            return a/b;
        }
        void usarCalculadora(){
            int resp;

            cout<<"Ingrese el primer numero: ";
            cin>>a;
            cout<<"Ingrese el segundo numero: ";
            cin>>b;
            do{
                cout<<"\nQue operacion desea realizar: "<<endl;
                cout<<"1. Suma"<<endl;
                cout<<"2. Resta"<<endl;
                cout<<"3. Multiplicacion"<<endl;
                cout<<"4. Division"<<endl;
                cout<<"5. Cambiar numeros"<<endl;
                cout<<"6. Salir"<<endl;
                cin>>resp;

                switch(resp){
                    case 1:
                        cout<<"\nSuma:"<<endl;
                        cout<< a <<" + "<< b << " = " <<suma()<<endl;
                        break;
                    case 2:
                        cout<<"\nResta:"<<endl;
                        cout<< a <<" - "<< b << " = " <<resta()<<endl;
                        break;
                    case 3:
                        cout<<"\nMultiplicacion:"<<endl;
                        cout<< a <<" * "<< b << " = " <<multiplicacion()<<endl;
                        break;
                    case 4:
                        cout<<"\nDivision:"<<endl;
                        if(b != 0){
                            cout<< a <<" / "<< b << " = " <<division()<<endl;
                        }else{
                            cout<<"No se puede dividir entre 0"<<endl;
                        }
                        break;
                    case 5:
                        cout<<"\nIngrese el primer numero: ";
                        cin>>a;
                        cout<<"Ingrese el segundo numero: ";
                        cin>>b;
                        break;
                    case 6:
                        cout<<"Saliendo..."<<endl;
                        break;
                    default:
                        cout<<"Opcion no valida"<<endl;
                }
            }while(resp != 6);
        }
};


int main(){
    Calculadora<float> flotantes;
    flotantes.usarCalculadora();

    return 0;
}