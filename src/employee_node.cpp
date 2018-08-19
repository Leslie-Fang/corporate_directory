#include "employee_node.hpp"
#include "main.hpp"
#include "global.hpp"

EmployeeNode::EmployeeNode(std::string name, int phone_number){
	this->name = name;
	this->phone_number = phone_number;
	this->next = NULL;
	if(employee_directory_list->GetTailId() > 0){
		this->id = employee_directory_list->GetTailId()+1;
	}else{
		this->id = 1;
	}
}

int EmployeeNode::GetId(){
	return this->id;
}

std::string EmployeeNode::GetName(){
	return this->name;
}

int EmployeeNode::GetPhoneNumber(){
	return this->phone_number;
}

bool EmployeeNode::ChangeNextNode(EmployeeNode * node){
	this->next = node;
	return true;
}

EmployeeNode * EmployeeNode::GetNext(){
	return this->next;
}

bool EmployeeNode::ChangePhoneNumber(int phone_number){
	this->phone_number = phone_number;
	return true;
}

bool EmployeeNode::ChangeId(int id){
	this->id = id;
	return true;
}