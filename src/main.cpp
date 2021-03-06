#include <map>
#include <iostream>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include "employee_node.hpp"
#include "employee_list.hpp"
#include "main.hpp"
#include "global.hpp"
#include "insert_node.hpp" 
#include "query_node.hpp" 
#include "modify_node.hpp" 
#include "delete_node.hpp" 
using namespace std;
using directory::employee_directory_list;
using directory::re_list_threshhold;
using directory::EmployeeList;
using directory::InsertNode;
using directory::QueryNode;
using directory::ModifyNode;
using directory::DeleteNode;

DEFINE_int32(re_list_threshhold,100,"Define a threshhold value, when deleted numbers are bigger than this value. Re_list operation would be triggered");

static string entries[5]={"Insert Node","Query Information","Modify Information","Delete Node","Exit"};

void GetOpts(){
	re_list_threshhold=FLAGS_re_list_threshhold;
}

void InitDirectory(){
	employee_directory_list = new EmployeeList();
	RegisterBrewFunction(1,InsertNode);
	RegisterBrewFunction(2,QueryNode);
	RegisterBrewFunction(3,ModifyNode);
	RegisterBrewFunction(4,DeleteNode);
}

static BrewMap g_brew_map;
void RegisterBrewFunction(int id, BrewFunction func){
	g_brew_map[id] = func;
}

int main(int argc , char ** argv){
	FLAGS_alsologtostderr = 1;
	FLAGS_log_dir = "./log";
	google::InitGoogleLogging(argv[0]);
	LOG(INFO) << "Program Start!";
	::google::ParseCommandLineFlags(&argc, &argv, true);
	GetOpts();
	InitDirectory();
	string input;
	int switch_command=0;
	while(1){
		cout<<"=======================Main Page===================="<<endl;
		for(int i=0;i<sizeof(entries)/sizeof(string);i++){
			cout<<i+1<<"."<<entries[i]<<endl;
		}
		cout<<"Please enter the id of entry:";
		getline(cin,input);
		switch_command=stoi(input);
		if(switch_command == 5){
			break;
		}else{
			g_brew_map[switch_command]();
		}
	}
	delete employee_directory_list;
	employee_directory_list = NULL;
	google::ShutdownGoogleLogging();
	return 1;
}