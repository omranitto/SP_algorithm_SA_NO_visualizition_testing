#ifndef __PRINTF_H
#define __PRINTF_H

//char * filename, unsigned int sp_mod_array, struct block *module, struct st_t spc, struct st_t spt
int print_module(FILE *, struct block *module, struct st_t, double temp);
int print_results(struct st_t spt, double initial_boundary_width, double temp, double initial_boundary_height);
int print_parametric_study(char * filename, double temp, unsigned int c);

#endif


