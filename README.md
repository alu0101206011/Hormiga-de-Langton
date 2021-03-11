# Hormiga de Langton
Algoritmos y Estructuras de Datos Avanzadas.

Curso 2020-2021.

## Práctica 2: Hormiga de Langton Modificada
### Objetivo 
El objetivo de esta práctica es implementar tipos de datos definidos por el usuario y utilizarlos en un programa en lenguaje C++.


### Entrega
Esta práctica se entregará en la sesión de laboratorio realizada entre las fechas del 8 al 12 de marzo. Durante esta sesión se podrán solicitar modificaciones sobre la práctica. En el actual escenario de presencialidad adaptada, la entrega se realizará en tareas separadas para la  rotación con asistencia presencial y la rotación con asistencia online.


### Enunciado
A partir de la implementación de la hormiga de Langton [[1](https://es.wikipedia.org/wiki/Hormiga_de_Langton)], realizada en la práctica 1, en esta práctica se pide realizar las siguientes modificaciones:

* 1. En el objeto Mundo se quiere emular una malla bidimensional infinita. Para ello, cuando la hormiga alcance una celda más allá de las dimensiones actuales de la malla se procederá a redimensionar la malla, aumentando el tamaño de la misma en una cantidad fija. Sólo se incrementará el tamaño por el borde de la malla donde se haya rebasado.
Hay que tener en cuenta que el incremento de la malla también puede realizarse  hacia posiciones con índices negativos. Para manejar esta situación se implementará un tipo genérico, Vector<T>, que admitirá la indexación en un rango de posiciones negativas. Por ejemplo, Vector<T> v(-10,10), instancia un array de 20 elementos indexados entre -10 y +9.
Por tanto, la malla del mundo infinito se extiende en un rango de posiciones
(-Xmin,-Ymin)hasta (Xmax,Ymax), que podrán aumentar según vayan siendo alcanzadas por la hormiga al moverse. Inicialmente, la malla se extenderá entre las posiciones (-Xini,-Yini) hasta (Xini,Yini), y la hormiga estará ubicada en la posición (0,0).


* 2. En el objeto Hormiga se quiere aumentar las direcciones hacia las que puede mirar, de forma que se incluyen las direcciones en diagonal. Mientras que la hormiga clásica sólo puede mirar en las direcciones: Arriba, aBajo, Izquierda o Derecha; la hormiga modificada también podrá mirar hacia las celdas que puede alcanzar con movimientos en diagonal: arriba-izquierda, arriba-derecha, abajo-izquierda, abajo-derecha. De esta forma, en cada paso de la simulación los giros que realiza la hormiga, según el color de la celda sobre la que se encuentre, serán de 45º en lugar de 90º.


* 3. Se incorpora un nuevo objeto al programa, el objeto Universo, que contendrá al objeto mundo y al objeto hormiga. Será responsable de implementar el bucle que controla el paso del tiempo. De esta forma, en el programa principal sólo hay que leer los datos de inicialización, instanciar el objeto universo, que contiene al mundo y a la hormiga; e invocar al método del objeto universo que simula los pasos de tiempo hasta que el usuario decida finalizar.


### Referencias
* [Wikipedia: Hormiga de Langton](https://es.wikipedia.org/wiki/Hormiga_de_Langton)
