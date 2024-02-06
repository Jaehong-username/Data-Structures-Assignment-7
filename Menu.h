/****************************************************************************************************************************
* Programmer: Jaehong Lee
* Class: CPTs 122, Fall 2023; Lab Section 3 (Tuesday 1:30PM - 4:20PM)
* Programming Assignment: PA7
* Date: November 15, 2023
* Description: This PA assignment is creating a student attendance tracker program. It keeps track of each student's
               attendance records. Absent dates are piled into the stack in the form of an array. Before implementing this
               programm, you must load data from classList.csv to a single linked list by going to menu option 1 first.
               It has an option of removing the most recent absent date for each student using stack data structure.
               Also, this can add absent dates on each student using Stack data structure. Stack is implemented in an array
               fashion. The codes for List and Node classes are written in the form of templates.
****************************************************************************************************************************/

#pragma once

#include "List.h"


/********************************************************************************************************************
* Class name: Menu
* Description: Menu class runs the student attendance tracker program. It has basic menu display and each menu invokes
*              related functions.
*********************************************************************************************************************/
class Menu
{
public:
	void runMenu();

	int exit(void);

private:
	ifstream fileStream; //dont add && error: attempting to refernce a deleted function
	List<Data> masterList;
};
