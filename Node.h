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

#include "Data.h"


/********************************************************************************************************************
* Class name: Node template <class T>
* Description: Node class stores student information including absent dates and a self-referntial pointer for pNext
*              In this program T replaces with data type called Data.
*********************************************************************************************************************/
template <class T> //replacing data type with T
class Node
{
public:

	Node(T& newStudentData); //when creating a template, assume that data cant be small

	T& getStudentData(); //make sure to pass by referance
	Node<T>* getpNext();

	void setStudentData(T& newStudentData);
	void setpNext(Node<T>* newpNext);

private:
	T studentData; //
	Node<T>* pNext; //self referential!
};

//ifstream& operator>>(ifstream& fileStream, Node& studentRecord);
//

// after updating the copy and sent it back to the original


/********************************************************************************************************************
* Function: Node() template <class T>
* Description: A copy constructor for Node.
* Input parameters: newStudentData: student data object passed by referance.
* Returns: Nothing
*********************************************************************************************************************/
template <class T>
Node<T>::Node(T& newStudentData) //the only time creating a node is when extracting data!! so do we need a default constructor forththis>?
//not really!!! //instead we will define it on the heap!! using the new keyword!!!
{
	studentData = newStudentData; //is this possible!!!!!??? I guess in struct is?
	pNext = nullptr;
}

/********************************************************************************************************************
* Function: getStudentData() template <class T>
* Description: A getter function for studentData, one of private members. Used for accessibility
*              to its data in a different class.
* Input parameters: Nothing
* Returns: studentData (pased by referance)
*********************************************************************************************************************/
template <class T>
T& Node<T>::getStudentData()
{
	return studentData;
}


/********************************************************************************************************************
* Function: getpNext() template <class T>
* Description: A getter function for pNext, one of private members. Used for accessibility
*              to its data in a different class.
* Input parameters: Nothing
* Returns: pNext
*********************************************************************************************************************/
template <class T>
Node<T>* Node<T>::getpNext()
{
	return pNext;
}


/********************************************************************************************************************
* Function: setStudentData() template <class T>
* Description: A setter function for studentData, one of private members in Node class. Used for updating its
*              data with a differnet value in a different class.
* Input parameters: newStudentData: student Data object passed by referance.
* Returns: Nothing
*********************************************************************************************************************/
template <class T>
void Node<T>::setStudentData(T& newStudentData)
{
	studentData = newStudentData;
}


/********************************************************************************************************************
* Function: setStudentpNext() template <class T>
* Description: A setter function for pNext, one of private members in Node class. Used for updating its
*              data with a differnet value in a different class.
* Input parameters: pNext: pointer to a Node.
* Returns: Nothing
*********************************************************************************************************************/
template <class T>
void Node<T>::setpNext(Node<T>* newpNext)
{
	pNext = newpNext;
}

