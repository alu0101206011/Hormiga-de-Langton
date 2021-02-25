# Hormiga de Langton
Algoritmos y Estructuras de Datos Avanzadas.

Curso 2020-2021.

## Práctica 1: Hormiga de Langton
### Objetivo 
El objetivo de esta práctica es implementar tipos de datos definidos por el usuario y utilizarlos en un programa en lenguaje C++.


### Entrega
Esta práctica se realizará en dos sesiones de laboratorio en las siguientes fechas:
- Sesión tutorizada: 22 al 26 de febrero;
- Sesión de entrega: 1 al 5 de marzo. Durante esta sesión se podrán solicitar modificaciones sobre la práctica. En el actual escenario de presencialidad adaptada, la entrega se realizará en tareas separadas para la rotación con asistencia presencial y la rotación con asistencia online.


### Enunciado
La hormiga de Langton [[1](https://es.wikipedia.org/wiki/Hormiga_de_Langton)] [[2](https://es.wikipedia.org/wiki/Christopher_Langton)] es un sistema discreto, determinista y muy simple. Esto es, dado un estado inicial en el paso de tiempo 0 se define el estado en el paso de tiempo 1, y así sucesivamente. La versión clásica funciona sobre un «mundo» que es una malla cuadriculada bidimensional. En principio se supone infinita, aunque por razones prácticas, se hacen simulaciones donde el borde superior de la malla se identifica con el inferior, y el borde izquierdo con el derecho.

Cada posición de la malla, denominada «celda», tiene un estado que puede ser Blanco o Negro (también se puede usar 0/1, Verdadero/Falso, Izquierda/Derecha, ...).

Inicialmente, paso de tiempo 0, se ubica arbitrariamente a la «hormiga» sobre una celda del mundo. La hormiga siempre está mirando en una de las cuatro direcciones cardinales (Izquierda, Derecha, Arriba, Abajo), y en cada paso de tiempo se mueve una celda de acuerdo con las siguientes *reglas*:
* Si está sobre una celda en estado Blanco entonces cambia la celda a estado Negro, la hormiga gira noventa grados a la izquierda y avanza una celda.
* Si está sobre una celda en estado Negro entonces cambia la celda a estado Blanco, la hormiga gira noventa grados a la derecha y avanza una celda.

Estas simples reglas que gobiernan a la hormiga de Langton llevan a comportamientos complejos que han sido objeto de múltiples investigaciones. Comenzando con una malla totalmente blanca, la versión clásica presenta tres tipos de comportamiento aparentes:

* Simplicidad: durante los primeros cientos de pasos, la hormiga crea patrones sencillos y frecuentemente simétricos.
* Caos: después de varios cientos de pasos, aparece un patrón grande e irregular. La hormiga sigue un camino aparentemente azaroso hasta los 10.000 pasos.
* Orden emergente: finalmente la hormiga empieza a construir una «avenida», un patrón de 104 pasos que se repite indefinidamente.


### Notas de implementación
Se pide implementar un programa que simule el comportamiento de la hormiga de Langton
durante un número indefinido de pasos de tiempo, mostrando para cada paso el estado de los
siguientes objetos:

* Objeto **Mundo**, contiene las celdas de colores, blanco y negro, sobre los que se mueve la hormiga. Inicialmente todas las celdas serán de color blanco. Para evitar trabajar en un entorno gráfico, la visualización de una celda blanca se hará con el carácter ‘ ‘, y la visualización de una celda negra con el carácter ‘X’. El objeto Mundo debe ocultar los detalles de su implementación, esto es, oculta la estructura de datos utilizada internamente para almacenar las celdas. Y por tanto, debe disponer de las operaciones necesarias para consultar y cambiar el estado de cualquiera de las celdas.

* Objeto **Hormiga** que se mueve sobre las celdas del Mundo siguiendo las *reglas*. La Hormiga guarda su dirección de movimiento: Izquierda, Derecha, Arriba o aBajo; y la posición de la celda que ocupa. La Hormiga es responsable de realizar su movimiento, consultando al objeto Mundo el estado de la celda que ocupa. Para evitar trabajar en un entorno gráfico, la visualización de la hormiga utilizará los siguientes caracteres que indican su dirección de movimiento sobre la Rejilla: ‘<’, ‘>’, ‘^’, ‘v’. 

En [[1](https://es.wikipedia.org/wiki/Hormiga_de_Langton)] pueden consultar una animación (en entorno gráfico) del funcionamiento de la versión
clásica de Hormiga de Langton. Se pide implementar un programa en C++ que simule este
comportamiento (en entorno de texto).


### Referencias
* [Wikipedia: Hormiga de Langton](https://es.wikipedia.org/wiki/Hormiga_de_Langton)
* [Wikipedia: Christopher Langton](https://es.wikipedia.org/wiki/Christopher_Langton)
