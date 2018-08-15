#include "employee_node.hpp"
#include "main.hpp"

Employee_Node::Employee_Node(std::string name, int phone_number){
	this->name = name;
	this->phone_number = phone_number;
	this->next = NULL;
	if(Employee_Directory_List->GetTailId() > 0){
		this->id = Employee_Directory_List->GetTailId()+1;
	}else{
		this->id = 1;
	}
}

int Employee_Node::GetId(){
	return this->id;
}

bool Employee_Node::ChangeNextNode(Employee_Node * node){
	this->next = node;
	return true;
}