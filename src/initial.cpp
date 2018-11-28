#include "stdafx.h"
#include "../inc/global.h"
#include "../inc/initial.h"



void initialize(unsigned int  *sp_mod_array, double *modifiedsp_cost_area, double *currentsp_cost_area, struct st_t *spt, struct st_t *spn, struct st_t *spc, double *Current_width,
	double *Current_height, struct block *module)
{
	unsigned int k;
	unsigned int tmp;
	*modifiedsp_cost_area = 0;

	*currentsp_cost_area = *Current_width = *Current_height = 0;

	//Flush the random seed
	srand((unsigned)time(NULL));

	module[0].id = -1;
	module[0].h = -1;
	module[0].w = -1;
	module[0].x = -1;
	module[0].y = -1;
	module[0].rotated = 0;
	module[0].con_cnt = -1;
	module[0].connections = NULL;

	for (k = 0; k <= n_modules; k++)
	{
		module[k].id = k;
		module[k].x = 0.0;
		module[k].y = 0.0;
		module[k].w = 0.0;
		module[k].h = 0.0;
		module[k].con_cnt = 0;
		module[k].connections = NULL;
		spc->psl[k] = 0;
		spn->psl[k] = 0;
		spt->psl[k] = 0;
		spc->nsl[k] = 0;
		spn->nsl[k] = 0;
		spt->nsl[k] = 0;

		sp_mod_array[k] = 0;
	}

}
//////////////////////

void initialize_coordinate(struct block *module)
{
	unsigned int k;

	module[0].x = -1;
	module[0].y = -1;


	for (k = 0; k <= n_modules; k++)
	{
		module[k].x = 0.0;
		module[k].y = 0.0;
	}

}
void initialize_orientation(struct st_t *sp)
{
	unsigned int k;


	sp->rotate_mod[0] = -1;


	for (k = 0; k <= n_modules; k++)
	{
		sp->rotate_mod[k] = 0;

	}

}
///////

void set_initial_layout_boundary(double  *Current_width, double *Current_height, double *initial_boundary_width, double *initial_boundary_height, struct block *module) {
	*initial_boundary_width = *initial_boundary_height = 0;
	unsigned int i;


	for (i = 1; i <= n_modules; i++) {
		*initial_boundary_width = *initial_boundary_width + module[i].w;
		if (module[i].h > *initial_boundary_height)
			*initial_boundary_height = module[i].h;
	}
	*Current_width = *initial_boundary_width;
	*Current_height = *initial_boundary_height;
}