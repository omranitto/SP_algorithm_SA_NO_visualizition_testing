#include "stdafx.h"
#include "global.h"
#include "readf.h"

#define READ_CSV_FILE 

enum {
	modules_n_col = 0, // Column 1 in .CSV File
	module_width_col = 1, // Column 2 in .CSV File
	module_height_col = 2, // Column 3 in .CSV File
	module_conn_col = 3, // Column 4 in .CSV File
};

int read_moduleConfig(char filename[]) {
	FILE *fp;

	int i;
	fp = fopen(filename, "r");
	fscanf(fp, "%d", &i);


	fclose(fp);

	return(i);

}

#ifndef READ_CSV_FILE
int read_sp_file(char * filename, struct block *module, struct st_t * spc) {
	FILE *fp;

	fp = fopen(filename, "r");
	unsigned int i = 1;
	while ((fscanf(fp, "%d", &module[i].id)) != EOF)
	{
		spc->psl[i] = module[i].id;
		spc->nsl[i] = module[i].id;
		fscanf(fp, "%lf", &module[i].w);
		fscanf(fp, "%lf", &module[i].h);
		fscanf(fp, "%d", &module[i].con_cnt);
		if (module[i].con_cnt == 0) module[i].connections = NULL;
		else {
			module[i].connections = new unsigned int[module[i].con_cnt];
			for (unsigned int j = 0; j<module[i].con_cnt; j++)
				fscanf(fp, "%d", &(module[i].connections[j]));
		}
		i++;
		if (n_modules == i - 1) break;
	}
	fclose(fp);
	if (n_modules != i - 1)
		exit(-1);
	return(0);

}
#else
int read_sp_file(char * filename, struct block *module, struct st_t * spc) {
	string str;

	vector<float> n_acc, width_acc, height_acc, conn_acc;
	float n_avg = 0.0, width_avg = 0.0, height_avg = 0.0, conn_avg = 0.0;
	short state;
	unsigned int i = 1;

	// Read the input file
	ifstream ifs(filename);
	if (!ifs) {
		cout << "Input Error" << endl;
		exit(1);
	}

	// Read the csv file line by line
	while (getline(ifs, str)) {
		string token;
		istringstream stream(str);
		state = (short)modules_n_col;

		// Separate the elements (e.g., string) inside one line by comma ","
		while (getline(stream, token, ',')) {
			// Convert every string (char array) into float type
			// and store in the std::vector
			if (state == (short)modules_n_col) {
				spc->psl[i] = stoi(token);
				spc->nsl[i] = stoi(token);
				cout << stod(token) << ",";
			}
			else if (state == (short)module_width_col) {
				module[i].w = stod(token);
				cout << stod(token) << ",";
			}
			else if (state == (short)module_height_col) {
				module[i].h = stod(token);
				cout << stod(token) << ",";
			}
			else {
				module[i].con_cnt = stoi(token);
				cout << stoi(token) << ",";
			}

			state += 1;
		}
		cout << endl;
		i++;
	}


	if (n_acc.size() != width_acc.size() ||
		height_acc.size() != width_acc.size() ||
		conn_acc.size() != width_acc.size()
		) {
		cout << "The number of contents among all column is not consistent" << endl;
		exit(1);
	}

	return(0);
}
#endif

/*

int read_online_sp_file(char * filename, struct block *module, struct st_t * spc) {

string str;
vector<double> n_acc, width_acc, height_acc, conn_acc;
char filename[100], output_FileName[100];
// Define the name of output file
sprintf_s(output_FileName, "testStruct.csv");
ofstream ofs(output_FileName);  // Same as fscanf() in C

// Set the name of input file
sprintf_s(filename, "testStruct.csv");
cout << "Reading " << filename << endl;


// Read the input file
ifstream ifs(filename);
if (!ifs) {
cout << "Input Error" << endl;
exit(1);
}

// Read the csv file line by line
while (getline(ifs, str)) {
string token;
istringstream stream(str);
state = (short)modules_n_col;

// Separate the elements (e.g., string) inside one line by comma ","
while (getline(stream, token, ',')) {
// Convert every string (char array) into float type
// and store in the std::vector
spc->psl[i] = module[i].id;
spc->nsl[i] = module[i].id;
fscanf(fp, "%lf", &module[i].w);
fscanf(fp, "%lf", &module[i].h);
fscanf(fp, "%d", &module[i].con_cnt);

if (state == (short)modules_n_col) {
n_acc.push_back(stoi(token));
cout << stod(token) << ",";
}
else if (state == (short)module_width_col) {
width_acc.push_back(stod(token));
cout << stod(token) << ",";
}
else if (state == (short)module_height_col) {
height_acc.push_back(stod(token));
cout << stod(token) << ",";
}
else {
conn_acc.push_back(stoi(token));
cout << stoi(token) << ",";
}

state += 1;
}
cout << endl;
}


if (n_acc.size() != width_acc.size() ||
height_acc.size() != width_acc.size() ||
conn_acc.size() != width_acc.size()
) {
cout << "The number of contents among all column is not consistent" << endl;
exit(1);
}

for (unsigned int i = 0; i < n_acc.size(); i++) {
n_avg += n_acc[i];
width_avg += width_acc[i];
height_avg += height_acc[i];
conn_avg += conn_acc[i];
}

return(0);

}
*/