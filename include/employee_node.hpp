#ifndef EMPLOYEE_NODE_HPP
#define EMPLOYEE_NODE_HPP

#include <string>

class Employee_Node{
private:
	int id;
	std::string name;
	int phone_number;
	Employee_Node * next;
public:
	Employee_Node(std::string name, int phone_number);
	int get_id();
	bool change_next_node(Employee_Node * node);
};

#endif