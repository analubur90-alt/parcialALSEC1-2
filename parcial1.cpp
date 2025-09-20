// parcial1
#include <iostream>
#include <cmath>
#include <limits>

struct Point {
    double x, y;
};

double calcularDistancia(const Point &p1, const Point &p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

void leerPuntos(Point puntos[], int n) {
    char respuesta;
    std::cout << "¿Desea ingresar los puntos manualmente? (s/n): ";
    std::cin >> respuesta;

    if (respuesta == 's' || respuesta == 'S') {
        for (int i = 0; i < n; i++) {
            std::cout << "Ingrese las coordenadas del punto " << i + 1 << " (x, y): ";
            std::cin >> puntos[i].x >> puntos[i].y;
        }
    } else {
        std::cout << "Usando puntos predeterminados...\n";
        Point predeterminados[4] = { {0,0}, {3,4}, {6,8}, {9,12} };
        for (int i = 0; i < n; i++) {
            puntos[i] = predeterminados[i % 4];
        }
    }
}

double calcularDistanciaMasCercana(Point puntos[], int n, const Point &pUsuario, int &indiceMasCercano) {
    double distanciaMinima = std::numeric_limits<double>::max();
    indiceMasCercano = -1;

    for (int i = 0; i < n; i++) {
        double d = calcularDistancia(pUsuario, puntos[i]);
        if (d < distanciaMinima) {
            distanciaMinima = d;
            indiceMasCercano = i;
        }
    }
    return distanciaMinima;
}

void mostrarResultado(Point puntos[], int indiceMasCercano, double distancia) {
    std::cout << "El punto más cercano es: (" 
              << puntos[indiceMasCercano].x << ", " 
              << puntos[indiceMasCercano].y << ")\n";
    std::cout << "La distancia al punto más cercano es: " << distancia << std::endl;
}

double calcularDistanciaTotal(Point puntos[], int n) {
    double total = 0;
    for (int i = 0; i < n - 1; i++) {
        total += calcularDistancia(puntos[i], puntos[i+1]);
    }
    return total;
}

int main() {
    int n;

    std::cout << "Ingrese el número de puntos (mínimo 2): ";
    std::cin >> n;

    if (n < 2) {
        std::cout << "Se necesitan al menos 2 puntos para calcular las distancias.\n";
        return 1;
    }

    Point puntos[n];

    leerPuntos(puntos, n);

    Point pUsuario;
    std::cout << "Ingrese las coordenadas del punto desde el que calcular la distancia (x, y): ";
    std::cin >> pUsuario.x >> pUsuario.y;

    int indiceMasCercano;
    double distancia = calcularDistanciaMasCercana(puntos, n, pUsuario, indiceMasCercano);

    mostrarResultado(puntos, indiceMasCercano, distancia);

    double distanciaTotal = calcularDistanciaTotal(puntos, n);
    std::cout << "La distancia total recorrida pasando por todos los puntos es: " 
              << distanciaTotal << std::endl;

    return 0;
}