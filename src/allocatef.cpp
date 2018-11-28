#include "stdafx.h"
#include "../inc/global.h"
#include "../inc/allocatef.h"

//, &module, &inv_psl, &inv_nsl, &spc
void allocate_arrays(unsigned int  **sp_mod_array, struct block **module, unsigned int ** inv_psl, unsigned int ** inv_nsl
	, struct st_t *spc, struct st_t *spn, struct st_t* spt) {

	*module = new struct block[n_modules + 1];

	spc->psl = new unsigned int[n_modules + 1];
	spc->nsl = new unsigned int[n_modules + 1];
	spc->rotate_mod = new unsigned int[n_modules + 1];

	spn->psl = new unsigned int[n_modules + 1];
	spn->nsl = new unsigned int[n_modules + 1];
	spn->rotate_mod = new unsigned int[n_modules + 1];

	spt->psl = new unsigned int[n_modules + 1];
	spt->nsl = new unsigned int[n_modules + 1];
	spt->rotate_mod = new unsigned int[n_modules + 1];

	subgamma_pair = new char[1];

	*inv_psl = new unsigned int[n_modules + 1];
	*inv_nsl = new unsigned int[n_modules + 1];

	*sp_mod_array = new unsigned int[n_modules + 1];
}
