#ifndef __COPYF_H
#define __COPYF_H

extern void module_rotation(int index, struct st_t *sp, struct st_t *spc);

void Seqcpy(int n_or_p, unsigned int *sp_mod_array, struct st_t *spn, struct st_t  *spc);
void SPcpy(struct st_t * sp2, struct st_t * sp1);


#endif
