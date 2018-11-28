#include "stdafx.h"
#include "../inc/global.h"

int randomly_select(unsigned int  *sp_mod_array, unsigned int *f, unsigned int *s, struct st_t  *spc) {

	int spc_index;
	spc_index = randmoize_2; // x = 0 ~ 1
	*f = randmoize_n_modules;
	do {
		*s = randmoize_n_modules;
	} while (*f == *s);

	if (spc_index == 0) {

		for (unsigned int i = 1; i <= n_modules; i++) {
			sp_mod_array[i] = spc->psl[i];
		}
	}
	else {

		for (unsigned int i = 1; i <= n_modules; i++) {
			sp_mod_array[i] = spc->nsl[i];
		}
	}
	return(spc_index);
}
void shuffle(struct st_t *spc) {
	int p_index, n_index, tp, tn;

	for (int i = 1; i <= n_modules; i++) {
		//sp psl shuffing 
		p_index = (rand() % n_modules) + 1;
		if (p_index != i) {
			tp = spc->psl[i];
			spc->psl[i] = spc->psl[p_index];
			spc->psl[p_index] = tp;
		}
		//sp nsl shuffing 
		n_index = (rand() % n_modules) + 1;
		if (n_index != i) {
			tn = spc->nsl[i];
			spc->nsl[i] = spc->nsl[n_index];
			spc->nsl[n_index] = tn;
		}
	}

}
/////

int randomly_select_multi(char *subgamma_pair, unsigned int random_count) {

	int sp_index;


	if (random_count <= 1) {
		printf("/n******random_count is not allowed******* /n "); exit;
	}

	sp_index = randmoize_2; // x = 0 ~ 1
	subgamma_pair[0] = randmoize_n_modules;


	char j, matched;
	for (int i = 1; i <= random_count; i++) {
		subgamma_pair[i] = randmoize_n_modules;
		matched = 0;
		for (j = 0; j < i; j++)
			if (subgamma_pair[i] == subgamma_pair[j]) {
				matched = 1;
				break;
			}
		if (matched) continue;
	}


	return(sp_index);
}



/////