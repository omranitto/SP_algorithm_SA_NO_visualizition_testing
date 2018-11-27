#ifndef __INITIAL_H
#define __INITIAL_H

void initialize(unsigned int  *sp_mod_array, double *modifiedsp_cost_area, double *currentsp_cost_area, struct st_t *spt, struct st_t *spn, struct st_t *spc, double *Current_width,
	double *Current_height, struct block *module);
void initialize_coordinate(struct block *module);
void initialize_orientation(struct st_t *sp);


void set_initial_layout_boundary(double *Current_width, double *Current_height, double *initial_boundary_width, double *initial_boundary_height, struct block *module);



#endif

