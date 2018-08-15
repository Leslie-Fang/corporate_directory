#include <iostream>
#include <gflags/gflags.h>
#include <map>
#include "employee_node.hpp"
#include "employee_list.hpp"
#include "main.hpp"
#include "insert_node.hpp" 
using namespace std;


DEFINE_int32(re_list_threshhold,100,"Define a threshhold value, when deleted numbers are bigger than this value. Re_list operation would be triggered");

Employee_List * Employee_Directory_List;
int re_list_threshhold;

string entries[5]={"Insert Node","Query Information","Modify Information","Delete Node","Exit"};

void GetOpts(){
	re_list_threshhold=FLAGS_re_list_threshhold;
}

void InitDirectory(){
	Employee_Directory_List = new Employee_List();
	RegisterBrewFunction(1,InsertNode);
}

BrewMap g_brew_map;
void RegisterBrewFunction(int id, BrewFunction func){
	g_brew_map[id] = func;
}

int main(int argc , char ** argv){
	::google::ParseCommandLineFlags(&argc, &argv, true);
	GetOpts();
	InitDirectory();
	string input;
	while(1){
		cout<<"=======================Main Page====================";
		for(int i=0;i<sizeof(entries)/sizeof(string);i++){
			cout<<i+1<<"."<<entries[i]<<endl;
		}
		cout<<"Please enter the id of entry:";
		getline(cin,input);
		cout<<stoi(input)<<endl;
		if(stoi(input) == 5){
			break;
		}

	}
	// g_brew_map[1]();
	return 1;
}