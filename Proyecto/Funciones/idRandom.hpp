#pragma once
#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

string generarID(int longitud) {
    // Conjunto de caracteres posibles
    const string caracteres = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    // Generador de números aleatorios
    mt19937 generador(static_cast<unsigned int>(time(nullptr))); // Semilla basada en el tiempo actual
    uniform_int_distribution<> distribucion(0, caracteres.size() - 1);

    // Construir el ID
    string id;
    for (int i = 0; i < longitud; ++i) {
        if (i > 0 && i % 4 == 0) {
            id += '-';
        }
        id += caracteres[distribucion(generador)];
    }

    return id;
}