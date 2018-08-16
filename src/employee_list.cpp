#include <gflags/gflags.h>
#include "employee_node.hpp"
#include "employee_list.hpp"
#include "main.hpp"


EmployeeList::EmployeeList(){
	this->head=NULL;
	this->tail=NULL;
	this->length=0;
	this->Number_deleted=0;
	this->deleteNumber=new int[re_list_threshhold];
}

EmployeeList::~EmployeeList(){
	delete [] this->deleteNumber;
}

int EmployeeList::GetTailId(){
	if(!this->tail){
		return -1;
	}
	return this->tail->GetId();
}

bool EmployeeList::InsertNode(EmployeeNode * node){
	if(this->head == NULL && this->tail == NULL){
		//empty list
		this->head=node;
		this->tail=this->head;
	}else{
		this->tail->ChangeNextNode(node);
	}
	this->length++;
	return true;
}

EmployeeNode * EmployeeList::GetHead(){
	return this->head;
}
