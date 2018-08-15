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
	int GetId();
	bool ChangeNextNode(Employee_Node * node);
};

#endif