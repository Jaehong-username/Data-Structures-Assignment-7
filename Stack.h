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

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <fstream>

#include <string>

#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

using std::ifstream;
using std::ofstream;
using std::istream;
using std::ostream;


/********************************************************************************************************************
* Class name: Stack
* Description: Stack class stores absent dates in stack data structure with the most recent absent date placed on the
*              top of the stack. It is stored in each student Data object.. It also includes total absences as well.
*              The Stack data structure is implemented in an array fashion.
*********************************************************************************************************************/
class Stack
{
public:

	Stack(); //needs a default constructor for this!!!

	//~Stack();

	string* getpTop();

	int getTotalAbsences();

	int getCurrentSize();

	bool isEmpty();

	void push(string& absentDate);

	void pop();

	void clearStack();

	string peek();

	string getAllAbsenceDates();

private:
	/*string pArray[100];
	Stack* pTop;*/

	int total_absences;
	int maxSize;
	int currentSize;
	string* pTop;

};
