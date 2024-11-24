#include<iostream>
using namespace std;

//Generación de la plantilla
template<class DATO>
void mostrarAbs(DATO num){ //Se escribe menos código
    if(num < 0){
        num *= -1;
    }
    cout << "El valor absoluto es: " << num << endl;
}

template<class DATO>
void imprimir(DATO data){
    cout << "Dato: " << data << endl;
}

int main(){

    int num1 = -5;
    float num2 = -3.5;
    double num3 = -7.8;
    string cadena = "Hola mundo";

    //Llamada a la plantilla con diferentes tipos de datos
    imprimir(num1);
    mostrarAbs<int>(num1);
    imprimir(num2);
    mostrarAbs<float>(num2); //No es necesario especificar el tipo de dato
    imprimir(num3);
    mostrarAbs<double>(num3);
    imprimir(cadena);

    return 0;
}