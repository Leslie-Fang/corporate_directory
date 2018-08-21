#include <limits.h>
#include <queue>
#include "gtest/gtest.h"
#include "main.hpp"
#include "global.hpp"
#include "employee_node.hpp"
#include "employee_list.hpp"

using directory::EmployeeList;
using directory::employee_directory_list;
using directory::EmployeeNode;

class EmployeeListTest : public ::testing::Test {
protected:
	EmployeeListTest(){}
	virtual void SetUp() {
		employee_directory_list = new EmployeeList();
	}
	virtual void TearDown() {
		delete employee_directory_list;
		employee_directory_list = NULL;
	}
	~EmployeeListTest(){}
};

// Tests employ_list.
TEST_F(EmployeeListTest, InitList) {
	EXPECT_EQ(NULL, employee_directory_list->GetHead());
	EXPECT_EQ(NULL, employee_directory_list->GetTail());
	EXPECT_EQ(0, employee_directory_list->GetLength());
	EXPECT_EQ(0, employee_directory_list->GetNumberDeleted());
	//EXPECT_EQ(re_list_threshhold, sizeof(employee_directory_list->GetDeletedNumber()));
}

TEST_F(EmployeeListTest, InsertNode){
	std::string name="leslie";
	int phone_number = 123;
	employee_directory_list->InsertNode(new EmployeeNode(name,phone_number));
	EXPECT_EQ(name, employee_directory_list->GetHead()->GetName());
	EXPECT_EQ(phone_number, employee_directory_list->GetHead()->GetPhoneNumber());
}
