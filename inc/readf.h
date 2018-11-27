#ifndef __READF_H
#define __READF_H
using namespace std;
int read_moduleConfig(char filename[]);
int read_sp_file(char * filename, struct block *module, struct st_t * spc);
int read_online_sp_file(char * filename, struct block *module, struct st_t * spc);

#endif
