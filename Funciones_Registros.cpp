#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Estudiante {
    int id;
    string nombre;
    float notaFinal;
};

Estudiante registrarEstudiante() {
    Estudiante e;
    cout << "Ingrese el ID: ";
    cin >> e.id;
    cin.ignore();
    cout << "Ingrese el Nombre completo: ";
    getline(cin, e.nombre);
    cout << "Ingrese la Nota Final (0.0 - 5.0): ";
    cin >> e.notaFinal;
    return e;
}

void mostrarEstudiante(const Estudiante& e) {
    cout << "ID: " << e.id 
         << " | Nombre: " << e.nombre 
         << " | Nota: " << e.notaFinal << endl;
}

float calcularPromedioGeneral(const vector<Estudiante>& lista) {
    if (lista.empty()) return 0.0f;
    float suma = 0;
    for (const auto& est : lista) {
        suma += est.notaFinal;
    }
    return suma / lista.size();
}

int main() {
    int n;
    cout << "==========================================" << endl;
    cout << "   TALLER 2: FUNCIONES Y STRUCTS EN C++   " << endl;
    cout << "==========================================" << endl;
    cout << "Cuantos estudiantes desea registrar? ";
    cin >> n;

    vector<Estudiante> listaEstudiantes;

    for (int i = 0; i < n; ++i) {
        cout << "\n--- Registrando Estudiante #" << (i + 1) << " ---" << endl;
        listaEstudiantes.push_back(registrarEstudiante());
    }

    cout << "\n==========================================" << endl;
    cout << "       LISTADO DE ESTUDIANTES         " << endl;
    cout << "==========================================" << endl;
    for (const auto& est : listaEstudiantes) {
        mostrarEstudiante(est);
    }

    float promedio = calcularPromedioGeneral(listaEstudiantes);
    cout << "\n[+] Promedio General del Curso: " << promedio << endl;

    return 0;
}