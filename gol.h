#ifndef _GOL_H_

#define _GOL_H_
#include <stdbool.h>

#define TAM_A 2
#define TAM_X 10
#define TAM_Y 10

void gol_init(bool mundos[TAM_A][TAM_X][TAM_Y]);
void gol_print(bool mundos[TAM_A][TAM_X][TAM_Y], int mundo_actual);
void gol_step(bool mundos[TAM_A][TAM_X][TAM_Y], int mundo_actual);
int gol_count_neighbors(bool mundos[TAM_A][TAM_X][TAM_Y], int mundo_actual, int x, int y);
bool gol_get_cell(bool mundos[TAM_A][TAM_X][TAM_Y], int mundo_actual, int x, int y);

#endif
