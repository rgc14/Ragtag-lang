#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <set>

using namespace std;

//the three variables, int, flt and str

struct int_{
	string name;
	int val=0;
	int is_const=0;
};

struct flt{
	string name;
	double val=0.0;
};

struct str{
	string name;
	string val="";
};

void int_assign(string iline, vector<struct int_> & ilist, unordered_map<string, int> & ivars){

}

int main(int argc, char* argv[]){

	string infile_name = argv[1];
	ifstream infile (infile_name);

	vector<string> in_code;//has ragtag code
	string line;

	if (infile.good()){

		while (getline(infile >> ws, line)){
			if (!line.empty()){
				in_code.push_back(line);
			}
		}

	}else{
		cout<<"invalid file\n";
	}

	//storage for variables
	vector<struct int_> int_list;
	vector<struct flt> flt_list;
	vector<struct str> str_list;
	unordered_map<string, int> var_taken;

	//keywords
	string keyword_name = "keywords.txt";
	ifstream kwfile (keyword_name);

	set<string> keywords;
	line = "";

	if (infile.good()){
		while (getline(kwfile >> ws, line)){
			if (!line.empty()){
				keywords.insert(line);
			}
		}
	}else{
		cout<<"no keyword file\n";
	}

	//main loop of looking at code
	for (int i = 0; i < in_code.size(); ++i){
		string code_statement = in_code[i];
		vector<string> components;

		istringstream iss(code_statement);
		string word;
		while (iss >> word){
			components.push_back(word);
		}
	}

  return 0;
}