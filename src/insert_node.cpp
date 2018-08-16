#include <iostream>
#include <map>
#include "insert_node.hpp" 
#include "main.hpp"
#include "employee_node.hpp"
#include "employee_list.hpp"

static std::string entries[2]={"Insert Node","Exit"};

void InsertNodeOperation(){
	std::string name;
	std::string string_phone_number;
	std::cout<<"Please enter the name:";
	std::getline(std::cin,name);
	std::cout<<"Please enter phone number:";
	std::getline(std::cin,string_phone_number);
	employee_directory_list->InsertNode(new EmployeeNode(name,std::stoi(string_phone_number)));
	std::cout<<employee_directory_list->GetHead()->GetName()<<std::endl;
	std::cout<<"Insert Successfully!"<<std::endl;
	return;
}

int InsertNode(){
	std::string input;
	int switch_command=0;
	while(1){
		std::cout<<"=======================InsertNode Page===================="<<std::endl;
		for(int i=0;i<sizeof(entries)/sizeof(std::string);i++){
			std::cout<<i+1<<"."<<entries[i]<<std::endl;
		}
		std::cout<<"Please enter the id of entry:";
		std::getline(std::cin,input);
		switch_command=std::stoi(input);
		if(switch_command == 2){
			break;
		}else{
			InsertNodeOperation();
		}
	}
	return 1;
}