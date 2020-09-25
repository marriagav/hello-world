"""""
Autores: Miguel
Arriaga
y
Pablo
Rocha
Fecha: 17 / 04 / 2020
Descripción: Situación
problema: juego
de
memoria
"""
import random

# Variables
coordenadas = [0, 1, 2, 3, 4, 5]
tablero = [[0] * 6, [0] * 6, [0] * 6, [0] * 6, [0] * 6, [0] * 6]
printedBoard = [["-"] * 6, ["-"] * 6, ["-"] * 6, ["-"] * 6, ["-"] * 6, ["-"] * 6]
cartas = [0] * 36
turno = [1, 2]
renglonCarta1 = 0
renglonCarta2 = 0
columnaCarta1 = 0
columnaCarta2 = 0
puntos = [0, 0]
seguirJugando = ""


# contExtra = 0 - se usa adentro de una función
# conX y cont Y se utilizan adentro de una función
# carta se utiliza adentro de una función

# Aquí empieza el código
def main():
    build()
    printboard()
    turns()
    ganador()

# ----función para construcción de tablero
def build():
    for contExtra in range(0, len(cartas), 1):  # ----llenar la lista "cartas"
        if contExtra < 18:
            cartas[contExtra] += contExtra + 1
        else:  # ----para repetir cada carta
            cartas[contExtra] = len(cartas) - contExtra
        # fin del if
    for contY in range(0, len(tablero), 1):
        for contX in range(0, len(tablero[contY]), 1):
            random.shuffle(cartas)  # ----se revuelven las cartas
            carta = cartas.pop()  # ----sacamos la ultima
            tablero[contY][contX] = carta  # ----asignamos el valor de la carta al tablero
        # fin loop x
    # fin loop y

# fin de la funcion build

# ----función para imprimir el tablero
def printboard():
    print(end="\t")
    for contY in range(0, len(tablero), 1):
        if contY == 0:  # ----imprime la primera fila con las coordenadas Y
            for contX in range(0, len(tablero[contY]), 1):
                print(coordenadas[contX], end="\t")
            print()
            # fin loop x1
        # fin if
        for contX in range(0, len(tablero[contY]), 1):
            if contX == 0:  # ----imprimir la columna con coordenadas X
                print()
                print(coordenadas[contY], end="\t")
            # fin if
            print(printedBoard[contY][contX], end="\t")
        print()

# ----función para tomar turnos
def turns():
    global renglonCarta1
    global renglonCarta2
    global columnaCarta1
    global columnaCarta2
    global seguirJugando
    contExtra = 0
    while "-" in printedBoard[0 or 1 or 2 or 3 or 4 or 5]:  # si descubren todas las cartas se rompe el loop
        # pide coordenadas primera carta
        print("Turno del jugador ", turno[contExtra])
        renglonCarta1 = input("Renglon de primera carta:")
        columnaCarta1 = input("Columna de primera carta:")
        try:
            renglonCarta1 = int(renglonCarta1)
            columnaCarta1 = int(columnaCarta1)
        except:
            print("Eso no en un número!")
            continue
        if renglonCarta1 > 5 or columnaCarta1 > 5:  # excepción cuando dan un número mayor al tablero
            print("Ese número es mayor al del tablero")
            continue
        # fin loop
        if tablero[renglonCarta1][columnaCarta1] == printedBoard[renglonCarta1][
            columnaCarta1]:  # excepción cuando dan una carta ya volteada
            print("Esa carta ya está volteada")
            continue
        # fin loop
        print("Elegiste la carta: ", tablero[renglonCarta1][columnaCarta1])
        # pide coordenadas segunda carta
        renglonCarta2 = int(input("Renglon de segunda carta:"))
        columnaCarta2 = int(input("Columna de segunda carta:"))
        while renglonCarta2 > 5 or columnaCarta2 > 5:  # excepción cuando dan un número mayor al tablero
            renglonCarta2 = int(input("Renglon de segunda carta:"))
            columnaCarta2 = int(input("Columna de segunda carta:"))
        # fin loop
        while renglonCarta1 == renglonCarta2 and columnaCarta1 == columnaCarta2:  # excepción cuando eligen la misma
            # carta
            renglonCarta2 = int(input("Renglon de segunda carta:"))
            columnaCarta2 = int(input("Columna de segunda carta:"))
        # fin loop
        while tablero[renglonCarta2][columnaCarta2] == printedBoard[renglonCarta2][
            columnaCarta2]:  # excepción cuando dan una carta ya volteada
            renglonCarta2 = int(input("Renglon de segunda carta:"))
            columnaCarta2 = int(input("Columna de segunda carta:"))
        # fin loop
        print("Elegiste la carta: ", tablero[renglonCarta2][columnaCarta2])

        if tablero[renglonCarta1][columnaCarta1] == tablero[renglonCarta2][columnaCarta2]:  # cuando consigue un par
            printedBoard[renglonCarta1][columnaCarta1] = tablero[renglonCarta1][columnaCarta1]
            printedBoard[renglonCarta2][columnaCarta2] = tablero[renglonCarta2][columnaCarta2]
            puntos[contExtra] += 1  # suma un punto al jugador
            contExtra = contExtra #si consigue un par, le vuelve a tocar
        else:  # cambia el turno al otro jugador
            if contExtra == 0:
                contExtra = 1
            elif contExtra == 1:
                contExtra = 0
            # fin del elif
        # end del if
        printboard()  # imprimir tablero actualizado
        seguirJugando = input("¿Quieres seguir jugando? (s/n) ")  # pregunta si quieren seguir jugando
        if seguirJugando == "n":
            break

# función para determinar al ganador
def ganador():
    if "-" in printedBoard[0 or 1 or 2 or 3 or 4 or 5]: #cuando ya no quieren seguir jugando
        print("El jugador #1 tiene ", puntos[0], " puntos.", "El jugador #2 tiene ", puntos[1], " puntos.")
    elif puntos[0] > puntos[1]:#cuando se acaban las cartas
        print("Ya se terminó el juego.")
        print("El ganador es el jugador #1 con ", puntos[0], " puntos.")
    elif puntos[1] > puntos[0]:
        print("Ya se terminó el juego.")
        print("El ganador es el jugador #2 con ", puntos[1], " puntos.")
    elif puntos[0] == puntos[1]:#empate
        print("Ya se terminó el juego.")
        print("Es un empate con ", puntos[0], " puntos.")


main()