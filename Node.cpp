//#include "Node.h"

//Node::Node(Data& newStudentData) //the only time creating a node is when extracting data!! so do we need a default constructor forththis>?
////not really!!! //instead we will define it on the heap!! using the new keyword!!!
//{
//    studentData = newStudentData; //is this possible!!!!!??? I guess in struct is?
//    pNext = nullptr;
//}
//
//
//Data& Node::getStudentData()
//{
//    return studentData;
//}
//
//
//Node* Node::getpNext()
//{
//    return pNext;
//}
//
//
//void Node::setStudentData(Data& newStudentData)
//{
//    studentData = newStudentData;
//}
//
//
//void Node::setpNext(Node* newpNext)
//{
//    pNext = newpNext;
//}

//ifstream& operator>>(ifstream& fileStream, Node& studentRecord)
//{
//	char line[300];
//
//	string tempRecordNumber = "";
//	string tempIdNumber = "";
//
//	string tempLastName = "";
//	string tempFirstName = "";
//	string tempName = "";
//
//
//	string tempEmail = "";
//	string tempUnits = "";
//	string tempProgram = "";
//	string tempLevel = "";
//
//	int tempTotalAbsences = 0;
//	//Stack tempAbsenceStack;
//	//fileStream.getline(line, 100); //extract one line!!!!
//	fileStream.getline(line, 100);
//
//	tempRecordNumber = strtok(line, ",\n");
//	tempIdNumber = strtok(NULL, ",\n");
//
//	tempLastName = strtok(NULL, ",\n");
//	tempLastName = tempLastName + "," + " ";
//	tempFirstName = strtok(NULL, ",\n");
//	tempName = tempLastName + tempFirstName;
//
//	tempEmail = strtok(NULL, ",\n");
//	tempUnits = strtok(NULL, ",\n");
//	tempProgram = strtok(NULL, ",\n");
//	tempLevel = strtok(NULL, ",\n");
//
//	tempTotalAbsences = atoi(strtok(NULL, ",\n"));
//
//	
//	studentRecord.getStudentData().setRecordNumber(tempRecordNumber);
//	studentRecord.getStudentData().setIdNumber(tempIdNumber);
//	studentRecord.getStudentData().setName(tempName);
//	studentRecord.getStudentData().setEmail(tempEmail);
//	studentRecord.getStudentData().setUnits(tempUnits);
//	studentRecord.getStudentData().setProgram(tempProgram);
//	studentRecord.getStudentData().setLevel(tempLevel);
//
//	studentRecord.getStudentData().setTotalAbsences(tempTotalAbsences);
//
//	//if (tempTotalAbsences == 0); //no absent!!
//
//	if (tempTotalAbsences > 0) //have been absent at least once. before we will put the date of absence in the stack
//	{
//		//define a Stack object invoking a default constructor
//		string tempAbsentDate = "";
//
//
//		for (int i = 0; i < tempTotalAbsences; i++)
//		{
//			tempAbsentDate = strtok(NULL, ",\n");
//			studentRecord.getStudentData().getAbsenceStack().push(tempAbsentDate);
//		}
//	}
//
//	//studentData.setAbsenceStack(tempAbsenceStack);
//
//	return fileStream;
//}
