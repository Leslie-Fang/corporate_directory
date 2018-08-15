#ifndef EMPLOYEE_LIST_HPP
#define EMPLOYEE_LIST_HPP

#include <string>
#include "employee_node.hpp"
#include "employee_list.hpp"

class Employee_List{
private:
	Employee_Node * head;
	Employee_Node * tail;
	int length;
	int Number_deleted;
	int * deleteNumber;
public:
	Employee_List();
	~Employee_List();
	int get_tail_id();
	bool insert_node(Employee_Node * node);
};
#endif