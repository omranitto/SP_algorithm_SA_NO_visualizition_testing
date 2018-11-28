#include "C:\Users\kaneko-lab\Desktop\SP_algorithm_SA_NO_visualizition_testing__version_22Nov\stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include<iostream> 
#include<fstream> 
#include<string>
#include<sstream>
#include<vector>
//#include "SP_modify.h"

#define randmoize_n_modules rand() % n_modules + 1
#define randmoize_2 rand() % 2
#define randmoize_10 rand() % 10
//#define width (1-sp->rotate_mod[l])*w + sp->rotate_mod[l]*h
//#define height (sp->rotate_mod[l])*w + (1-sp->rotate_mod[l])*h



// Declaration of Module
struct block {
	unsigned int id; // Identifier
	double w;        // width
	double h;        // height
	double x;        // x-coordinate
	double y;        // y-coordinate
	unsigned char rotated;
	unsigned int  con_cnt;
	unsigned int * connections;
};


struct st_t {
	unsigned int *psl; // Positive Step-Line i.e., Gamma+ 
	unsigned int *nsl; // Negative Step-Line, i.e., Gamma-
	unsigned int *rotate_mod;  // flag for if the module is rotated or not in each structure
};

struct sub_array {
	unsigned int *sblo; // chain array
	unsigned int *index; // index of the component in the main arrangement
	unsigned int *rotate_mod;  // flag for if the module is rotated or not
};

extern unsigned int n_modules;
extern unsigned int farthest_module, highest_module;
extern double wasted_area_pecentage;
extern char *subgamma_pair;