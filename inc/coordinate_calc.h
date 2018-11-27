#ifndef __COORDINATE_CALC_H
#define __COORDINATE_CALC_H

extern void module_rotation(int index, struct st_t *sp, struct st_t *spc);

void coordinate_calc(double *Current_width, double *Current_height, struct block *module, struct st_t *spc, unsigned int * inv_psl);


#endif