#ifndef __CHAINIDENTIFIER_H
#define __CHAINIDENTIFIER_H

int chain_set(struct sub_array *chain, char *gamma_pair, unsigned int random_count, struct st_t  *spt);
int correspond_Pair_search(char *sblo_pairarray, struct sub_array *chain, unsigned int random_count);


#endif
