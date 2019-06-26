#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gol.h"

static int count_neighbors(const struct gol *gol, int x, int y);
static bool get_cell(const struct gol *gol, int x, int y);

void gol_init(struct gol *gol)
{
	gol->mundo_actual = 0;

	// TODO: Poner el mundo a false
	for (int a = 0; a < TAM_A; a++)
	{
		for(int x = 0; x < TAM_X; x++)
		{
			for(int y = 0; y < TAM_Y; y++)
			{
				gol->mundos[a][x][y] = 0;
			}
		}
	}

	/* TODO: Inicializar con el patrÃ³n del glider:
	 *           . # .
	 *           . . #
	 *           # # #
	 */
	gol->mundos[0][0][1] = 1;
	gol->mundos[0][1][2] = 1;
	gol->mundos[0][2][0] = 1;
	gol->mundos[0][2][1] = 1;
	gol->mundos[0][2][2] = 1;
}

void gol_print(const struct gol *gol)
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
				printf("%c ", gol->mundos[gol->mundo_actual][x][y]? '#' : '.');
		}
		printf("\n");
	}
}


void gol_step(struct gol *gol)
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
			vecinas_vivas = count_neighbors(gol, x, y);

			if (get_cell(gol, x, y))
			{
				gol->mundos[!gol->mundo_actual][x][y] = (vecinas_vivas == 3) || (vecinas_vivas == 2);
			}
			else
			{
				gol->mundos[!gol->mundo_actual][x][y] = (vecinas_vivas == 3);
			}
			vecinas_vivas = 0;
		}
	}
	gol->mundo_actual = !gol->mundo_actual;
}

static int count_neighbors(const struct gol *gol, int x, int y)
{
	// Devuelve el nÃºmero de vecinos
	int total_vecinas_vivas = 0;

	total_vecinas_vivas += get_cell(gol, x - 1, y - 1);
	total_vecinas_vivas += get_cell(gol, x - 1, y);
	total_vecinas_vivas += get_cell(gol, x - 1, y + 1);

	total_vecinas_vivas += get_cell(gol, x, y - 1);
	total_vecinas_vivas += get_cell(gol, x, y + 1);

	total_vecinas_vivas += get_cell(gol, x + 1, y - 1);
	total_vecinas_vivas += get_cell(gol, x + 1, y);
	total_vecinas_vivas += get_cell(gol, x + 1, y + 1);
	
	return total_vecinas_vivas;
}

static bool get_cell(const struct gol *gol, int x, int y)
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
		return gol->mundos[gol->mundo_actual][x][y];
	}
}	
