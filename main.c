#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gol.h"

int main()
{
	int i = 0;

	// TODO: Declara dos mundos
	struct gol gol;
	
	bool success = gol_alloc(&gol, TAM_X, TAM_Y);
	if (!success) {
		EXIT_FAILURE;
	}

	// TODO: inicializa el mundo
	gol_init(&gol);

	do
	{
		printf("\033cIteration %d\n", i++);
		// TODO: Imprime el mundo
		gol_print(&gol);

		//~ int count = a ? 0 : 1;
		// TODO: Itera
		gol_step(&gol);
	}
	while (getchar() != 'q');
	
	gol_free(&gol);

	return 0;
}

