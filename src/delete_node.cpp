#include <iostream>
#include <map>
#include "delete_node.hpp" 
#include "main.hpp"
#include "global.hpp"
#include "employee_node.hpp"
#include "employee_list.hpp"

static std::string entries[2]={"Delete Node","Exit"};

int DeleteNodeOperation(){
	std::string name;
	std::cout<<"Please enter the name you want to delete:";
	std::getline(std::cin,name);
	EmployeeNode * pre_node = NULL;
	EmployeeNode * node = employee_directory_list->GetHead();
	while(node != NULL){
		if(node->GetName() == name){
			employee_directory_list->DeleteNode(pre_node,node);
			return 1;
		}
		pre_node = node;
		node = node->GetNext();
	}
	std::cout<<"=======================Didn't find Node===================="<<std::endl;
	return -1;
}

int DeleteNode(){
	std::string input;
	int switch_command=0;
	while(1){
		std::cout<<"=======================DeleteNode Page===================="<<std::endl;
		for(int i=0;i<sizeof(entries)/sizeof(std::string);i++){
			std::cout<<i+1<<"."<<entries[i]<<std::endl;
		}
		std::cout<<"Please enter the id of entry:";
		std::getline(std::cin,input);
		switch_command=std::stoi(input);
		if(switch_command == 2){
			break;
		}else{
			DeleteNodeOperation();
		}
	}
	return 1;
}