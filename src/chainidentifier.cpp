#include "stdafx.h"
#include "global.h"
#include "modificationf.h"
#include "array_arrange.h"

int chain_set(struct sub_array *chain, char *gamma_pair, unsigned int random_count, struct st_t  *spt) {

	int chainarr_size;
	double chainarr_nsl;

	chainarr_size = (int)(0.1 + rand() * 0.9) * n_modules;
	*subgamma_pair = randomly_select_multi(gamma_pair, random_count);

	chain->sblo = new unsigned int[random_count + 1];
	chain->index = new unsigned int[random_count + 1];
	chain->rotate_mod = new unsigned int[random_count + 1];

	for (int i = 1; i <= random_count; i++)
	{
		*chain->sblo = spt->psl[gamma_pair[i]];
		*chain->index = gamma_pair[i];
		*chain->rotate_mod = spt->rotate_mod[gamma_pair[i]];
	}

	return(0);
}
/*int correspond_Pair_search(char *sblo_pairarray, struct sub_array *chain, unsigned int random_count) {

inv_def(inv_sblo, &chain);
sp2->nsl[i] = sp1->nsl[i];

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
}*/