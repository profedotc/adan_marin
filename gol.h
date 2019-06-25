#ifndef _GOL_H_

#define _GOL_H_
#include <stdbool.h>

#define TAM_A 2
#define TAM_X 10
#define TAM_Y 10

struct gol {
	bool mundos[TAM_A][TAM_X][TAM_Y];
	unsigned int mundo_actual;
};

void gol_init(struct gol *gol);
void gol_print(const struct gol *gol);
void gol_step(struct gol *gol);
int gol_count_neighbors(const struct gol *gol, int x, int y);
bool gol_get_cell(const struct gol *gol, int x, int y);

#endif
