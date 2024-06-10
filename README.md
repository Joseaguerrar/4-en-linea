4-en-linea

Integrantes:
Jose Guerra Rodríguez C33510

Aarón Arce Alfaro C30601

Sebastián Orozco Castillo C35719

i. Para compilar el programa, se deben seguir los siguientes comandos:
    1. cmake -S . -B build -G Ninja
    2. cmake --build build
*Si se quiere ejecutar la interfaz
    3. ./build/src/PlantillaWxWidgets
*Si se quiere ejecutar el andamiaje
    3. ./build/src/ANDAMIAJE

ii. Para usar el programa depende si se quiere utilizar la interfaz o el andamiaje
*Para utilizar la interfaz:
    TO DO: Instrucciones para cuando se quiere usar la interfaz
*Para utilizar el andamiaje:
    1. Primeramente se abrirá un primer menú de si se quiere jugar (presione 1) o quiere salir (presione 2).
    2. Si quiere jugar, al presionar 1 se le abrirá otro menú con las distintas opciones de juego a elegir o si quiere volver al menú principal de jugar/salir.
    3. Para todos los modos de juego, se le pedirá a el o los usuarios que pongan el nombre de los jugadores, bots o IA´s y el numero de filas y columnas del tablero con el que quieren jugar.
    4. Si el o los usuarios quieren jugar en un modo donde se involucre a almenos una IA, este también deberá indicar de que dificultad/profundidad quiere que sea la IA con la que desea jugar.
    5. Si el juego involucra almenos a un humano, el propio juego le indicará que escoja una columna dentro del número que fueron establecidas para que asi juegue.
    6. Ya luego de esto depende de los jugadores, bots o IA´s en si ganan, pierden o llegan a un empate.
    7. Sea cual sea el resultado, al final a los jugadores se le mostrará un mensaje en si quieren volver a jugar o no, si quieren jugar de nuevo se volverá a crear una nueva partida, si no quiere volver a jugar, el juego lo llevará al menú del punto 2.

iii.
Clase Tablero:
    Para esta clase, las funcionalidades de puedeTirar, soltarFicha, comprobarGanador, comprobarEmpate, mostrarTablero, así como las de getFilas, columnas, colorFicha y setTablero fueron implementadas por Aarón Arce.
    Sebastián Orozco implementó la funcionalidad de reiniciarTablero.
    Jose Guerra implementó las funcionalidades de setVictorias y getVictorias para las fichas rojas y azules.
Clase IJugador:
Clase JugadorHumano:
Clase JugadorIAFacil:
Clase JugadorIAInteligente:
Clase MenuFrame:
Clase TableroFrame:
    La funcionalidad de dibujarTablero fue implementada por Aarón Arce, esta funcionalidad permite dibujar el tablero en una ventana aparte del menú de la interfaz.
    
Clase main:
Clase main3: