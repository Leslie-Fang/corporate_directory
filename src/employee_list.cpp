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

int Employee_List::get_tail_id(){
	if(!this->tail){
		return -1;
	}
	return this->tail->get_id();
}

bool Employee_List::insert_node(Employee_Node * node){
	if(this->head == NULL && this->tail == NULL){
		//empty list
		this->head=node;
		this->tail=this->head;
	}else{
		this->tail->change_next_node(node);
	}
	this->length++;
	return true;
}
