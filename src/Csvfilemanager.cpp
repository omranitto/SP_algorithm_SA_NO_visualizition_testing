
#include "stdafx.h"
#include "global.h"
#include "Csvfilemanager.h"

using namespace std;

enum {
	modules_n_col = 0, // Column 1 in .CSV File
	module_width_col = 1, // Column 2 in .CSV File
	module_height_col = 2, // Column 3 in .CSV File
	module_conn_col = 3, // Column 4 in .CSV File
};

//char raw_id[] = "Average";

int csvfilemanager() {
	string str;

	vector<float> n_acc, width_acc, height_acc, conn_acc;
	short state;
	char filename[100], teststruct[100];

	// Define the name of output file
	sprintf_s(teststruct, "testStruct.csv");
	ofstream ofs(teststruct);  // Same as fscanf() in C

	cout << "To randomly generate components " << endl;
	cout << "How many components you want to handle " << endl;
	cin >> n_modules;
	if (n_modules < 2) {
		cout << "The number is Invalid " << endl;
		exit(1);
	}
	else
	{
		double module_width, module_height, *module_conn;
		for (unsigned int cnt = 1; cnt <= n_modules; cnt++) {
			module_width = rand() % 15 + 0.5;
			module_height = rand() % 15 + 0.5;
			module_conn = 0;
			// Export the generated information to one csv file

			ofs << cnt << ","
				<< module_width << ","
				<< module_height << ","
				<< module_conn << ","
				<< endl;
		}
	}


	ofs.close();


	return EXIT_SUCCESS;
}