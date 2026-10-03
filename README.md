# Práctica 5: El mayor de tres números

> **En esta práctica todo es tuyo:** el análisis, la receta, el código y las pruebas. Llena cada sección en la fase que se indica.

## 1. Descripción del problema (Fase 1)
Mi programa pide al usuario tres números (pueden ser enteros o decimales, positivos, negativos o cero),
los compara entre sí y muestra el valor del mayor. Si hay empate, muestra ese valor una sola vez.
En la vida real serviría, por ejemplo, para saber cuál de tres sensores de temperatura registra la lectura
más alta, o para detectar el pico más grande entre tres mediciones de un motor.

_____

## 2. Entradas y salidas (Fase 1)

**Entradas:**
1. 3 numeroa
**Salida:**
1. el numero más alto

**¿Muestro el valor del mayor o cuál de los tres fue (primero, segundo o tercero)? ¿Por qué?**
el valor mayor, ya que desea saber ell numero mas alto de los 3 ingresados 

**¿Qué función de `utilerias.h` uso para leer los números? ¿Por qué esa y no la otra?**
Uso `leerDecimal`. El problema no dice que los números sean enteros, y con `leerEntero` no podría comparar casos como 2.5, 2.7 y 2.6. Con `leerDecimal` también acepta enteros así que cubre todos los casos.

## 3. Restricciones e invariante (Fases 1 y 2)

**Restricciones** (¿qué debe cumplirse?):
- Ningún número es inválido: 0 y negativos son válidos para comparar, así que no hace falta validar rango. Lo que sí hay que validar es que lo escrito sea un número,

**¿Hace falta validar el rango de los números (por ejemplo, rechazar el 0 o los negativos)? ¿Por qué?**
No. Comparar cuál es el mayor funciona igual con positivos, negativos y cero. Rechazar el 0 o los negativos dejaría fuera casos reales, como temperaturas bajo cero, y daría resultados incompletos.

**¿Qué hace mi programa cuando dos números son iguales y son los mayores? ¿Y cuando los tres son iguales?**
Si dos son iguales y son los mayores (7, 7, 3), el programa muestra 7 una sola vez, porque el valor mayor es el mismo sin importar cuál de los dos se elija. Si los tres son iguales (5, 5, 5), muestra 5 una sola vez. Para que esto funcione uso `>=` en las comparaciones; con `>` los empates quedarían sin resultado

**¿Quién detecta cada error?** (¿qué revisa la función de `utilerias.h` y qué reviso yo?)
La función `leerDecimal` detecta que lo escrito no sea un número (por ejemplo "abc") y vuelve a pedir el dato. Mi programa no necesita detectar ningún otro error, porque cualquier número válido (positivo, negativo o cero) se puede comparar.

**Invariante** (justo antes de mostrar el resultado, ¿qué es seguro sobre el valor que voy a mostrar?):
El valor que muestro es siempre uno de los tres números que escribió el usuario y es mayor o igual que los otros dos.

## 4. Casos resueltos a mano (Fase 1)

| Caso | Número 1 | Número 2 | Número 3 | Mayor calculado a mano |
|---|---|---|---|---|
| 1 (el mayor en primera posición) | 7| 2 | 1 | 7 |
| 2 (el mayor en segunda posición) | 12 | 21 | 18 | 21 |
| 3 (el mayor en tercera posición) | 45 | 12 | 52 | 52 |
| 4 (con un empate) | 7 | 7 | 2 | 7 |
| 5 (con negativos) | -2 | 1 | 0 | 1 |

## 5. Receta en pseudocódigo (Fase 2)
<!-- Tu receta va en el archivo RECETA.md. Aquí solo responde las preguntas. -->

**¿Probé mi receta a mano con mis 5 casos?** Sí 
**¿Tuve que corregirla? ¿Qué cambié?** no
**¿Cuántas versiones de mi receta escribí hasta la final?** 1
**¿Se me ocurrió otra forma de resolver el problema? ¿Cuál? ¿Por qué elegí la que usé?**
_____

## 6. Cómo compilar y ejecutar (Fase 3)

```bash
g++ -Wall -Wextra -std=c++17 main.cpp -o numero_mayor
./numero_mayor
```

## 7. Ejemplo de ejecución (Fase 3)
Bienvenido: este programa te dice cuál de tres números es el mayor.
Escribe el primer número: 7
Escribe el segundo número: 7
Escribe el tercer número: 2
El mayor es: 7


## 8. De la receta al código (Fase 3)
<!-- Para cada paso de TU receta, escribe la instrucción (o instrucciones) de C++ que lo implementa. Agrega las filas que necesites. -->

