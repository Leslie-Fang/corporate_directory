#ifndef EMPLOYEE_NODE_HPP
#define EMPLOYEE_NODE_HPP

#include <string>

class EmployeeNode{
private:
	int id;
	std::string name;
	int phone_number;
	EmployeeNode * next;
public:
	EmployeeNode(std::string name, int phone_number);
	int GetId();
	std::string GetName();
	int GetPhoneNumber();
	EmployeeNode * GetNext();
	bool ChangeNextNode(EmployeeNode * node);
	bool ChangePhoneNumber(int phone_number);
	bool ChangeId(int id);
};

#endif