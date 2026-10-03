# Receta: El mayor de tres números

<!-- Escribe aquí tu receta completa en pseudocódigo, ANTES de programar.
     El primer paso es solo un ejemplo del formato; el resto de la receta es completamente tuyo.
     Si la corriges después de probarla a mano, deja aquí la versión final. -->

1. MOSTRAR "Bienvenido a mi programa"
2. primero ← leerDecimal("Escribe el primer número: ")
3. segundo ← leerDecimal("Escribe el segundo número: ")
4. tercero ← leerDecimal("Escribe el tercer número: ")
5. SI primero >= segundo Y primero >= tercero ENTONCES
       mayor ← primero
   SINO SI segundo >= primero Y segundo >= tercero ENTONCES
       mayor ← segundo
   SINO
       mayor ← tercero
   FIN SI
6. MOSTRAR "El mayor es: ", mayor
7. FIN
