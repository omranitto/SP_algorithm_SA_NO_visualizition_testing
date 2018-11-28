#include "stdafx.h"
#include "../inc/global.h"
#include "../inc/copyf.h"

void SPcpy(struct st_t * sp2, struct st_t * sp1) { //copy SP order from one struct array to another
												   //struct sp_t spc = { { -1, 13,6,9,8,1,7,2,3,4,5,11,10,12 },{ -1, 4,6,11,3,10,2,12,8,1,7,9,5,13 } };

	for (unsigned int i = 0; i <= n_modules; i++) {
		sp2->psl[i] = sp1->psl[i];
		sp2->nsl[i] = sp1->nsl[i];
		sp2->rotate_mod[i] = sp1->rotate_mod[i];

	}
}

void Seqcpy(int n_or_p, unsigned int *sp_mod_array, struct st_t *spn, struct st_t  *spc) { //copy a normal copy for the current SP order for later step to modify SP order
	unsigned int i = 0;
	if (n_or_p == 0) {
		for (i = 0; i < n_modules + 1; i++) {

			spn->psl[i] = sp_mod_array[i];

			spn->nsl[i] = spc->nsl[i];

			spn->rotate_mod[i] = spc->rotate_mod[i];
		}
	}
	else
		for (i = 0; i < n_modules + 1; i++) {

			spn->psl[i] = spc->psl[i];

			spn->nsl[i] = sp_mod_array[i];

			spn->rotate_mod[i] = spc->rotate_mod[i];
		}
}