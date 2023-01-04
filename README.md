![image](https://user-images.githubusercontent.com/121684145/210482534-addf3a21-797c-43dc-8ce6-d7ee6883ad76.png)
<br/>
# UNIVERSIDAD DE LAS AMERICAS
MATEMÁTICAS DISCRETAS<br/>
Camila Cabrera,Mateo Encalada, Ariel Raura,Joe Cordero

# Descripcion juego tres en raya
Este juego necesita la participacion de dos jugadores, a cada uno se le asiganra X o O.Una jugador inicia la partida,y se continua por turnos colocando alternativamenteX y O en los casilleros de una figura formada por dos líneas verticales que cruzan dos líneas horizontales,es decir una matriz 3x3.Cada jugador intenta obtener una fila vertical horixontal o diagonal de tres X o tres O antes que el oponente lo haga.
# Funciones principales del código
#### **Explicación de funcionamiento**
|#|Función|Descripción|
|--|--|--|
|1|` int main() `| La función principal ejecuta el menú del juego y pregunta al jugador que rol desea que inicie la partida (jugador/computador).|
|2|` void initialise(char board[][SIDE])`| La función se compone por dos ciclos for que controlan las filas y columnas de la matriz , y se encargan de recorrerlo inicializando los valores de cada posición.|
|3|` void showInstructions()`|La función imprimir las instrucciones para que el usuario visualice el número de casilla.|
|4|` bool gameOver(char board[][SIDE])`| La función retorna verdadero o falso dependiendo si se cumplió que existe un cruce diagonal o cruce vertical o cruce horizontal en la matriz.|
|5|` bool rowCrossed(char board[][SIDE]) `| La función devuelve verdadero en caso de que en un misma fila existan tres jugadas del mismo jugador.|
|6|` bool columnCrossed(char board[][SIDE]) `| La función devuelve verdadero en caso de que en un misma columna existan tres jugadas del mismo jugador.|
|7|` bool diagonalCrossed(char board[][SIDE]) `| La función devuelve verdadero en caso de que en un misma diagonal existan tres jugadas del mismo jugador.|
|8|` int bestMove(char board[][SIDE], int moveIndex) `| La función retorna un entero, en esta se recorre la matriz y se comprueba si la posición está vacía para poder efectuar la rutina minmax. Se ejecuta en el turno de la computadora. |
|9|` void showBoard(char board[][SIDE])`| La función imprime el estado actual del tablero (X y O).|
|10|` int minimax(char board[][SIDE], int depth, bool isAI )`| La función retorna un entero	y es recursiva. En ella se evalúa el estado de la partida y en función de si continua activa se calcula el score del jugador o de la computadora. |
|11|` void declareWinner(int whoseTurn) `| La función imprime quien ganó la partida.|
|12|` void playTresEnRaya(int whoseTurn) `| La función inicializa el juego y se encarga de controlar los turnos del jugador y computador invocando a la mayor parte de funciones. Indica las posiciones disponibles en la matriz para el jugador. |

<br/>

# Tiempo de los mejores y peores casos 
El algoritmo minmax en teoría de juegos se encarga de reducir (minimizar) la pérdida máxima posible en una partida con un adversario. Básicamente, se basa en elegir el mejor movimiento para el jugador 1 suponiendo que el oponente (jugador 2) escogerá el peor para el (jugador 1). Dependiendo de los movimientos seleccionados se puede calcular la probabilidad de victoria. Es por esto por lo que se pueden identificar algunos de los mejores y peores casos del juego tres en raya y el tiempo aproximado de duración. Para estimar el tiempo se debe considerar los dos jugadores, que en el caso particular son:
* Jugador 1 Computador (O): El tiempo de respuesta durante la partida será aproximadamente de milisegundo, tiempo que tarda en procesarse el algoritmo.
* Jugador 2 Humano(X): dependerá de la agilidad y estrategia de razonamiento, aproximadamente se podría establecerlo en 15 segundos como base y 45 segundos en promedio. 
#### **Tiempos de los mejores y peores casos**
Los casos especificados a continuación son considerados desde el jugador 1y los más comunes.Se contemplara como mejor caso victoria y el peor caso empate considerando que el juego perfecto termina en empate sin importar con qué juega el primer jugador de la partida.Para el calculo del tiempo se implemento en el cóigo el uso de la funcion clock(), propia de la libreria ctime.Los tiempos tomados corresponden a la ejecución del código en una laptop con Intel(R) Core(TM) i7-6500U CPU @ 2.50GHz   2.59 GHz y 16,0 GB de RAM.

|#|Caso de juego|Partida|Tiempo(min)|
|--|--|--|--|
|1|` Victoria jugador 1 (O) en 6 jugadas de la partida`|![image](https://user-images.githubusercontent.com/121684145/210283517-e380eb6a-536e-466f-b0a2-a9a64eb43413.png)| 0.05432|
|2|` Victoria jugador 1 (O) en 7 jugadas de la partida`|![image](https://user-images.githubusercontent.com/121684145/210283525-4908d0b0-2333-4378-9aec-7ca298d7bb50.png)| 0.04563|
|3|` Empate jugador 1 (O) y jugador 2(x) bloqueo horizontal-vertical`|![image](https://user-images.githubusercontent.com/121684145/210283550-2e1edb55-3891-49dc-aa63-8430c4b701c6.png)| 0.04432|
|4|` Empate jugador 1 (O) y jugador 2(x) bloqueo diagonal`|![image](https://user-images.githubusercontent.com/121684145/210283553-1810c2bd-d3a2-4155-88fd-5feabc233675.png)| 0.06453|

# Estudio de posibilidades árbol combinatorio 
El estudio de probabilidad de victoria, perdida o empate en el juego de tres en raya parte del estudio combinatorio de las posibilidades de colocar X y O en cada jugada. Por ejemplo, hay hay 9 formas posibles de colocar la primera marca, 8 formas restantes de colocar la segunda, 7 la tercera,6 la cuarta, 5 la quinta,4 la sexta,3 la septima,2 la octava y 1 la novena. Esto sería 9*8*7*6*5*4*3*2*1 = 9! = 362880. Representado en un árbol de posibilidad figura 2, donde la posición influye en el resultado del nodo hoja donde los resultados positivos favorecen al jugador 1, los resultados negativos favorecen al jugador 2 y el cero indica empate. La mayoría de los juegos tienen árboles de juego excesivamente grandes, de forma que no podemos expandir completamente el árbol hasta llegar a los nodos terminales, tal es el caso del tres en raya. Por ello, suele ser común usar un algoritmo de profundidad limitada que solo expande algunos niveles del árbol, sin llegar a los nodos terminales. Además, en el caso especifico del tres en raya se maneja un concepto de isomorfismo que se refiere a las mimas jugadas, pero con una reflexión en el plano figura 1.
<br/>
Figura #1:
![image](https://user-images.githubusercontent.com/121684145/210283645-ec5d9348-49a7-4663-b30f-7b43ad0dc169.png)
Fuente: Elaboración propia
<br/><br/> 
Figura #2:
![image](https://user-images.githubusercontent.com/121684145/210283736-f8d73139-f751-4414-ad09-c7761d0ac59b.png)
Fuente: http://www.cs.us.es/~fsancho/?e=107
<br/>
Ejemplo árbol combinatorio
![image](https://user-images.githubusercontent.com/121684145/210299095-9bfe7eb4-5190-4c2d-95e2-b3f48950c113.png)

#### **Movimientos con las que se puede ganar**
Se considera que el mínimo de posiciones para ganar en el tres en raya es de 5.
|Ganancia|Posibilidades de movimeintos|Probabilidad|
|--|--|--|
|` Victoria jugador 1 (O) en 5 jugadas de la partida`|1440| 0.6%|
|` Victoria jugador 1 (O) en 6 jugadas de la partida`|5328| 2.1%|
|` Victoria jugador 1 (O) en 7 jugadas de la partida`|47952| 18.8%|
|` Victoria jugador 1 (O) en 8 jugadas de la partida`|72576| 28.4%|
|` Victoria jugador 1 (O) en 9 jugadas de la partida`|81792| 32.1%|
|` Empate de los jugadores`|46080| 18.1%|
|` Total de jugadas`|255168| 100%|
#### **Explicación**
Para realizar los cálculos se considero que en 5 jugadas 8*3!*6*5 = 1440 posibilidades de que los juegos terminen en una victoria en el quinto movimiento.En 6 jugadas esto nos da 8*3!*6*5*4 = 5760 posibilidades. Para tener en cuenta el paréntesis, debemos excluir los casos en los que hay tres Os en una fila y tres X en una fila: ninguno de ellos puede ser una diagonal, y si se toma una fila en particular, solo hay otras dos filas posibles.Por lo que debemos excluir 6*3!*2*3! = 432 casos. Así que estamos viendo 5760-432 = 5328 posibilidades de que los juegos terminen en una victoria en el sexto movimiento.
# Ejecutar el código en Windows y Linux 

Para poder ejecutar el código en Linux y en Windows se recurre al uso de un entorno de desarrollo con la posibilidad de trabajar en C++, como lo es Visual Code.Lo que es el lenguaje en sí mismo, sí es igual (las estructuras de control, sentencias comunes, entre otras). El problema está en las bibliotecas y los estándares. En el caso el programa se utiliza la biblioteca bits/stdc++.h que es un archivo de encabezado no estándar de la biblioteca GNU C++, por lo que si no se usa un compilador GCC el programa no correra. En caso de no tenerlo los pasos a seguir para descargar un compilador posible son, este compilador es amigable ya que configura automáticamente la variable de entorno del sistema operativo:
1.	Ingresar a la página de tdm-gcc: https://jmeubank.github.io/tdm-gcc/download/. 
2.	Seleccionar el tipo de compilador dependiendo del tipo de sistema operativo de 34 0 62 bits
3.	Agregar el path al IDE


