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
    Para esta clase, las funcionalidades de puedeTirar que verifica si se puede tirar una ficha en cierta columna dada por el usuario, bot o IA, soltarFicha que como su nombre indica suelta la ficha en la columna previamente seleccionada y verificada por el programa, comprobarGanador que comprueba si existe un ganador en los 4 estados posibles (vertical, horizontal, diagonal y diagonal inversa), comprobarEmpate que comprueba si existe un empate si el tablero está lleno y no se comprobó un ganador, mostrarTablero que muestra el tablero, así como las de getFilas, columnas, colorFicha y setTablero fueron implementadas por Aarón Arce.
    Sebastián Orozco implementó la funcionalidad de reiniciarTablero, la cual reinicia el tablero previamente jugado a uno con sus campos vacíos.
    Jose Guerra implementó las funcionalidades de setVictorias y getVictorias para las fichas rojas y azules, asl cuales da la cantidad de victorias de ambos jugadores en base a las fichas.
Clase JugadorHumano:
    Las funcionalidades hechas en dicha clase fueron implementadas por Sebastián Orozco, dichas funcionalidades son los get del nombre del jugador y el color de la ficha del mismo, la funcionalidad de seleccionar columna, la cual tiene throw exception por si no se cumple con lo esperado y devuelve el numero de la columna a seleccionar.
Clase JugadorIAFacil:
    Las funcionalidades realizadas en esta clase, fueron implementadas por Sebastián Orozco, estas funcionalidades son los métodos que hereda de IJugador, además del método seleccionar columna el cual devuelve un número random en el rango de las columnas previamente seteadas en el programa, para que este se suelte en el tablero.
Clase JugadorIAInteligente:
Clase MenuFrame:
Clase TableroFrame:
    La funcionalidad de dibujarTablero fue implementada por Aarón Arce, esta funcionalidad permite dibujar el tablero en una ventana aparte del menú de la interfaz.
    También la funcionalidad del evento del mouse con el click izquierdo para dibujar la ficha en la columna presionada fue implementada por Aarón Arce.
Clase main:
    Esta clase llama a MenuFrame para que se imprima el menú del juego y el tablero, estas funcionalidades fueron implementadas tanto por Sebastián Orozco y Aarón Arce.
Clase main2:
    Todas las funcionalidades vistas en el código de main2 fueron implementadas por Jose Guerra para realizar el andamiaje.
iv.
#Si no da tiempo, añadir que no se pudo terminar de implementar la interfaz :c

v. Algunos errores conocidos son los siguientes:
    1. Error de si el jugadorHumano ingresa algo que no sea un número, el programa lanzará una excepción de error que vuelva a ingresar un numero.
    2. Si una columna está llena y el jugador quiere ingresar una ficha en dicha columna, el programa lanzará una excepción de que el movimiento es inválido y le solicitará al usuario que digite una nueva columna..
    3. Si el jugadorHumano quiere ingresar una columna fuera del rango de la cantidad de columnas previamente dicho, el programa lanzará una excepcion de que el movimiento es inválido y le solicitará al usuario que digite una nueva columna.

vi. Para ejecutar las pruebas se deben seguir los siguientes comandos:
    1. cd build/tests
    2. ctest
    o
    2. ./unit_tests

