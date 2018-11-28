#include "stdafx.h"
#include "../inc/SP_modify.h"
#include "../inc/global.h"
#include "../inc/copyf.h"



void SP_modify(struct st_t *sp, struct st_t * spc) {
	unsigned int modificationType = (rand() % 5);

	//the case for module orientation rotation
	if (modificationType == 0) {
		int index = randmoize_n_modules;
		//		do  {
		SPcpy(sp, spc);
		module_rotation(index, sp, spc);
		//		} while (sp->rotate_mod[index] != 1);
		//	sol_n.rot[index] = 1 - sol_n.rot[index];
	}
	else {// the case for shifted swap module
		  //If the subfunction randomly_select had returned 0 means modify only the gamma+ array 
		  //If the subfunction randomly_select had returned 1 means modify only the gamma- array 
		unsigned int f, s;
		//int n_or_p;
		unsigned int *sp_mod_array = new unsigned int[n_modules + 1];

		//n_or_p = randomly_select(sp_mod_array, &f, &s, spc);

		int spc_index;
		spc_index = randmoize_2; // x = 0 ~ 1
		f = randmoize_n_modules;
		do {
			s = randmoize_n_modules;
		} while (f == s);

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
		// means the same component arbitrarily have been chosen
		if (f == s) exit(-1);

		unsigned int temp;
		if (f < s) {
			unsigned int temp;
			temp = sp_mod_array[f];
			for (unsigned int k = f; k < s; k++) {
				sp_mod_array[k] = sp_mod_array[k + 1];
			}
			sp_mod_array[s] = temp;
		}
		else {
			unsigned int temp;
			temp = sp_mod_array[f];
			for (unsigned int k = f; k > s; k--) {
				sp_mod_array[k] = sp_mod_array[k - 1];
			}
			sp_mod_array[s] = temp;
		}


		Seqcpy(spc_index, sp_mod_array, sp, spc);

	}
}