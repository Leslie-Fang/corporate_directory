#include <iostream>
#include <map>
#include "modify_node.hpp" 
#include "main.hpp"
#include "global.hpp"
#include "employee_node.hpp"
#include "employee_list.hpp"

static std::string entries[2]={"Modify Node","Exit"};

int ModifyNodeOperation(){
	std::string string_id;
	std::cout<<"Please enter the id of employee you want to modify:";
	std::getline(std::cin,string_id);
	int id = std::stoi(string_id);
	EmployeeNode * node = employee_directory_list->GetHead();
	while(node != NULL){
		if(node->GetId() == id){
			std::string string_phone_number;
			std::cout<<"Please enter new phone number:";
			std::getline(std::cin,string_phone_number);
			node->ChangePhoneNumber(std::stoi(string_phone_number));
			return 1;
		}
		node = node->GetNext();
	}
	return -1;
}

int ModifyNode(){
	std::string input;
	int switch_command=0;
	while(1){
		std::cout<<"=======================ModifyNode Page===================="<<std::endl;
		for(int i=0;i<sizeof(entries)/sizeof(std::string);i++){
			std::cout<<i+1<<"."<<entries[i]<<std::endl;
		}
		std::cout<<"Please enter the id of entry:";
		std::getline(std::cin,input);
		switch_command=std::stoi(input);
		if(switch_command == 2){
			break;
		}else{
			ModifyNodeOperation();
		}
	}
	return 1;
}
