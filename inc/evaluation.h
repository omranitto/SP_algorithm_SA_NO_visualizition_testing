#ifndef __EVALUATION_H
#define __EVALUATION_H


double boudary_calc(double Current_width, double Current_height);
double optimal_bounday_area(struct block *module);

char eval_boudary_cost(double currentsp_cost_area, double * modifiedsp_cost_area);
double wasted_area(double optimal_area, double *desiredsp_cost_area);


#endif

