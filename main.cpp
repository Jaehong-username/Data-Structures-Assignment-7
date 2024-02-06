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

#include "Menu.h"

int main(void)
{
	/*int a = 100;
	std::to_string(a);*/

	Menu runProgram;
	runProgram.runMenu();
	//char newAbsentYear[10];
	//std::sprintf(newAbsentYear, "%d", now->tm_year + 1900);
	//string strYear = newAbsentYear;
	//char newAbsentMonth[10];
	//std::sprintf(newAbsentYear, "%d", now->tm_mon + 1);
	//string strMonth = newAbsentMonth;
	//char newAbsentDay[10];
	//std::sprintf(newAbsentDay, "%d", now->tm_mday);
	//string strDay = newAbsentYear;
	//string newAbsentDate = strYear + "-" + strMonth + "-" + strDay;
	return 0;
}