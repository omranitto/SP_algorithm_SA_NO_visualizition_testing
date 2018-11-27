// SP_algorithm_SA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NUM_MODULE 13


// Declaration of Module
struct block {
	unsigned int id; // Identifier
	double w;        // width
	double h;        // height
	double x;        // x-coordinate
	double y;        // y-coordinate
};
struct block module[MAX_NUM_MODULE];
unsigned int n_mod;  // the number of blocks

					 // Sequence-Pair
struct sp_t {
	unsigned int psl[MAX_NUM_MODULE]; // Positive Step-Line i.e., Gamma+ 
	unsigned int nsl[MAX_NUM_MODULE]; // Negative Step-Line, i.e., Gamma-
};
/*
struct sp_t sp;
unsigned int pos_def[MAX_NUM_MODULE]; // User-defined Gamma+ Input
unsigned int neg_def[MAX_NUM_MODULE]; // User-defined Gamma- Input
*/
void initialize();
void LeftLayout(int k);
int  read_module(char*);
int read_sp_file(char filename[]);
int  print_module(char*);
int netlist_config(unsigned int); // Define wired connected modules to keep acceptable wire length between them.
void SeqIntersect(unsigned int, char);
void inv_def(unsigned int * p, unsigned int * n, struct sp_t  sp); //Gama type decide which either Gama_Neg (1) or Gama_Pos (2) ;



void main(int argc, char *argv[]) {

	int status1;
	int status2;
	initialize();
	unsigned int x;

	if (argc >= 2)
	{
		status1 = read_module((char*)"test.txt");
		status2 = read_sp_file((char*)"SP_sample.txt");
	}
	else
	{
		printf("Please specify module-file name\n");
		return;
	}

	status1 = print_module((char*)"output.txt");

	inv_def(pos_def)

	
	return;
}

void initialize() {
	unsigned int k;
	int tmp;
	n_mod = (unsigned int)MAX_NUM_MODULE;
	for (k = 0; k < MAX_NUM_MODULE; k++)
	{
		module[k].x = 0.0;
		module[k].w = 0.0;
		module[k].h = 0.0;
	}
}

int read_module(char filename[]) {
	unsigned int i;
	FILE *fp;

	fp = fopen("./test.txt", "r");
	n_mod = 0;

	while ((fscanf(fp, "%d", &i)) != EOF)
	{
		fscanf(fp, "%lf", &module[i].w);
		fscanf(fp, +"%lf", &module[i].h);
		if (i > n_mod) n_mod = i;
		printf("module[%d].w: %.05f, module[%d].h: %.05f\r\n", i, module[i].w, i, module[i].h);
	}

	fclose(fp);

	return(0);

}
int read_sp_file(char filename[]) {
	unsigned int i;
	FILE *fp;
	if ((fp = fopen("./SP_sample.txt", "r")) == NULL) {
		fprintf(stderr, "%s\n", "error: can't read file.");
		return EXIT_FAILURE;
	}

	while ((fscanf(fp, "%d", &i)) != EOF)
	{
		fscanf(fp, "%d", &pos_def[i]);
		fscanf(fp, "%d", &neg_def[i]);
		printf("pos_def[%d]: %d, neg_def[%d]: %d\r\n", i, pos_def[i], i, neg_def[i]);
	}

	return EXIT_SUCCESS;
}
int print_module(char filename[]) {
	unsigned int i;
	FILE *fp;

	fp = fopen(filename, "w");

	for (i = 1; i <= n_mod; i++)
	{
		fprintf(fp, "%d %lf %lf\n", i, module[i].w, module[i].h);
		fprintf(fp, "%lf\n", pos_def[MAX_NUM_MODULE]);
		fprintf(fp, "%lf\n", neg_def[MAX_NUM_MODULE]);

		fclose(fp);

		return(0);
	}
}
/*int netlist_config(char filename[]) {
	unsigned int i;	
	FILE *fp;
	if ((fp = fopen("./netlist.txt", "r")) == NULL) {
		fprintf(stderr, "%s\n", "error: can't read file.");
		return EXIT_FAILURE;
	}

	while ((fscanf(fp, "%d", &i)) != EOF)
	{
		fscanf(fp, "%d", &pos_def[i]);
		printf("pos_def[%d]: %d, neg_def[%d]: %d\r\n", i, pos_def[i], i, neg_def[i]);
	}

	return EXIT_SUCCESS;
}
*/


