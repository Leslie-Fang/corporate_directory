#ifndef EMPLOYEE_LIST_HPP
#define EMPLOYEE_LIST_HPP

#include <string>
#include "employee_node.hpp"
#include "employee_list.hpp"

class EmployeeList{
private:
	EmployeeNode * head;
	EmployeeNode * tail;
	int length;
	int number_deleted;
	int * delete_number;
public:
	EmployeeList();
	~EmployeeList();
	int GetTailId();
	EmployeeNode * GetHead();
	EmployeeNode * GetTail();
	int GetNumberDeleted();
	int GetLength();
	int * GetDeletedNumber();
	bool InsertNode(EmployeeNode * node);
	bool DeleteNode(EmployeeNode * pre_node, EmployeeNode * node);
	bool ChangeHead(EmployeeNode * node);
	bool ChangeTail(EmployeeNode * node);
	int IncreaseLength();
	int DecreaseLength();
	int IncreaseNumberDeleted();
	void ClearNumberDeleted();
	void InsertDeletedNumber(int pos,int id);
	void ClearDeletedNumber();
	bool RefreshList();
};
#endif