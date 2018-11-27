#ifndef __MODIFICATIONF_H
#define __MODIFICATIONF_H

unsigned int * inv_def(unsigned n, unsigned int *inputarr); //Gama type decide which either Gama_Neg (1) or Gama_Pos (2) ;
void module_rotation(int index, struct st_t *sp, struct st_t *spc);
void swap_var(unsigned int *a, unsigned int *b);

#endif