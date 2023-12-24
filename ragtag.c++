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
#include <limits>
#include <stdexcept>
#include <cctype>

using namespace std;

//the three variables, int, flt and str

struct int_{
	string name;
	int val;
};

struct flt{
	string name;
	double val;
};

struct str{
	string name;
	string val;
};

int int_init(vector<string> iline, vector<struct int_> & ilist, unordered_map<string, int> & ivars){

	string var_name = iline[1];

	if (iline.size() == 2){
		//int a
		int_ new_int;
		new_int.name = var_name;
		new_int.val = 0;
		ilist.push_back(new_int);
		ivars[var_name] = 0;
	}else{
		//int a = blah blah blah
		vector<string> exp;
		for (int i = 3; i < iline.size(); i++){
			exp.push_back(iline[i]);
		}
		string val;
		int final;
		int prev_op = 0;//0 is na, 1 if add, 2 if minus, 3 if multiple, 4 if divide, 5 if mod
		for (int i = 0; i < exp.size(); i+=2){
			if (prev_op == 0){
				val = exp[i];
				if (isdigit(val[0]) == 1){
					final = stoi(exp[i]);
				}else{
					//implement func for this
				}
				break;
			}else{
				if (exp[i-1] == "+"){
					prev_op = 1;
				}else if (exp[i-1] == "-"){
					prev_op = 2;
				}else if (exp[i-1] == "*"){
					prev_op = 3;
				}else if (exp[i-1] == "+"){
					prev_op = 4;
				}else if (exp[i-1] == "+"){
					prev_op = 5;
				}
				//implement this here
			}
		}
	}

	return 0;
}

int int_assign(vector<string> iline, vector<struct int_> & ilist, unordered_map<string, int> & ivars){

	return 0;
	
}

int flt_assign(vector<string> iline, vector<struct flt> & ilist, unordered_map<string, int> & ivars){

	return 0;

}

int flt_init(vector<string> iline, vector<struct flt> & ilist, unordered_map<string, int> & ivars){

	return 0;

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
		return 1;
	}

	//storage for variables
	vector<struct int_> int_list;
	vector<struct flt> flt_list;
	vector<struct str> str_list;
	unordered_map<string, int> vars; //0 if int, 1 if flt, 2 is str, and in future: 3 if box

	//keywords
	string keyword_name = "keywords.txt";
	ifstream kwfile (keyword_name);

	set<string> keywords;
	line = "";

	if (kwfile.good()){
		while (getline(kwfile >> ws, line)){
			if (!line.empty()){
				keywords.insert(line);
			}
		}
	}else{
		cout<<"no keyword file\n";
		return 1;
	}

	//main loop of looking at code
	for (int i = 0; i < in_code.size(); ++i){
		//this breaks the line into its components
		string code_statement = in_code[i];
		vector<string> components;

		istringstream iss(code_statement);
		string word;
		while (iss >> word){
			components.push_back(word);
		}
		
		set<string>::iterator it = keywords.find(components[0]);
		
		//checks if the first word is a variable or a keyword
		if (it == keywords.end()){//checks if it is a int, flt or str
			unordered_map<string, int>::iterator it2 = vars.find(components[0]);
			if (it2 == vars.end()){//checks if it is a variable name
				cout<<" error"<<endl;
				return 1;
			}
			//so if we reach here it means it is a variable name
			int type = it2->second;
			if (type == 0){
				int_assign(components, int_list, vars);
			}else if (type == 1){
				flt_assign(components, flt_list, vars);
			}
		}
		//if it is here then that means it is a keyword
		if (components[0] == "int"){
			int_init(components, int_list, vars);
		}else if (components[0] == "flt"){
			flt_init(components, flt_list, vars);
		}
		
	}
	
	
	for (int i = 0; i < int_list.size(); ++i){
		cout<<int_list[i].name<<endl;
		cout<<int_list[i].val<<endl;
		cout<<endl;
	}
	
	for (int i = 0; i < flt_list.size(); ++i){
		cout<<flt_list[i].name<<endl;
		cout<<flt_list[i].val<<endl;
		cout<<endl;
	}
    
    for (const auto& pair : vars) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
	
	

  return 0;
}