#include <iostream>
#include <gflags/gflags.h>
#include "employee_node.hpp"
#include "employee_list.hpp"
using namespace std;


DEFINE_int32(re_list_threshhold,100,"Define a threshhold value, when deleted numbers are bigger than this value. Re_list operation would be triggered");

Employee_List * Employee_Directory_List;
int re_list_threshhold;

void get_opts(){
	re_list_threshhold=FLAGS_re_list_threshhold;
}

void init_directory(){
	Employee_Directory_List = new Employee_List();
}

int main(int argc , char ** argv){
	::google::ParseCommandLineFlags(&argc, &argv, true);
	get_opts();
	init_directory();

	return 1;
}