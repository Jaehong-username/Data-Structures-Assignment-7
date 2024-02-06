#include "Data.h"


//initialize  memory
//allocate meory
//some basic computatiation needed


//Data student1; //after invoking the default constructor!!! for cohesive!!!

//fileStream >> student1; outside of the consturctor 

// pMem = new Node(student1); //no need foe default constructor for node because we tying to define it on the heap!!!
//default constructor for defing on the call stack. delete and new key words only dealing with data on  the heap we manually control of!!!
//new and delete not dealing with memory on the call stack.

//once declare an  object varaible default constructor invoked and be on the call stack, and when the local function ends.
//the program automatically deallocates memory on the call stack.

//if we define a node on the call stack. it just really hard to have full control of like when inering or deleting etc.
//what about pointer?? well let's say we define a linked list on the stack and we insert a node at the front using the local function
//but once that function ends memory is gone other nodes problematic!! as well

//if list we define it on the call stack	!! that is the reason why we have all isertion and deletion function we define as member functions.
//so that we can have more manual control of on the call stack!! otherwise program will automatcially decide to de allocate stuff like that

//but for data memory defined on the heap, we dont need like insert or delete because we can manually control it!!

//we x need for default constructor because we not gonna write Node n; which is invoking a default constructor

//delete !!!! delete is deallocating on the heap!!

//we cannot delete memory on the stack only program can control of that!!



/********************************************************************************************************************
* Function: Data()
* Description: A default constructor for Data class. It initializes its private members
* Input parameters:Nothing
* Returns: Nothing
*********************************************************************************************************************/
Data::Data(/*istream& fileStream*/) //constructor should not change the state of the program.  constructor for only initializing
{ //here would set the basic value!!!
	//fileStream >> *this;
	recordNumber = "";
	idNumber = "";
	name = "";
	email = "";
	units = "";
	program = "";
	level = "";

	totalAbsences = 0;
	//absenceStack = nullptr;
}



/********************************************************************************************************************
* Function: getRecordNumber()
* Description: A getter function for recordNumber, one of private members. Used for accessibility
*              to its data in a different class.
* Input parameters: Nothing
* Returns: recordNumber
*********************************************************************************************************************/
string Data::getRecordNumber()
{
	return recordNumber;
}

/********************************************************************************************************************
* Function: getIdNumber()
* Description: A getter function for idNumber, one of private members. Used for accessibility
*              to its data in a different class.
* Input parameters: Nothing
* Returns: idNumber
*********************************************************************************************************************/
string Data::getIdNumber()
{
	return idNumber;
}

/********************************************************************************************************************
* Function: getName()
* Description: A getter function for name, one of private members. Used for accessibility
*              to its data in a different class.
* Input parameters: Nothing
* Returns: name
*********************************************************************************************************************/
string Data::getName()
{
	return name;
}

/********************************************************************************************************************
* Function: getEmail()
* Description: A getter function for email, one of private members. Used for accessibility
*              to its data in a different class.
* Input parameters: Nothing
* Returns: email
*********************************************************************************************************************/
string Data::getEmail()
{
	return email;
}

/********************************************************************************************************************
* Function: getUnits()
* Description: A getter function for units, one of private members. Used for accessibility
*              to its data in a different class.
* Input parameters: Nothing
* Returns: units
*********************************************************************************************************************/
string Data::getUnits()
{
	return units;
}

/********************************************************************************************************************
* Function: getProgram()
* Description: A getter function for program, one of private members. Used for accessibility
*              to its data in a different class.
* Input parameters: Nothing
* Returns: program
*********************************************************************************************************************/
string Data::getProgram()
{
	return program;
}

/********************************************************************************************************************
* Function: getLevel()
* Description: A getter function for level, one of private members. Used for accessibility
*              to its data in a different class.
* Input parameters: Nothing
* Returns: level
*********************************************************************************************************************/
string Data::getLevel()
{
	return level;
}

/********************************************************************************************************************
* Function: getTotalAbsences()
* Description: A getter function for totalAbsences, one of private members. Used for accessibility
*              to its data in a different class.
* Input parameters: Nothing
* Returns: totalAbsences
*********************************************************************************************************************/
int Data::getTotalAbsences()
{
	return totalAbsences;
}

/********************************************************************************************************************
* Function: getAbsenceStack()
* Description: A getter function for absenceStack, one of private members. Used for accessibility
*              to its data in a different class.
* Input parameters: Nothing
* Returns: absenceStack (passed by referance instead of a copy of a Stack object.
*********************************************************************************************************************/
Stack& Data::getAbsenceStack() //should be pass by referance!!!
{
	return absenceStack;
}



/********************************************************************************************************************
* Function: setRecordNumber()
* Description: A setter function for recordNumber, one of private members in Data class. Used for updating its
*              data with a differnet value in a different class.
* Input parameters: newRecordNumber
* Returns: Nothing
*********************************************************************************************************************/
void Data::setRecordNumber(string newRecordNumber)
{
	recordNumber = newRecordNumber;
}

/********************************************************************************************************************
* Function: setIdNumber()
* Description: A setter function for idNumber, one of private members in Data class. Used for updating its
*              data with a differnet value in a different class.
* Input parameters: newIdNumber
* Returns: Nothing
*********************************************************************************************************************/
void Data::setIdNumber(string newIdNumber)
{
	idNumber = newIdNumber;
}

