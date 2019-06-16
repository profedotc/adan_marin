#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gol.h"

int main()
{
	int i = 0;

	// TODO: Declara dos mundos
	struct gol gol;

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

	return 0;
}

