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
	int Number_deleted;
	int * deleteNumber;
public:
	EmployeeList();
	~EmployeeList();
	int GetTailId();
	bool InsertNode(EmployeeNode * node);
	EmployeeNode * GetHead();
};
#endif