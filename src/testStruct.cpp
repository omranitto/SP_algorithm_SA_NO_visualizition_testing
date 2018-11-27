// testStruct.cpp : Defines the entry point for the console application.
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
	unsigned int  con_cnt;
	unsigned int * connections;
};
struct block module[MAX_NUM_MODULE];
unsigned int n_mod;  // the number of blocks

int read_sp_file(char filename[]);

void main(int argc, char *argv[]) {
	read_sp_file("./testStruct.txt");
}

int read_sp_file(char filename[]) {
	unsigned int i;
	FILE *fp;

	fp = fopen(filename, "r");
	n_mod = 0;

	while ((fscanf(fp, "%d", &i)) != EOF)
	{
		module[i].id = i;
		fscanf(fp, "%lf", &module[i].w);
		fscanf(fp, "%lf", &module[i].h);
		fscanf(fp, "%d", &module[i].con_cnt);
		if (module[i].con_cnt == 0) module[i].connections = NULL;
		else {
			module[i].connections = new unsigned int[module[i].con_cnt];
			for (unsigned int j = 0; j<module[i].con_cnt; j++)
				fscanf(fp, "%d", &(module[i].connections[j]) );
		}
	}
	fclose(fp);

	return(0);

}