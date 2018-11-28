#include "stdafx.h"
#include "../inc/global.h"
#include "../inc/evaluation.h"

double boudary_calc(double Current_width, double Current_height) {

	return Current_width * Current_height;
}

double optimal_bounday_area(struct block *module) {
	double optimal_area = 0;

	for (int k = 1; k <= n_modules; k++)
	{

		optimal_area = optimal_area + (module[k].w * module[k].h);
	}
	return optimal_area;
}


char eval_boudary_cost(double currentsp_cost_area, double *modifiedsp_cost_area) {
	if (*modifiedsp_cost_area < currentsp_cost_area) {
		*modifiedsp_cost_area = currentsp_cost_area;
		return 1;
	}
	else return 0;
}

double wasted_area(double optimal_area, double *desiredsp_cost_area) {
	wasted_area_pecentage = (100 * (*desiredsp_cost_area - optimal_area)) / *desiredsp_cost_area;
	return *desiredsp_cost_area - optimal_area;
}
