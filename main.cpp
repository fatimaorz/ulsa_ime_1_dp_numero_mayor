// Práctica 5: El mayor de tres números
// Traduce TU receta de RECETA.md a C++, paso por paso.
// Deja el comentario "// Paso N" sobre cada bloque, con la numeración de TU receta.

// ¿Recuerdas qué hace iostream?
#include <iostream>

// ¿Qué función de utilerias.h vas a usar? ¿Por qué esa y no la otra?
#include "utilerias.h"

int main() {
    // Variables 
    double primero = 0.0;
    double segundo = 0.0;
    double tercero = 0.0;
    double mayor = 0.0;

    // Paso 1: mensaje de bienvenida
    std::cout << "Bienvenido: Esste programa te dira cual de los 3 numeros es mayor." << std::endl;

    // Paso 2: leer el primer número
    primero = leerDecimal(" Escribe el primer numero: ");

    // Paso 3: leer el segundo número
    segundo = leerDecimal(" Escribe el segundo numero: ");

    // Paso 4: leer el tercer número
    tercero = leerDecimal(" Escribe el tercer numero: ");

    // Paso 5: decidir cuál es el mayor
    // Uso >= para que los empates (7, 7, 3 o 5, 5, 5) también tengan resultado.
    if (primero >= segundo && primero >= tercero) {
        mayor = primero;
    } else if (segundo >= primero && segundo >= tercero) {
        mayor = segundo;
    } else {
        mayor = tercero;
    }

    // Paso 6: mostrar el resultado
    std::cout << "El mayor es: " << mayor << std::endl;

    // Paso 7: fin
    return 0;
}