| Paso de la receta | Instrucción de C++ que lo implementa |
|---|---|
| 1. Mensaje de bienvenida | `std::cout << "Bienvenido: ..." << std::endl;` |
| leer el primer numero | `primero = leerDecimal("Escribe el primer número: ");` |
| decidir cual es el mayor |  `if (primero >= segundo && primero >= tercero) {...} else if (...) {...} else {...}` |
| mostrar el resultado | ´std::cout << "El mayor es: " << mayor << std::endl;` |

**¿Hubo algún paso de mi receta que me costó traducir a C++? ¿Cuál y por qué?**
El decidir el mayor, porque hay que escribir bien las condiciones con `&&` y usar `>=`
para que los empates tengan resultado

## 9. Experimentos (Fase 3)

**Experimento A: ¿qué te dijo el compilador con `if (a > b > c)`? ¿Qué mostró el programa con 3, 2 y 1? ¿Por qué?**
El compilador avisó que `a > b > c` no tiene el significado matemático. Con 3, 2 y 1 la condición resultó falsa aunque 3 es el mayor: primero se calcula `3 > 2` (true = 1) y luego se compara `1 > 1`, que es falso. La forma correcta es `a > b && b > c`.

**Experimento B: al cambiar `>=` por `>` (o al revés), ¿qué mostró el programa con 7, 7, 3 y con 5, 5, 5? ¿Por qué?**
Con `>`, el caso 7, 7, 3 mostró 3 (incorrecto): ninguna de las dos primeras condiciones se cumple porque 7 > 7 es falso, y cae en el `else`. Con 5, 5, 5 mostró 5, pero solo de casualidad, porque el `else` toma el tercero. Con `>=` ambos casos funcionan. Dejé la versión con `>=`.

**Experimento C (opcional): con `if (a = b)`, ¿qué te dijo el compilador? ¿Qué le pasó al valor de `a`?**

## 10. Tabla de pruebas (Fase 4)

| Caso | Entradas | Esperado | Obtenido | ¿Pasó? |
|---|---|---|---|---|
| Mayor primero | 9, 4, 2 | 9 | 9 | si |
| Mayor en medio | 4, 9, 2 | 9 | 9 | si |
| Mayor al final | 2, 4, 9 | 9 | 9 | si |
| Empate arriba (1.º y 2.º) | 7, 7, 3 | 7 | 7 | si |
| Empate arriba (1.º y 3.º) | 7, 3, 7 | 7 | 7 | si |
| Empate abajo | 8, 3, 3 | 8 | 8 | si |
| Los tres iguales | 5, 5, 5 | 5 | 5 | si |
| Todos negativos | -4, -1, -9 | -1 | -1 | si |
| Con cero | -2, 0, -5 | 0 | 0 | si |
| Decimales cercanos | 2.5, 2.7, 2.6 | 2.7 | 2.7 | si |
| Texto | `abc` (luego 3), 1, 2 | vuelve a pedir el dato; 3 | pedir de nuevo | si |
| Caso propio 1 | 120,124,125 | 125 | 125 | si |
| Caso propio 2 | 2,8,1 | 8 | 8 | si |

## 11. Bitácora de mejoras (Fase 4)

| # | ¿Qué falló o qué quise mejorar? | ¿Qué cambié? | ¿Funcionó? |
|---|---|---|---|
| 1 | _____ | _____ | _____ |
| 2 | _____ | _____ | _____ |

**Reto elegido (opcional):** _____

## 12. Dudas para el profesor (Fase 3)

| Duda | Lo que ya intenté |
|---|---|
| _____ | _____ |

## 13. Reflexión final

**¿Qué aprendí con esta práctica?**
Que un problema facil tiene casos dificiles y que >= y > cambian resultados que a>b>c no funciona como en mate

**Ahora que terminé, ¿qué cambiaría de mi proceso?**
Enlistar los casos raros antes de escribir la receta

**¿Qué fue lo más difícil y cómo lo resolví?**
El main.cpp por que en la terminal me aparecian signos raros en lugar de las tildes y luego se las quite y aun aparecian los signos raros

**¿Qué pregunta me quedó sin responder?**


**¿Qué fue más fácil para mí: la Práctica 3 (receta propia con un paso de ejemplo), la 4 (receta ajena) o esta (todo desde cero)? ¿Por qué?**
La receta ajena ya que me adapte a la frma que se penso de solucion asi que no podia elegir otra alterntiva 

**¿Pensé en los empates antes de programar o los descubrí al probar?**
Al probar

## 14. Lista de verificación antes de entregar (Fase 5)

- [/] Llené las secciones 1 a 13 (no quedan `_____`)
- [/] Escribí mi receta completa en `RECETA.md` antes de programar
- [/] Cada bloque de `main.cpp` tiene su comentario `// Paso N`, de acuerdo con mi receta
- [/] Mi programa compila sin advertencias
- [/] Probé todos los casos de la tabla, incluidos los empates
- [/] Hice los Experimentos A y B y dejé el código correcto al terminar
- [/] No modifiqué `utilerias.h`
- [/] Hice al menos 3 commits con mensajes claros
- [/] Hice `git push` y verifiqué mi fork en GitHub
- [/] Mi fork se llama `ulsa_ime_1_dp_numero_mayor` y el código está en main.cpp`
- [/] Entregué el enlace de mi fork en Classroom