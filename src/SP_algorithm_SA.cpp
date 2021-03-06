#include "stdafx.h"

#include "../inc/global.h"

#include "../inc/Csvfilemanager.h"
#include "../inc/initial.h"

#include "../inc/readf.h"
#include "../inc/allocatef.h"
#include "../inc/coordinate_calc.h"
#include "../inc/array_arrange.h"
#include "../inc/chainidentifier.h"
#include "../inc/SP_modify.h"
#include "../inc/copyf.h"
#include "../inc/modificationf.h"
#include "../inc/evaluation.h"
#include "../inc/printf.h"
/////////////////////////
#include <iostream>
//#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
//#include "visualdrawpreparation.h"

#define render_scale_x 20
#define render_scale_y 20

struct block struct_block;
unsigned int n_modules;
unsigned int farthest_module = 0, highest_module = 0;
double wasted_area_pecentage;
char *subgamma_pair;
int main()
{

	char //configfilename[] = "./configFile.txt",
		filename[] = "testStruct.csv",
		PSfilename[] = "./Parametric_study.txt",
		Modulesfilename[] = "./testOutput.txt";
	//n_modules = read_moduleConfig(configfilename);
	csvfilemanager();
	struct block * module;
	//struct sp_t spc, spt, spn ;
	struct st_t spc, spt, spn;
	unsigned int state, *inv_psl, *inv_nsl, *sp_mod_array;
	double initial_boundary_width;
	double initial_boundary_height;

	double modifiedsp_cost_area, currentsp_cost_area, tentativesp_cost_area, Current_width, Current_height;
	allocate_arrays(&sp_mod_array, &module, &inv_psl, &inv_nsl, &spc, &spn, &spt);

	initialize(sp_mod_array, &modifiedsp_cost_area, &currentsp_cost_area, &spt, &spn, &spc,
		&Current_width, &Current_height, module);
	initialize_orientation(&spc);
	read_sp_file(filename, module, &spc);
	set_initial_layout_boundary(&Current_width, &Current_height, &initial_boundary_width, &initial_boundary_height, module);
	///////////

	shuffle(&spc);

	inv_psl = inv_def(n_modules, spc.psl);
	coordinate_calc(&Current_width, &Current_height, module, &spc, inv_psl);
	//visualdrawpreparation(module);
	//RectangleLinesf(module);
	double optimal_area = optimal_bounday_area(module);
	currentsp_cost_area = boudary_calc(Current_width, Current_height);
	//double wasted_areas = wasted_area(optimal_area, currentsp_cost_area);
	SPcpy(&spt, &spc);
	tentativesp_cost_area = currentsp_cost_area;

	//visualdrawpreparation(module);


	//from here the SA Loop will start
	double temp = 10000;
	int random_no;
	int no_acc, no_rand;

	FILE *fp = fopen(PSfilename, "w");
	FILE *fp_modules = fopen(Modulesfilename, "w");

	// Output PSL & NSL of the modified SP order to file
	fprintf(fp, "optimal_bounday_area = %lf\n", optimal_bounday_area(module));
	fprintf(fp, "Temperature\tAcceptanced\tRandum\tCost\tWastedArea\n");
	double delta_area, exp_f = 0, r = 0;
	int c, displayStep = 0;
	//from here the SA Loop will start
	while (temp > 0.001) {
		no_acc = 0;
		no_rand = 0;

		for (c = 0; c < 50000; c++) {

			SP_modify(&spn, &spc);
			inv_psl = inv_def(n_modules, spn.psl);
			initialize_coordinate(module);
			coordinate_calc(&Current_width, &Current_height, module, &spn, inv_psl);
			modifiedsp_cost_area = boudary_calc(Current_width, Current_height);

			//wasted_areas = wasted_area(optimal_area, tentativesp_cost_area);

			//state = eval_boudary_cost(currentsp_cost_area, &modifiedsp_cost_area);     //if(modified_cost_area < current_cost_area)
			if (modifiedsp_cost_area <= currentsp_cost_area)
			{
				no_acc++;
				SPcpy(&spc, &spn);
				currentsp_cost_area = modifiedsp_cost_area;
				if (currentsp_cost_area < tentativesp_cost_area) {
					tentativesp_cost_area = currentsp_cost_area;
					SPcpy(&spt, &spc);
				}
			}
			else
			{
				delta_area = currentsp_cost_area - modifiedsp_cost_area;
				// Acceptance probability calculation 
				exp_f = exp(delta_area / temp);
				r = ((double)(rand() % 10000 + 1)) / 10000.0;
				if (exp_f >= r) {
					no_rand++;
					SPcpy(&spc, &spn);
					currentsp_cost_area = modifiedsp_cost_area;
				}
			}
			//chain_set( chain, *gamma_pair, random_count, *spt);

			//fprintf(fp, "%6e,\t%6e,\t%6e,\t%.4f\n", temp, exp_f, r, currentsp_cost_area);
			//print_module(fp_modules, module, spc, temp);
			//fprintf(fp, "%.4e\t%11d\t%6d\t%.4f\n", temp, no_acc, no_rand, currentsp_cost_area);
		}
		temp = temp * 0.95;
		if (++displayStep % 50 == 0) {
			for (unsigned int i = 1; i <= n_modules; i++) module[i].rotated = spc.rotate_mod[i];
			//RectangleLinesf(module);
		}// SA algorith finish 

		 //fprintf(fp, "=========================================\n" );
		fprintf(fp, "%.4e\t%4.4f\t%4d\t%4d\t%.4f\t%.4f\n", temp, currentsp_cost_area, no_acc, no_rand, wasted_areas, wasted_area_pecentage);
		fflush(fp);
	}

	for (unsigned int i = 1; i <= n_modules; i++) module[i].rotated = spc.rotate_mod[i];
	//RectangleLinesf(module);

	fprintf(fp, "Tentative: %.4f\n", tentativesp_cost_area);
	fclose(fp);
	fprintf(fp_modules, "\n****************\n****************\nTentative\n");
	print_module(fp_modules, module, spt, temp);
	fclose(fp_modules);


	//print_results(spt, initial_boundary_width, temp,  initial_boundary_height);
	//getchar();

	//mathmatic Library 
	/*void encrypt_randomly_select_one(unsigned int encrypt);
	void decrypt_randomly_select_one(unsigned int encrypt);
	int randomly_select_multi(char *gamma_index, unsigned int random_count);
	*/
	/*

	void encrypt_randomly_select_one(unsigned int encrypt) {

	int sp_index, seq_index;
	sp_index = rand() % 2; // x = 0 ~ 1
	seq_index = rand() % n_modules + 1;

	encrypt = ((seq_index) * 10) + sp_index;

	}
	void decrypt_randomly_select_one(unsigned int encrypt) {

	int sp_index, seq_index;

	sp_index = encrypt % 10;
	seq_index = encrypt / 10;


	}
	*/


	//////////////////////////////////////////////////////////////////////

	//Tutorial_011_Rectangle_Bounding_Box_Collision_Detection();


	//Tutorial_02_Sprite_Textures();
	//Tutorial_4_TransformationsPosition_Rotation_Scale_Origin();
	return EXIT_SUCCESS;
}