void inv_def(unsigned int x, unsigned int pos_def[], char GammaType){
	unsigned int i;
	unsigned int inv_pos_array[MAX_NUM_MODULE];
	unsigned int inv_neg_array[MAX_NUM_MODULE];
	unsigned int def[MAX_NUM_MODULE];

	for (i = 1; i >= MAX_NUM_MODULE; i++)
	{
		int j; int index;
		for (j = 1; j <= MAX_NUM_MODULE; j++)
			switch (GammaType) {
				case (char) 1:
					if (pos_def[j] == j)
					{
						index == j;
						inv_pos_array[i] = index;// pos_def[j];
					}
					break;

				case (char) 2:
					if (neg_def[j] == j)
					{
						index == j;
						inv_neg_array[i] = index;// pos_def[j];
					}
					break;
				default :
					break;
			}

		//return(0);
	}
}
	
	void Layout_Relation_Checker(unsigned int inv_pos_array[], unsigned int neg_def[])
	{
		int k;
		for (k = 1; k <= MAX_NUM_MODULE; k++)
		{
			int l;
			for (l = 1; l < k; l++)
				if (inv_pos_array[neg_def[l]] < pos_def.inv_pos_def[neg_def[k]]
					{
					if (neg_def[l].x + neg_def[l].w > pos_def[inv_pos_array[neg_def[k]]].x)

						neg_def[k].x = neg_def[l].x + neg_def[l].w;
						
					}
		/*	this function is for searching if the current component is in the same order with other in both pairs
				means it is in left - right relation,
			if it is in reverse relation means it is in above - below relation; otherwise there is no relation. 
		*/	
			
		

/*
		void SeqIntersect(unsigned int x, unsigned int inv_pos_array[], unsigned int neg_def[MAX_NUM_MODULE])
		{
			unsigned int i, j, k, l, m, ;

			if (operation == AFTER_AFTER) {
				for (i = 1; sp.psl[i - 1] != x; i++);
				for (j = 1; sp.nsl[j - 1] != x; j++);
				// Calculate the number of elements inside M^aa(x)
				disjoint_size[0] = MAX_NUM_MODULE - i;
				disjoint_size[1] = MAX_NUM_MODULE - j;
				disjoint_size[2] = 0; // Initialise as 0
				for (l = 0; l < disjoint_size[0]; l++) {
					for (m = 0; m < disjoint_size[1]; m++) {
						if (sp.psl[i + l] == sp.nsl[j + m]) {
							disjoint_size[2] += 1;
							DisjointSet_module[0] = (unsigned int*)realloc(
								DisjointSet_module[0],
								disjoint_size[2] * sizeof(unsigned int)
							);
							DisjointSet_module[0][disjoint_size[2] - 1] = sp.psl[i + l];
						}
					}
				}
				printf("M^aa(x): {");
				for (i = 0; i < disjoint_size[2]; i++) printf("%d, ", DisjointSet_module[0][i]);
				printf("}\r\n");
			}
			else if (operation == BEFORE_BEFORE) {
				for (i = 1; sp.psl[i - 1] != x; i++);
				for (j = 1; sp.nsl[j - 1] != x; j++);
				// Calculate the number of elements inside M^aa(x)
				disjoint_size[0] = i - 1;
				disjoint_size[1] = j - 1;
				disjoint_size[2] = 0; // Initialise as 0
				for (l = 0; l < disjoint_size[0]; l++) {
					for (m = 0; m < disjoint_size[1]; m++) {
						if (sp.psl[l] == sp.nsl[m]) {
							DisjointSet_module[1] = (unsigned int*)realloc(
								DisjointSet_module[1],
								(disjoint_size[2] + 1) * sizeof(unsigned int)
							);
							DisjointSet_module[1][disjoint_size[2]] = sp.psl[l];
							disjoint_size[2] += 1;
						}
					}
				}
				printf("M^bb(x): {");
				for (i = 0; i < disjoint_size[2]; i++) printf("%d, ", DisjointSet_module[1][i]);
				printf("}\r\n");
			}
			else if (operation == BEFORE_AFTER)１ {
				for (i = 1; sp.psl[i - 1] != x; i++);
				for (j = 1; sp.nsl[j - 1] != x; j++);
				// Calculate the number of elements inside M^aa(x)
				disjoint_size[0] = i - 1;
				disjoint_size[1] = MAX_NUM_MODULE - j;
				disjoint_size[2] = 0; // Initialise as 0
				for (l = 0; l < disjoint_size[0]; l++) {
					for (m = 0; m < disjoint_size[1]; m++) {
						if (sp.psl[l] == sp.nsl[j + m]) {
							DisjointSet_module[2] = (unsigned int*)realloc(
								DisjointSet_module[2],
								(disjoint_size[2] + 1) * sizeof(unsigned int)
							);
							DisjointSet_module[2][disjoint_size[2]] = sp.psl[l];
							disjoint_size[2] += 1;
						}
					}
				}
				printf("M^ba(x): {");
				for (i = 0; i < disjoint_size[2]; i++) printf("%d, ", DisjointSet_module[2][i]);
				printf("}\r\n");
			}
			else { // AFTER_BEFORE
				for (i = 1; sp.psl[i - 1] != x; i++);
				for (j = 1; sp.nsl[j - 1] != x; j++);
				// Calculate the number of elements inside M^aa(x)
				disjoint_size[0] = MAX_NUM_MODULE - i;
				disjoint_size[1] = j - 1;
				disjoint_size[2] = 0; // Initialise as 0
				for (l = 0; l < disjoint_size[0]; l++) {
					for (m = 0; m < disjoint_size[1]; m++) {
						if (sp.psl[i + l] == sp.nsl[m]) {
							disjoint_size[2] += 1;
							DisjointSet_module[3] = (unsigned int*)realloc(
								DisjointSet_module[3],
								disjoint_size[2] * sizeof(unsigned int)
							);
							DisjointSet_module[3][disjoint_size[2] - 1] = sp.psl[i + l];
						}
					}
				}
				printf("M^ab(x): {");
				for (i = 0; i < disjoint_size[2]; i++) printf("%d, ", DisjointSet_module[3][i]);
				//printf("nm_ ifyer f=].d;Si l[Be kpow
	}
*/
/*
				unsigned int max(unsigned int module_id, int target_constraint_in)
			
			{
					double max_temp = 0.0;
					if (target_constraint_in == (int)LEFT) {
						for (int i = 0; i < module[module_id].left_constraint_num; i++)
							if (module[module_id].left_constraint[i] > max_temp) {
								max_temp = module[module_id].left_constraint[i];
							}

						//max_temp = (module[module_id].left_constraint[i] > max_temp) ? module[module_id].left_constraint[i] : max_temp;
					}
					else { // target_constraint_in == (int) BELOW
						for (int i = 0; i < module[module_id].below_constraint_num; i++)
							if (module[module_id].below_constraint[i] > max_temp) {
								max_temp = module[module_id].below_constraint[i];
							}
					}

					return max_temp;
				}
			
*/