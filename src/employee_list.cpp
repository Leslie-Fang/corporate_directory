#include <gflags/gflags.h>
#include "employee_node.hpp"
#include "employee_list.hpp"
#include "main.hpp"
#include "global.hpp"

namespace directory{
	EmployeeList::EmployeeList(){
		this->head=NULL;
		this->tail=NULL;
		this->length=0;
		this->number_deleted=0;
		this->delete_number=new int[re_list_threshhold];
	}

	EmployeeList::~EmployeeList(){
		EmployeeNode * node = this->head;
		EmployeeNode * prenode = NULL;
		while(node != NULL){
			prenode = node;
			node = node->GetNext();
			delete prenode;
		}
		delete [] this->delete_number;
	}

	EmployeeNode * EmployeeList::GetHead(){
		return this->head;
	}

	EmployeeNode * EmployeeList::GetTail(){
		return this->tail;
	}

	int EmployeeList::GetNumberDeleted(){
		return this->number_deleted;
	}

	int EmployeeList::GetLength(){
		return this->length;
	}

	int * EmployeeList::GetDeletedNumber(){
		return this->delete_number;
	}

	int EmployeeList::GetTailId(){
		if(!this->tail){
			return -1;
		}
		return this->tail->GetId();
	}

	bool EmployeeList::InsertNode(EmployeeNode * node){
		if(this->head == NULL && this->tail == NULL){
			this->head=node;
			this->tail=this->head;
		}else{
			this->tail->ChangeNextNode(node);
			this->tail=node;
		}
		this->IncreaseLength();
		return true;
	}

	bool EmployeeList::DeleteNode(EmployeeNode * pre_node, EmployeeNode * node){
		if(!pre_node){
			this->ChangeHead(node->GetNext());
			if(!node->GetNext()){
				this->ChangeTail(NULL);
			}
		}else{
			pre_node->ChangeNextNode(node->GetNext());
			if(!node->GetNext()){
				this->ChangeTail(pre_node);
			}
		}
		this->InsertDeletedNumber(this->GetNumberDeleted(),node->GetId());
		this->IncreaseNumberDeleted();
		delete node;
		if(this->GetNumberDeleted() >= re_list_threshhold){
			this->RefreshList();
		}
		return true;
	}

	int EmployeeList::IncreaseLength(){
		return ++this->length;
	}
	int EmployeeList::DecreaseLength(){
		return --this->length;
	}
	int EmployeeList::IncreaseNumberDeleted(){
		return ++this->number_deleted;
	}
	void EmployeeList::ClearNumberDeleted(){
		this->number_deleted = 0;
		return;
	}
	void EmployeeList::InsertDeletedNumber(int pos,int id){
		this->delete_number[pos]=id;
		return;
	}
	void EmployeeList::ClearDeletedNumber(){
		std::memset(this->delete_number, 0, sizeof(int)*re_list_threshhold); 
		return;
	}

	bool EmployeeList::RefreshList(){
		std::sort(this->delete_number,this->delete_number+re_list_threshhold);
		int metric=this->GetTailId();
		EmployeeNode * node=this->GetHead();
		int count=0;
		while(node != NULL){
			while(node->GetId() > this->delete_number[count]){
				count++;
			}
			node->ChangeId(node->GetId()-count);
			node = node->GetNext();
		}
		this->ClearNumberDeleted();
		this->ClearDeletedNumber();
		return true;
	}

	bool EmployeeList::ChangeHead(EmployeeNode * node){
		this->head=node;
		return true;
	}
	bool EmployeeList::ChangeTail(EmployeeNode * node){
		this->tail=node;
		return true;
	}
}
