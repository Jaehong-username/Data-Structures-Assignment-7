#include "Stack.h"


/********************************************************************************************************************
* Function: Stack()
* Description: A default constructor for Stack class. It populatesan array memory on the heap, initializing private
*              data members. The starting index is an empty string initially. Stack data structure is implemented in
*              an array fashion.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
Stack::Stack()
{
	total_absences = 0;
	pTop = new string[20];
	pTop[0] = "";
	maxSize = 20;
	currentSize = 0;

}

//Stack::~Stack()
//{
//	delete[] pTop; //deleting the array on the heap?
//}

/********************************************************************************************************************
* Function: getpTop()
* Description: A getter function for pTop, one of private members. Used for accessibility
*              to its data in a different class.
* Input parameters: Nothing
* Returns: pTop: a pointer to an array.
*********************************************************************************************************************/
string* Stack::getpTop()
{
	return pTop;
}


/********************************************************************************************************************
* Function: getTotalAbsences()
* Description: A getter function for total_absences, one of private members. Used for accessibility
*              to its data in a different class.
* Input parameters: Nothing
* Returns: total_absences
*********************************************************************************************************************/
int Stack::getTotalAbsences()
{
	return total_absences;
}

/********************************************************************************************************************
* Function: getCurrentSize()
* Description: A getter function for currentSize, one of private members. Used for accessibility
*              to its data in a different class.
* Input parameters: Nothing
* Returns: currentSize.
*********************************************************************************************************************/
int Stack::getCurrentSize()
{
	return currentSize;
}


/********************************************************************************************************************
* Function: isEmpty()
* Description: It checks for whether or not the stack is empty or not by checking the array pTop.
* Input parameters: Nothing
* Returns: bool
*********************************************************************************************************************/
bool Stack::isEmpty()
{
	if (pTop == nullptr) return true;
	
	return false;
}


/********************************************************************************************************************
* Function: push()
* Description: This pushes the most recent date for a student on the top of the stack.
* Input parameters: absentDate: data to be pushed in (passed by referance).
* Returns: Nothing
*********************************************************************************************************************/
void Stack::push(string& absentDate)
{
	if (currentSize < maxSize)
	{
		pTop[currentSize] = absentDate;
		currentSize++;

		total_absences++;
	}
	
	else
	{
		cout << "You failed the clas! since you exceeded the number of absences." << endl;
	}
	
}

/********************************************************************************************************************
* Function: pop()
* Description: It removes the most recent data on a student from the top of the stack.
* Input parameters: Nothing
* Returns: bool
*********************************************************************************************************************/
void Stack::pop()
{
	if (!isEmpty())
	{
		currentSize--;

		total_absences--;
	}

	else
	{
		cout << "Nothing in the stack for pop!" << endl;
	}
}


/********************************************************************************************************************
* Function: clearStack()
* Description: This cleas the entire stack, so that absent dates when loading the linked list don't multiply.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
void Stack::clearStack()
{
	int tempCurrentSize = currentSize;

	if (tempCurrentSize > 0)
	{
		for (int i = 0; i < tempCurrentSize; i++)
		{
			pop();
			//currentSize--; no need!! because pop function already decrements the size!!!
		}
	}

	else if (tempCurrentSize == 0) cout << "There is nothing to clear the stack, it is empty!!\n" << endl;
	
}

/********************************************************************************************************************
* Function: peek()
* Description: This gets the most data on the top of the Stack which is the most recent absent date.
* Input parameters: Nothing
* Returns: pTop[currentSize - 1]: the most recent absent date
*********************************************************************************************************************/
string Stack::peek()
{
	return pTop[currentSize - 1];
}


/********************************************************************************************************************
* Function: getAllAbsenceDates()
* Description: This prints out all absent dates from the stack to the console output.
* Input parameters: Nothing
* Returns: allAbsenceDates
*********************************************************************************************************************/
string Stack::getAllAbsenceDates()
{
	string absenceDate = "";
	string allAbsenceDates = "";
	string totalAbsencesStr = "";
	//string and stream were named the same didnkt know what to do it.
	std::ostringstream totalAbsencesStream;
	totalAbsencesStream << total_absences;
	totalAbsencesStr = totalAbsencesStream.str();
	
	//function overloading!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	

	if (currentSize == 0)
	{
		allAbsenceDates = "," + totalAbsencesStr;
	}

	else if (currentSize > 0)
	{
		allAbsenceDates = "," + totalAbsencesStr;

		for (int i = 0; i < currentSize; i++)
		{
			absenceDate = "," + pTop[i];
			allAbsenceDates = allAbsenceDates + absenceDate;
		}
	}

	return allAbsenceDates;
}
