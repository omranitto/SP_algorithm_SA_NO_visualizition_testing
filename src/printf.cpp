#include "stdafx.h"
#include "../inc/global.h"

//Outfilename, module, spc,
int print_module(FILE * fp, struct block *module, struct st_t sp, double temp) {
	unsigned int j;
	fprintf(fp, "================\n================\n%8.2f\n", temp);
	for (unsigned int i = 1; i <= n_modules; i++) {
		//printf("%3d %5.2lf %5.2lf %5.2lf %5.2lf %3d:", 
		//	i, module[i].w, module[i].h, module[i].x, module[i].y, module[i].con_cnt);
		fprintf(fp, "%3d %5.2f %5.2f %5.2f %5.2f\n", i, module[i].w, module[i].h, module[i].x, module[i].y);

		//for (j = 0; j < module[i].con_cnt; j++) 
		//	printf(" %3d", module[i].connections[j]);
		//printf("\n");
	}

	// Output PSL & NSL of the current SP order to file
	fprintf(fp, "PSL=[");
	for (unsigned int i = 0; i <= n_modules; i++) {
		fprintf(fp, "%3d ", sp.psl[i]);
	}
	fprintf(fp, "]\nNSL=[");
	for (unsigned int i = 0; i <= n_modules; i++) {
		fprintf(fp, "%3d ", sp.nsl[i]);
	}
	fprintf(fp, "]\n");
	return(0);
}

//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

int print_parametric_study(char * filename, double temp, unsigned int c) {
	FILE *fp = fopen(filename, "w");
	fprintf(fp, "\n");
	// Output PSL & NSL of the modified SP order to file
	fprintf(fp, "Parameteric Study\n");
	fprintf(fp, "Temprature change during SA iterations");

	fprintf(fp, "%3d ", temp);

	fprintf(fp, "]\n");

	fclose(fp);
	return(0);
}



///\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

int print_results(struct st_t spt, double temp, double initial_boundary_width, double initial_boundary_height) {
	unsigned int j;

	printf("\n Initial baundary size \n");
	printf("\nInitial_boundary_width = %f    ,     Initial_boundary_height = %f\n", initial_boundary_width, initial_boundary_height);

	printf("\ncurrentsp_cost_area = %f    ,     Initial_boundary_height = %f\n", initial_boundary_width, initial_boundary_height);

	// Output PSL & NSL of the tentative SP order to file
	printf("\ntentative sp\n");
	printf("PSL=[");
	for (unsigned int i = 0; i <= n_modules; i++) {
		printf("%3d ", spt.psl[i]);
	}
	printf("]\nNSL=[");
		for (unsigned int i = 0; i <= n_modules; i++) {
			printf("%3d ", spt.nsl[i]);
		}
	printf("\n the temprature is   %d", temp);


	/*

	temp_modules = cost.final_modules;
	printf("\nfinal modules\n");
	for (i = 0; i<module_count; i++) {
	printf("(%d, %d)\t", temp_modules[i].module, temp_modules[i].size);
	}
	printf("\n");
	//generates output desig file
	optimal_design(module_count, cost, module_array, polish_exp);

	//free allocated dynamic memory
	module_array_temp = module_array;
	for (i = 0; i<module_count; i++) {
	temp_module = module_array_temp[i];
	while (temp_module != NULL) {
	free_module = temp_module;
	temp_module = temp_module->next;
	free(free_module);
	}

	*/

	return(0);
}

