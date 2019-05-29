#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM_A 2
#define TAM_X 10
#define TAM_Y 10

void gol_init(bool mundos[TAM_A][TAM_X][TAM_Y]);
void gol_print(bool mundos[TAM_A][TAM_X][TAM_Y], int a);
void gol_step(bool mundos[TAM_A][TAM_X][TAM_Y], int a, int count);
int gol_count_neighbors(bool mundos[TAM_A][TAM_X][TAM_Y], int x, int y, int count);
bool gol_get_cell(bool mundos[TAM_A][TAM_X][TAM_Y], int x, int y, int count);

int main()
{
	int i = 0;
	int a = 0;
	// TODO: Declara dos mundos
	bool mundos[TAM_A][TAM_X][TAM_Y];

	// TODO: inicializa el mundo
	gol_init(mundos);

	do
	{
		printf("\033cIteration %d\n", i++);
		// TODO: Imprime el mundo
		gol_print(mundos, a);

		int count = a ? 0 : 1;
		// TODO: Itera
		gol_step(mundos, a, count);
		a = count;
	}
	while (getchar() != 'q');

	return 0;
}

void gol_init(bool mundos[TAM_A][TAM_X][TAM_Y])
{
	// TODO: Poner el mundo a false
	for (int a = 0; a < 2; a++)
	{
		for(int x = 0; x < TAM_X; x++)
		{
			for(int y = 0; y < TAM_Y; y++)
			{
				mundos[a][x][y] = 0;
			}
		}
	}

	/* TODO: Inicializar con el patrÃ³n del glider:
	 *           . # .
	 *           . . #
	 *           # # #
	 */
	mundos[0][0][1] = 1;
	mundos[0][1][2] = 1;
	mundos[0][2][0] = 1;
	mundos[0][2][1] = 1;
	mundos[0][2][2] = 1;
}

void gol_print(bool mundos[TAM_A][TAM_X][TAM_Y], int a)
{
	// TODO: Imprimir el mundo por consola. Sugerencia:
	/*
	 *     . # . . . . . . . .
	 *     . . # . . . . . . .
	 *     # # # . . . . . . .
	 *     . . . . . . . . . .
	 *     . . . . . . . . . .
	 *     . . . . . . . . . .
	 *     . . . . . . . . . .
	 *     . . . . . . . . . .
	 *     . . . . . . . . . .
	 *     . . . . . . . . . .
	 */
	for (int x = 0; x < TAM_X; x++)
	{
		for (int y = 0; y < TAM_Y; y++)
		{
				printf("%c ", mundos[a][x][y]? '#' : '.');
		}
		printf("\n");
	}
}


void gol_step(bool mundos[TAM_A][TAM_X][TAM_Y], int a, int count)
{
	/*
	 * TODO:
	 * - Recorrer el mundo cÃ©lula por cÃ©lula comprobando si nace, sobrevive
	 *   o muere.
	 *
	 * - No se puede cambiar el estado del mundo a la vez que se recorre:
	 *   Usar un mundo auxiliar para guardar el siguiente estado.
	 *
	 * - Copiar el mundo auxiliar sobre el mundo principal
	 */
	int vecinas_vivas = 0;
	for(int x = 0; x < TAM_X; x++)
	{
		for(int y = 0; y < TAM_Y; y++)
		{
			vecinas_vivas = gol_count_neighbors(mundos, a, x, y);

			if (gol_get_cell(mundos, a, x, y))
			{
				mundos[count][x][y] = (vecinas_vivas == 3) || (vecinas_vivas == 2);
			}
			else
			{
				mundos[count][x][y] = (vecinas_vivas == 3);
			}
			vecinas_vivas = 0;
		}
	}

}

int gol_count_neighbors(bool mundos[TAM_A][TAM_X][TAM_Y], int a, int x, int y)
{
	// Devuelve el nÃºmero de vecinos
	int total_vecinas_vivas = 0;

	total_vecinas_vivas += gol_get_cell(mundos, a, x - 1, y - 1);
	total_vecinas_vivas += gol_get_cell(mundos, a, x - 1, y);
	total_vecinas_vivas += gol_get_cell(mundos, a, x - 1, y + 1);

	total_vecinas_vivas += gol_get_cell(mundos, a, x, y - 1);
	total_vecinas_vivas += gol_get_cell(mundos, a, x, y + 1);

	total_vecinas_vivas += gol_get_cell(mundos, a, x + 1, y - 1);
	total_vecinas_vivas += gol_get_cell(mundos, a, x + 1, y);
	total_vecinas_vivas += gol_get_cell(mundos, a, x + 1, y + 1);
	
	return total_vecinas_vivas;
}

bool gol_get_cell(bool mundos[TAM_A][TAM_X][TAM_Y], int a, int x, int y)
{
	/*
	 * TODO: Devuelve el estado de la cÃ©lula de posiciÃ³n indicada
	 * (Â¡cuidado con los lÃ­mites del array!)
	 */
	if ( (x < 0) || (x > (TAM_X - 1)) || (y < 0) || (y > (TAM_Y - 1)) )
	{
		return 0;
	}
	else
	{
		return mundos[a][x][y];
	}
}	
