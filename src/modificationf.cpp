#include "stdafx.h"
#include "global.h"
#include "modificationf.h"


void module_rotation(int index, struct st_t *sp, struct st_t *spc) {
	unsigned int tmp = sp->rotate_mod[index];
	sp->rotate_mod[index] = 1 - tmp;

}


void swap_var(unsigned int *a, unsigned int *b) {
	double tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/////
unsigned int * inv_def(unsigned n, unsigned int *inputarr) { //Gama type decide which either Gama_Neg (1) or Gama_Pos (2) ;
	unsigned int* outarr = new unsigned int[n + 1];																				 // sp1 = { { -1, 13,6,9,8,1,7,2,3,4,5,11,10,12 },{ -1, 4,6,11,3,10,2,12,8,1,7,9,5,13 } }
	for (int i = 1; i <= n; i++) {
		//std::cout << "inputarr[" << i << "]: " << inputarr[i] << std::endl;
		outarr[inputarr[i]] = i;
		

	}
	return outarr;
}
