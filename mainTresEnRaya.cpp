// Programa en C++ para jugar tres en raya

#include<bits/stdc++.h>
using namespace std;

#define COMPUTER 1
#define HUMAN 2

#define SIDE 3 // Medida del tablero

// El computador va a mover con 'O'
// y el humano con 'X'
#define COMPUTERMOVE 'O'
#define HUMANMOVE 'X'

// Funcion que muestra el status actual del tablero
void showBoard(char board[][SIDE])
{

	printf("\t\t\t %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
	printf("\t\t\t-----------\n");
	printf("\t\t\t %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
	printf("\t\t\t-----------\n");
	printf("\t\t\t %c | %c | %c \n\n", board[2][0], board[2][1], board[2][2]);
}

// Funcion que muestra las instrucciones
void showInstructions()
{
	printf("\nElija una celda del 1 al 9 como se indica a continuación y juegue\n\n");

	printf("\t\t\t 1 | 2 | 3 \n");
	printf("\t\t\t-----------\n");
	printf("\t\t\t 4 | 5 | 6 \n");
	printf("\t\t\t-----------\n");
	printf("\t\t\t 7 | 8 | 9 \n\n");
}


// Funcion para incializar el juego
void initialise(char board[][SIDE])
{
	// Inicialmente el tablero está vacío
	for (int i=0; i<SIDE; i++)
	{
		for (int j=0; j<SIDE; j++)
			board[i][j] = ' ';
	}
}

// Funcion para declarar el ganador del juego
void declareWinner(int whoseTurn)
{
	if (whoseTurn == COMPUTER)
		printf("La computadora GANO\n");
	else
		printf("Humano GANO\n");
}

// Una función que devuelve true si alguna de las filas
// se cruza con la jugada del mismo jugador
bool rowCrossed(char board[][SIDE])
{
	for (int i=0; i<SIDE; i++)
	{
		if (board[i][0] == board[i][1] &&
			board[i][1] == board[i][2] &&
			board[i][0] != ' ')
			return (true);
	}
	return(false);
}

// Una función que devuelve true si alguna de las columnas
// se cruza con la jugada del mismo jugador
bool columnCrossed(char board[][SIDE])
{
	for (int i=0; i<SIDE; i++)
	{
		if (board[0][i] == board[1][i] &&
			board[1][i] == board[2][i] &&
			board[0][i] != ' ')
			return (true);
	}
	return(false);
}

// Una función que devuelve true si alguna de las diagonales
// se cruza con la jugada del mismo jugador
bool diagonalCrossed(char board[][SIDE])
{
	if (board[0][0] == board[1][1] &&
		board[1][1] == board[2][2] &&
		board[0][0] != ' ')
		return(true);

	if (board[0][2] == board[1][1] &&
		board[1][1] == board[2][0] &&
		board[0][2] != ' ')
		return(true);

	return(false);
}

// Una funcion que regresa true si eljuego se acaba
// caso contrario regresa false
bool gameOver(char board[][SIDE])
{
	return(rowCrossed(board) || columnCrossed(board) || diagonalCrossed(board) );
}

// Funcion que calcula el mejor score
int minimax(char board[][SIDE], int depth, bool isAI)
{
	int score = 0;
	int bestScore = 0;
	if (gameOver(board) == true)
	{
		if (isAI == true)
			return -1;
		if (isAI == false)
			return +1;
	}
	else
	{
		if(depth < 9)
		{
			if(isAI == true)
			{
				bestScore = -999;
				for(int i=0; i<SIDE; i++)
				{
					for(int j=0; j<SIDE; j++)
					{
						if (board[i][j] == ' ')
						{
							board[i][j] = COMPUTERMOVE;
							score = minimax(board, depth + 1, false);
							board[i][j] = ' ';
							if(score > bestScore)
							{
								bestScore = score;
							}
						}
					}
				}
				return bestScore;
			}
			else
			{
				bestScore = 999;
				for (int i = 0; i < SIDE; i++)
				{
					for (int j = 0; j < SIDE; j++)
					{
						if (board[i][j] == ' ')
						{
							board[i][j] = HUMANMOVE;
							score = minimax(board, depth + 1, true);
							board[i][j] = ' ';
							if (score < bestScore)
							{
								bestScore = score;
							}
						}
					}
				}
				return bestScore;
			}
		}
		else
		{
			return 0;
		}
	}
}

// Funcion que calcula el mejor movimiento
int bestMove(char board[][SIDE], int moveIndex)
{
	int x = -1, y = -1;
	int score = 0, bestScore = -999;
	for (int i = 0; i < SIDE; i++)
	{
		for (int j = 0; j < SIDE; j++)
		{
			if (board[i][j] == ' ')
			{
				board[i][j] = COMPUTERMOVE;
				score = minimax(board, moveIndex+1, false);
				board[i][j] = ' ';
				if(score > bestScore)
				{
					bestScore = score;
					x = i;
					y = j;
				}
			}
		}
	}
	return x*3+y;
}

// Una funcion para jugar Tres en raya
void playTresEnRaya(int whoseTurn)
{
	char board[SIDE][SIDE];
	int moveIndex = 0, x = 0, y = 0;

	initialise(board);
	showInstructions();

	// Sigue jugando hasta que el juego termine o haya un empate.
	while (gameOver(board) == false && moveIndex != SIDE*SIDE)
	{
		int n;
		if (whoseTurn == COMPUTER)
		{
			n = bestMove(board, moveIndex);
			x = n / SIDE;
			y = n % SIDE;
			board[x][y] = COMPUTERMOVE;
			printf("COMPUTER ha puesto un %c en la celda %d\n\n", COMPUTERMOVE, n+1);
			showBoard(board);
			moveIndex ++;
			whoseTurn = HUMAN;
		}

		else if (whoseTurn == HUMAN)
		{
			printf("Puede insertar en las siguientes posiciones : ");
			for(int i=0; i<SIDE; i++)
				for (int j = 0; j < SIDE; j++)
					if (board[i][j] == ' ')
						printf("%d ", (i * 3 + j) + 1);
			printf("\n\nIngrese la posicion = ");
			scanf("%d",&n);
			n--;
			x = n / SIDE;
			y = n % SIDE;
			if(board[x][y] == ' ' && n<9 && n>=0)
			{
				board[x][y] = HUMANMOVE;
				printf ("\nHUMANO a puesto un %c en la celda %d\n\n", HUMANMOVE, n+1);
				showBoard(board);
				moveIndex ++;
				whoseTurn = COMPUTER;
			}
			else if(board[x][y] != ' ' && n<9 && n>=0)
			{
				printf("\nLa posicion esta� ocupada, seleccione una casilla cualquiera de las disponibles\n\n");
			}
			else if(n<0 || n>8)
			{
				printf("Posicion invalida\n");
			}
		}
	}

	// Si el juego ha empatado
	if (gameOver(board) == false && moveIndex == SIDE * SIDE)
		printf("EMPATE\n");
	else
	{
		// Toggling the user to declare the actual winner
		if (whoseTurn == COMPUTER)
			whoseTurn = HUMAN;
		else if (whoseTurn == HUMAN)
			whoseTurn = COMPUTER;

		declareWinner(whoseTurn);
	}
	}
	int main()  
	{  
     int opcion;
	 opcion=4;
	 while (opcion !=3)
	 {
		printf("JUEGO TRES EN RAYA COMPUTADORA VS JUDAGOR\nMenú principal\nOpciones: \n1.Computador\n2.Jugador\n3.Salir\n");
		printf("Selecione el participante que comienza o salir del juego:");
      	scanf("%i",&opcion);
		switch (opcion)
		{
		case 1:
			playTresEnRaya(COMPUTER); 
			break;
		case 2:
			playTresEnRaya(HUMAN); 
			break;
	    case 3:
			printf("Fin del juego"); 
			break;
		
		default:
			printf("Opcion no permitida");
			break;
		}
	 }

    return (0);  
	}  

