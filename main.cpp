/*
Juan Carlos Velez Reyes
Juanki07
801-21-2150
CCOM3033-002
HW 6: Figuras
*/

#include <iostream>
#include <cmath>      
#include <iomanip>   

using namespace std;

// Funciones para volumen
double volumen(double radio, double altura) { //Para un cilindro
    return M_PI * pow(radio, 2) * altura;
}

double volumen(double radio) { // Para una esfera
    return (4.0 / 3.0) * M_PI * pow(radio, 3);
}

double volumen(double largo, double ancho, double alto) { // para un prisma rectangular
    return largo * ancho * alto;
}

// Funciones para área
double area(double radio, double altura) { // para un cilindro
    return 2 * M_PI * radio * (radio + altura);
}

double area(double radio) { // para una esfera
    return 4 * M_PI * pow(radio, 2);
}

double area(double largo, double ancho, double alto) { // para un prisma rectangular
    return 2 * (largo * ancho + largo * alto + ancho * alto);
}

// Funcion para numero positivo
double leerDatoPositivo(string mensaje) {
    double valor;
    do {
        cout << mensaje;
        cin >> valor;
        if (valor <= 0) {
            cout << "Por favor, ingrese un valor positivo.\n";
        }
    } while (valor <= 0);
    return valor;
}

int main() {
    char figura, opcion;

    cout << "Este programa calcula el volumen y el area de la superficie de tres figuras.\n\n";

    // Opcion de figuras
    cout << "Escoja una figura:\n";
    cout << "  a. Cilindro\n";
    cout << "  b. Esfera\n";
    cout << "  c. Prisma rectangular\n";
    cout << "Seleccion: ";
    cin >> figura;

    // Validacion de input
    while (figura != 'a' && figura != 'b' && figura != 'c') {
        cout << "Opcion invalida. Intente de nuevo: ";
        cin >> figura;
    }

    // Opcion para calcular volumen o area
    cout << "\nEscoja entre los siguientes opciones:\n";
    cout << "  a. Volumen\n";
    cout << "  b. Area de la superficie\n";
    cout << "Seleccion: ";
    cin >> opcion;

    while (opcion != 'a' && opcion != 'b') {
        cout << "Opcion invalida. Intente de nuevo: ";
        cin >> opcion;
    }

    cout << fixed << setprecision(2); // Redondear a dos decimales

    switch (figura) {
        case 'a': { // Cilindro
            double r = leerDatoPositivo("Entre el radio del cilindro: ");
            double h = leerDatoPositivo("Entre la altura del cilindro: ");
            if (opcion == 'a') {
                cout << "El volumen del cilindro es " << volumen(r, h) << endl;
            } else {
                cout << "El area del cilindro es " << area(r, h) << endl;
            }
            break;
        }
        case 'b': { // Esfera
            double r = leerDatoPositivo("Entre el radio de la esfera: ");
            if (opcion == 'a') {
                cout << "El volumen de la esfera es " << volumen(r) << endl;
            } else {
                cout << "El area de la esfera es " << area(r) << endl;
            }
            break;
        }
        case 'c': { // Prisma rectangular
            double l = leerDatoPositivo("Entre el largo del prisma: ");
            double a = leerDatoPositivo("Entre el ancho del prisma: ");
            double h = leerDatoPositivo("Entre el alto del prisma: ");
            if (opcion == 'a') {
                cout << "El volumen del prisma es " << volumen(l, a, h) << endl;
            } else {
                cout << "El area del prisma es " << area(l, a, h) << endl;
            }
            break;
        }
    }

    return 0;
}

