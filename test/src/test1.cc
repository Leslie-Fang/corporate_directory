#include <limits.h>
#include <queue>
#include "gtest/gtest.h"
#include "main.hpp"
#include "global.hpp"
#include "employee_node.hpp"
#include "employee_list.hpp"

class EmployeeListTest : public ::testing::Test {
protected:
	virtual void SetUp() {
		employee_directory_list = new EmployeeList();
	}
};

// Tests employ_list.
TEST_F(EmployeeListTest, InitList) {
  EXPECT_EQ(NULL, employee_directory_list->GetHead());
  EXPECT_EQ(NULL, employee_directory_list->GetTail());
  EXPECT_EQ(0, employee_directory_list->GetLength());
  EXPECT_EQ(0, employee_directory_list->GetNumberDeleted());
  //EXPECT_EQ(re_list_threshhold, sizeof(employee_directory_list->GetDeletedNumber()));
}
