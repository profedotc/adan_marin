#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM_X 12
#define TAM_Y 12

void gol_init(bool mundo_1[][TAM_Y]);
void gol_print(bool mundo_1[][TAM_Y]);
void gol_step(bool mundo_1[][TAM_Y], bool mundo_2[][TAM_Y]);
int gol_count_neighbors(bool mundo_1[][TAM_Y], int x, int y);
bool gol_get_cell(bool mundo_1[][TAM_Y], int x, int y);
void gol_copy(bool mundo_1[][TAM_Y],bool mundo_2[][TAM_Y]);

int main()
{
	int i = 0;
	// TODO: Declara dos mundos
	bool mundo_1[TAM_X][TAM_Y];
	bool mundo_2[TAM_X][TAM_Y];

	// TODO: inicializa el mundo
	gol_init(mundo_1);

	do
	{
		printf("\033cIteration %d\n", i++);
		// TODO: Imprime el mundo
		gol_print(mundo_1);

		// TODO: Itera
		gol_step(mundo_1, mundo_2);
	}
	while (getchar() != 'q');

	return 0;
}

void gol_init(bool mundo_1[][TAM_Y])
{
	// TODO: Poner el mundo a false
	for(int x = 0; x < TAM_X; x++)
	{
		for(int y = 0; y < TAM_Y; y++)
		{
			mundo_1[x][y] = 0;
		}
	}

	/* TODO: Inicializar con el patrÃ³n del glider:
	 *           . # .
	 *           . . #
	 *           # # #
	 */
	mundo_1[1][2] = 1;
	mundo_1[2][3] = 1;
	mundo_1[3][1] = 1;
	mundo_1[3][2] = 1;
	mundo_1[3][3] = 1;
}

void gol_print(bool mundo_1[][TAM_Y])
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
	for (int x = 1; x < TAM_X - 1; x++)
	{
		for (int y = 1; y < TAM_Y - 1; y++)
		{
				printf("%c ", mundo_1[x][y]? '#' : '.');
		}
		printf("\n");
	}
}


void gol_step(bool mundo_1[][TAM_Y], bool mundo_2[][TAM_Y])
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
	for(int x = 1; x < TAM_X - 1; x++)
	{
		for(int y = 1; y < TAM_Y - 1; y++)
		{
			vecinas_vivas = gol_count_neighbors(mundo_1, x, y);

			if (gol_get_cell(mundo_1, x, y))
			{
				mundo_2[x][y] = (vecinas_vivas == 3) || (vecinas_vivas == 2);
			}
			else
			{
				mundo_2[x][y] = (vecinas_vivas == 3);
			}
			vecinas_vivas = 0;
		}
		//printf("\n");
	}

	gol_copy(mundo_1, mundo_2);
}

int gol_count_neighbors(bool mundo_1[][TAM_Y], int x, int y)
{
	// Devuelve el nÃºmero de vecinos
	int total_vecinas_vivas = 0;

	total_vecinas_vivas += mundo_1[x - 1][y - 1];
	total_vecinas_vivas += mundo_1[x - 1][y];
	total_vecinas_vivas += mundo_1[x - 1][y + 1];

	total_vecinas_vivas += mundo_1[x][y - 1];
	total_vecinas_vivas += mundo_1[x][y + 1];

	total_vecinas_vivas += mundo_1[x + 1][y - 1];
	total_vecinas_vivas += mundo_1[x + 1][y];
	total_vecinas_vivas += mundo_1[x + 1][y + 1];

	return total_vecinas_vivas;
}

bool gol_get_cell(bool mundo_1[][TAM_Y], int x, int y)
{
	/*
	 * TODO: Devuelve el estado de la cÃ©lula de posiciÃ³n indicada
	 * (Â¡cuidado con los lÃ­mites del array!)
	 */
	if (mundo_1[x][y])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void gol_copy(bool mundo_1[][TAM_Y], bool mundo_2[][TAM_Y])
{
	// TODO: copia el mundo segundo mundo sobre el primero
	for (int x = 1; x < TAM_X - 1; x++)
	{
		for (int y = 1; y < TAM_Y - 1; y++)
		{
			mundo_1[x][y] = mundo_2[x][y];
		}
	}

}
