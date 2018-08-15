#include <gflags/gflags.h>
#include "employee_node.hpp"
#include "employee_list.hpp"
#include "main.hpp"


Employee_List::Employee_List(){
	this->head=NULL;
	this->tail=NULL;
	this->length=0;
	this->Number_deleted=0;
	this->deleteNumber=new int[re_list_threshhold];
}

Employee_List::~Employee_List(){
	delete [] this->deleteNumber;
}

int Employee_List::GetTailId(){
	if(!this->tail){
		return -1;
	}
	return this->tail->GetId();
}

bool Employee_List::InsertNode(Employee_Node * node){
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
