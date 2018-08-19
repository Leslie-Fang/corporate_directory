#ifndef MAIN_HPP
#define MAIN_HPP
#include <map>
#include "employee_node.hpp"
#include "employee_list.hpp"
//extern Employee_List * Employee_Directory_List;
typedef int(*BrewFunction)();
typedef std::map<int,BrewFunction> BrewMap;
void RegisterBrewFunction(int id, BrewFunction func);

#endif