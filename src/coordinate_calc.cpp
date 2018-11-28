#include "stdafx.h"
#include "../inc/global.h"
//#include "coordinate_calc.h"
void coordinate_calc(double * Current_width, double * Current_height, struct block *module, struct st_t *spc, unsigned int * inv_psl) {
	unsigned int l, K_ID, L_ID, K_indexPos;
	module[spc->nsl[1]].x = 0; module[spc->nsl[1]].y = 0;


	double l_width, l_height, k_width, k_height;
	K_ID = spc->nsl[1];
	*Current_width = (double)(1 - spc->rotate_mod[K_ID])*module[K_ID].w + (double)(spc->rotate_mod[K_ID]) * module[K_ID].h;
	*Current_height = (double)(spc->rotate_mod[K_ID])*module[K_ID].w + (double)(1 - spc->rotate_mod[K_ID])*module[K_ID].h;

	for (unsigned int k = 2; k <= n_modules; k++) {
		// x-coordinate of nsl[k]
		K_ID = spc->nsl[k];
		K_indexPos = inv_psl[K_ID];
		k_width = (double)(1 - spc->rotate_mod[K_ID])*module[K_ID].w + (double)(spc->rotate_mod[K_ID]) * module[K_ID].h;
		k_height = (double)(spc->rotate_mod[K_ID])*module[K_ID].w + (double)(1 - spc->rotate_mod[K_ID])*module[K_ID].h;

		for (l = 1; l < k; l++) {
			L_ID = spc->nsl[l];
			l_width = (double)(1 - spc->rotate_mod[L_ID])*module[L_ID].w + (double)(spc->rotate_mod[L_ID]) * module[L_ID].h;
			l_height = (double)(spc->rotate_mod[L_ID])*module[L_ID].w + (double)(1 - spc->rotate_mod[L_ID])*module[L_ID].h;

			if (inv_psl[L_ID] /*L_indxPos*/ < K_indexPos) { // the condition of Left_right relation

				if (module[K_ID].x < l_width + module[L_ID].x)
				{
					module[K_ID].x = l_width + module[L_ID].x;
					// to calculate the boundary / cost
					if (*Current_width < module[K_ID].x + k_width) {
						*Current_width = module[K_ID].x + k_width;
						farthest_module = K_ID;

					}
					if (*Current_height < module[K_ID].y + k_height) {
						*Current_height = module[K_ID].y + k_height;
						highest_module = K_ID;
					}
				}
			}
			else /* if (L_inPos > K_indexPos) */ {
				// the condition of Above_Below 

				if (module[K_ID].y < l_height + module[L_ID].y) {

					module[K_ID].y = l_height + module[L_ID].y;
					// to calculate the boundary / cost
					if (*Current_width < module[K_ID].x + k_width) {
						*Current_width = module[K_ID].x + k_width;
						farthest_module = K_ID;

					}
					if (*Current_height < module[K_ID].y + k_height) {
						*Current_height = module[K_ID].y + k_height;
						highest_module = K_ID;
					}
				}
			}
		}
	}
}
/*
this function is for searching if the current component is in the same order with other in both pairs
means it is in left - right relation,
if it is in reverse relation means it is in above - below relation; otherwise there is no relation.
*/