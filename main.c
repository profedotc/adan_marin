#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gol.h"

int main()
{
	int i = 0;
	int mundo_actual = 0;
	// TODO: Declara dos mundos
	bool mundos[TAM_A][TAM_X][TAM_Y];

	// TODO: inicializa el mundo
	gol_init(mundos);

	do
	{
		printf("\033cIteration %d\n", i++);
		// TODO: Imprime el mundo
		gol_print(mundos, mundo_actual);

		//~ int count = a ? 0 : 1;
		// TODO: Itera
		gol_step(mundos, mundo_actual);
		mundo_actual = !mundo_actual;
	}
	while (getchar() != 'q');

	return 0;
}

