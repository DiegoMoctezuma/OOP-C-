#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

int main(){

    int a = 15, b = 5, n;

    //int fclose(FILE*);
    FILE *archivo;
    archivo = fopen("datos.txt","a"); //Solo la letra es secuencial - con un '+' es directo

    if(archivo == NULL){
        cout<<"Error al abrir el archivo"<<endl;
    }else{
        /* fprintf(archivo,"Potencias de 2: \n");
        for(int i = 1; i < 100 ; i++ ){
            fprintf(archivo,"Potencia %i - %.1f\n",i,pow(2,i));
        } */
        fprintf(archivo,"Numeros primos: \n");
        for(int i = 2; i < 100 ; i++ ){
            n = 0;
            for(int j = 1; j <= i; j++){
                if(i%j == 0){
                    n++;
                }
            }
            if(n == 2){
                fprintf(archivo,"%i, ",i);
            }
        }
        cout<<"Datos guardados en el archivo"<<endl;
        
    }

    fclose(archivo);

    return 0;
}