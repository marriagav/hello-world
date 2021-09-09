Cuando main.cpp se ejecuta, se le piden al usuario los datos necesarios para configurar y crear un juego.
Se utilizó herencia, ya que las clases AutomaticGame y ManualGame son clases derivadas de myGame.
Además, se utilizó polimorfismo, ya que dentro de la clase myGame, existe la función virtual pura
startGame(). Esta se redefine en las clases derivadas de myGame y en main() se utiliza un apuntador para
que la función startGame() se comporte acorde a la clase que se cree.
El programa corre y compila correctamente. Sin embargo, cuando se utilizan valores exagerados como 1000 tiles o 
20 jugadores, el juego puede crashear.

Actualización: se implementó sobrecarga de operadores. Se sobrecargó el operador "+" para poder calcular la posición final 
a partir de dos casillas. Tomando en cuenta su tipo de casilla.  Además se cobrecargó el operador "<<" para imprimir cada turno de
la forma en la que se indicó. Esto se hizo con una nueva clase de turno.

El manejo de excepciones se implementó en la funcionalidad de juego manual. En esta modalidad, se le pide al
usuario que realize una accion (1=tirar ó 2=salir), se utilizó el manejo de excepciones para asegurarse de que 
el usuario introduzca un número que sea únicamente 1 o 2.

Output de funcionamiento correcto:

Configuración del juego:
Tipo de juego (M) Manual o (A) Automático: A
Número total de casillas: 30
Número de escaleras: 3
Número de serpientes: 3
Bonus por escalera: 3
Castigo por serpiente: 3
Número de lados del dado: 6
Número de jugadores: 2
Número total de turnos: 30
Board:
1-N 2-N 3-N 
4-N 5-N 6-N 
7-N 8-N 9-N 
10-N 11-N 12-L 
13-N 14-N 15-L 
16-N 17-S 18-N 
19-N 20-N 21-S 
22-N 23-N 24-N 
25-N 26-L 27-N 
28-S 29-N 30-N 
----------------
Game:
1 1 1 6 N 7
2 2 1 5 N 6
3 1 7 1 N 8
4 2 6 1 N 7
5 1 8 5 N 13
6 2 7 5 L 15
7 1 13 6 N 19
8 2 15 3 N 18
9 1 19 4 N 23
10 2 18 4 N 22
11 1 23 3 L 29
12 2 22 3 N 25
13 1 29 3 N 30
 
The game ends. Player number 1 won!