/********************************************************************************************************************
* Function: setName()
* Description: A setter function for name, one of private members in Data class. Used for updating its
*              data with a differnet value in a different class.
* Input parameters: newName
* Returns: Nothing
*********************************************************************************************************************/
void Data::setName(string newName)
{
	name = newName;
}

/********************************************************************************************************************
* Function: setEmail()
* Description: A setter function for email, one of private members in Data class. Used for updating its
*              data with a differnet value in a different class.
* Input parameters: newEmail
* Returns: Nothing
*********************************************************************************************************************/
void Data::setEmail(string newEmail)
{
	email = newEmail;
}

/********************************************************************************************************************
* Function: setUnits()
* Description: A setter function for units, one of private members in Data class. Used for updating its
*              data with a differnet value in a different class.
* Input parameters: newUnits
* Returns: Nothing
*********************************************************************************************************************/
void Data::setUnits(string newUnits)
{
	units = newUnits;
}

/********************************************************************************************************************
* Function: setProgram()
* Description: A setter function for program, one of private members in Data class. Used for updating its
*              data with a differnet value in a different class.
* Input parameters: newProgram
* Returns: Nothing
*********************************************************************************************************************/
void Data::setProgram(string newProgram)
{
	program = newProgram;
}

/********************************************************************************************************************
* Function: setLevel()
* Description: A setter function for level, one of private members in Data class. Used for updating its
*              data with a differnet value in a different class.
* Input parameters: newLevel
* Returns: Nothing
*********************************************************************************************************************/
void Data::setLevel(string newLevel)
{
	level = newLevel;
}

/********************************************************************************************************************
* Function: setTotalAbsences()
* Description: A setter function for totalAbsences, one of private members in Data class. Used for updating its
*              data with a differnet value in a different class.
* Input parameters: newTotalAbsences
* Returns: Nothing
*********************************************************************************************************************/
void Data::setTotalAbsences(int newTotalAbsences)
{
	totalAbsences = newTotalAbsences;
}


/********************************************************************************************************************
* Function: setAbsenceStack()
* Description: A setter function for newAbsenceStack, one of private members in Data class. Used for updating its
*              data with a differnet value in a different class.
* Input parameters: newAbsenceStack
* Returns: Nothing
*********************************************************************************************************************/
void Data::setAbsenceStack(Stack newAbsenceStack)
{
	absenceStack = newAbsenceStack;
}



/********************************************************************************************************************
* Function: operator>>()
* Description: Extracts data from csv file and stores into a node of the linked list.
* Input parameters: fileStream: an input file stream. studentData: Data object passed by referance.
* Returns: fileStream
*********************************************************************************************************************/
ifstream& operator>>(ifstream& fileStream, Data& studentData)
{
	char line[200];

	string tempRecordNumber = "";
	string tempIdNumber = "";

	string tempLastName = "";
	string tempFirstName = "";
	string tempName = "";


	string tempEmail = "";
	string tempUnits = "";
	string tempProgram = "";
	string tempLevel = "";

	//int tempTotalAbsences = 0;
	//string absentDates = "";
	//Stack tempAbsenceStack;

	//fileStream.getline(line, 100); //extract one line!!!!
	fileStream.getline(line, 200);

	tempRecordNumber = strtok(line, ",\n");
	tempIdNumber = strtok(NULL, ",\n");

	tempLastName = strtok(NULL, ",\n");
	tempLastName = tempLastName + "," + " ";
	tempFirstName = strtok(NULL, ",\n");
	tempName = tempLastName + tempFirstName;

	tempEmail = strtok(NULL, ",\n");
	tempUnits = strtok(NULL, ",\n");
	tempProgram = strtok(NULL, ",\n");
	tempLevel = strtok(NULL, ",\n");

	//if (tempLevel[i] == '\n') //which means we are dealing with classList.csv which doesn't include absent dates.
	//{
	//	tempTotalAbsences = *(strtok(NULL, ",\n"));
	//	studentData.setTotalAbsences(tempTotalAbsences);
	//	for (int i = 0; i < tempTotalAbsences; i++)
	//	{
	//		absentDates = strtok(NULL, ",\n");
	//		studentData.getAbsenceStack().push(absentDates);
	//	}
	//}
	
	//tempTotalAbsences = atoi(strtok(NULL, ",\n"));

	studentData.setRecordNumber(tempRecordNumber);
	studentData.setIdNumber(tempIdNumber);
	studentData.setName(tempName);
	studentData.setEmail(tempEmail);
	studentData.setUnits(tempUnits);
	studentData.setProgram(tempProgram);
	studentData.setLevel(tempLevel);

	//if (tempTotalAbsences == 0); //no absent!!
	//if(tempTotalAbsences > 0) //have been absent at least once. before we will put the date of absence in the stack
	//{
	//	 //define a Stack object invoking a default constructor
	//	string tempAbsentDate = "";
	//	

	//	for (int i = 0; i < tempTotalAbsences; i++)
	//	{
	//		tempAbsentDate = strtok(NULL, ",\n");
	//		studentData.getAbsenceStack().push(tempAbsentDate);
	//	}
	//}
	//studentData.setAbsenceStack(tempAbsenceStack);

	return fileStream;
}


//since manually controllin the node. I dont need a constructor or destructor for node.

//List we create all the insertion and deletion functions we x have auto control of the list 
