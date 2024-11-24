#include<iostream>
#include<vector>

using namespace std;

template <class T>
class BuscaMinMax{
    private:
        vector<T> valores;
    public:
        struct par {
            T min, max;
        }minMax;

        BuscaMinMax(vector<T> _valores){
            this->valores = _valores;
        }
        void encontrarMinMax(){
            T min = valores[0];
            T max = valores[0];
            for(int i = 1; i < valores.size(); i++){
                if(valores[i] < min){
                    min = valores[i];
                }
                if(valores[i] > max){
                    max = valores[i];
                }
            }
            minMax.min = min;
            minMax.max = max;
        }
        void imprimirValores(){
            for(int i = 0; i < valores.size(); i++){
                cout<<valores[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    vector<int> valoresEnteros; // = {2,-1,100,88}; No funciona :(
    valoresEnteros.push_back(2);
    valoresEnteros.push_back(-1);
    valoresEnteros.push_back(100);
    valoresEnteros.push_back(88);

    BuscaMinMax<int> finderEnteros(valoresEnteros);
    finderEnteros.encontrarMinMax();
    
    cout<<"Valores: ";
    finderEnteros.imprimirValores();
    cout<<"Minimo: "<<finderEnteros.minMax.min<<endl;
    cout<<"Maximo: "<<finderEnteros.minMax.max<<endl;


    return 0;
}

