#include <iostream>
#include "query_node.hpp" 
#include "main.hpp"
#include "employee_node.hpp"
#include "employee_list.hpp"

static std::string entries[2]={"Query Node","Exit"};

int QueryNodeOperation(){
	std::string name;
	std::cout<<"Please enter the name:";
	std::getline(std::cin,name);
	EmployeeNode * node = employee_directory_list->GetHead();
	while(node != NULL){
		if(node->GetName() == name){
			std::cout<<"=======================Find Node===================="<<std::endl;
			std::cout<<"=======================ID: "<<node->GetId()<<" ===================="<<std::endl;
			std::cout<<"=======================Name: "<<node->GetName()<<" ===================="<<std::endl;
			std::cout<<"=======================Phone Number: "<<node->GetPhoneNumber()<<" ===================="<<std::endl;
			return 1;
		}
		node = node->GetNext();
	}
	std::cout<<"=======================Didn't find Node===================="<<std::endl;
	return -1;
}

int QueryNode(){
	std::string input;
	int switch_command=0;
	while(1){
		std::cout<<"=======================QueryNode Page===================="<<std::endl;
		for(int i=0;i<sizeof(entries)/sizeof(std::string);i++){
			std::cout<<i+1<<"."<<entries[i]<<std::endl;
		}
		std::cout<<"Please enter the id of entry:";
		std::getline(std::cin,input);
		switch_command=std::stoi(input);
		if(switch_command == 2){
			break;
		}else{
			QueryNodeOperation();
		}
	}
	return 1;
}