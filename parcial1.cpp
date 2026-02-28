#include <iostream>
#include <cmath>
using namespace std;

// Estructura para representar un punto en el plano
struct Punto {
    double x;
    double y;
};

// Calcula la distancia entre dos puntos
double distancia(Punto a, Punto b) {
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    return sqrt(dx * dx + dy * dy);
}

// Encuentra la distancia mínima entre todos los puntos
double distanciaMinima(Punto lista[], int cantidad) {

    if (cantidad < 2) {
        return -1;
    }

    double menor = distancia(lista[0], lista[1]);

    for (int i = 0; i < cantidad; i++) {
        for (int j = i + 1; j < cantidad; j++) {

            double actual = distancia(lista[i], lista[j]);

            if (actual < menor) {
                menor = actual;
            }
        }
    }

    return menor;
}

int main() {

    int cantidad;

    cout << "Cantidad de puntos: ";
    cin >> cantidad;

    if (cantidad < 2) {
        cout << "Se necesitan al menos 2 puntos." << endl;
        return 0;
    }

    Punto lista[cantidad];

    for (int i = 0; i < cantidad; i++) {
        cout << "Punto " << i + 1 << endl;
        cout << "x: ";
        cin >> lista[i].x;
        cout << "y: ";
        cin >> lista[i].y;
    }

    double resultado = distanciaMinima(lista, cantidad);

    cout << "La distancia mas cercana es: " << resultado << endl;

    return 0;
}