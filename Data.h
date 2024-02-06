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

#include "Stack.h"


/********************************************************************************************************************
* Class name: Data
* Description: This Data class has data members of student information
*********************************************************************************************************************/
class Data
{
public:
	Data();

	string getRecordNumber();
	string getIdNumber();
	string getName();
	string getEmail();
	string getUnits();
	string getProgram();
	string getLevel();

	int getTotalAbsences();
	Stack& getAbsenceStack();
	void setRecordNumber(string newRecordNumber);
	void setIdNumber(string newIdNumber);
	void setName(string newName);
	void setEmail(string newEmail);
	void setUnits(string newUnits);
	void setProgram(string newProgram);
	void setLevel(string newLevel);

	void setTotalAbsences(int newTotalAbsences);
	void setAbsenceStack(Stack newAbsenceStack);

private:
	string recordNumber; //max 3digits
	string idNumber; //max 9digits
	string name; //(last, first)
	string email;
	string units; //(number of credits for class or AU for audit)
	string program; //major
	string level;  //(freshman, sophomore, junior, senior, graduate)

	int totalAbsences;
	//Stack* absenceStack; pointer not working???????? Question!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	Stack absenceStack;
};

//insertion and extraction operator overloading!!!!!
//ostream is inclusive of ofstream!!!


ifstream& operator>>(ifstream& fileStream, Data& studentData); //extraction pass by referance!!