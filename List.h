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

#include "Node.h"


/********************************************************************************************************************
* Class name: List <class T>
* Description: This List class deals with storing and editing student data in a singly linked list.
*              In this program template argument T replaces data type called Data.
*********************************************************************************************************************/
template <class T>   //replacing data type Data with T!
class List //master list!!!
{
public:

	List();

	//~List();

	void destroyList();

	Node<T>* getpHeadList();

	void setpHeadList(Node<T>* newpHeadList);

	bool isEmpty();

	void insertNode(ifstream& fileStream);
	
	void importCourseList(); //menu option 1 

	void printMasterList(/*Node* newpHeadList*/);

	void loadMasterList();//option 2: load the master list from the csv file

	void storeMasterList(); //option 3

	void markAbsence(); //option 4

	void editAbsence(); //option 5 bonus!

	void generateAbsenceReports(); //option 6 !!!

private:

	Node<T>* pHeadList;
};

ofstream& operator<< (ofstream& fileStream, Data studentData);

ofstream& operator<< (ofstream& fileStream, Node<Data> studentNode);


/********************************************************************************************************************
* Function: List() <template>
* Description: A default constructor for List class. It initializes its private members
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
template <class T>
List<T>::List()
{
    pHeadList = nullptr;
}

//List::~List()
//{  // delete pHeadList;!!!! can;t delete it!!!!
//}

/********************************************************************************************************************
* Function: destroyList() template <class T>
* Description: It destroys the single linked list by deallocating a node in an successive order.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
template <class T>
void List<T>::destroyList() //destroying the preexisting nodes from the list for menu 1 option
{
    if (pHeadList != nullptr)
    {
        Node<T>* pCur = pHeadList;
        Node<T>* tempNode = nullptr;

        while (pCur != nullptr)   // node --->  lastNode ---> nullptr
        {
            tempNode = pCur;
            pCur = tempNode->getpNext(); //move the pointer pCUr
            delete tempNode;
        }

        pHeadList = nullptr; //now entirely destroying the list

        cout << "Destroyed the previous master list successfully!\n" << endl;
    }
}


/********************************************************************************************************************
* Function: getpHeadList() template <class T>
* Description: A getter function for pHeadList, one of private members. Used for accessibility
*              to its data in a different class.
* Input parameters: Nothing
* Returns: pHeadList
*********************************************************************************************************************/
template <class T>
Node<T>* List<T>::getpHeadList()
{
    return pHeadList;
}

/********************************************************************************************************************
* Function: setpHeadList() template <class T>
* Description: A setter function for pHeadList, one of private members in List class. Used for updating its
*              data with a differnet address in a different class.
* Input parameters: newpHeadList
* Returns: Nothing
*********************************************************************************************************************/
template <class T>
void List<T>::setpHeadList(Node<T>* newpHeadList)
{
    pHeadList = newpHeadList;
}


/********************************************************************************************************************
* Function: isEmpty <class T>
* Description: Returns true if the list is empty or false otherwise by checking the pHeadList.
* Input parameters: Nothing
* Returns: bool
*********************************************************************************************************************/
template <class T>
bool List<T>::isEmpty() //since this is a member function I dont need to pass in arguments
{
    if (pHeadList == nullptr) return true;

    return false;
}


/********************************************************************************************************************
* Function: insertNode() <class T>
* Description: It inserts a node that contains data and pNext pointer to the single linked list that stores student
*              information and absent dates.
* Input parameters: fileStream: input file stream
* Returns: Nothing
*********************************************************************************************************************/
template <class T>
void List<T>::insertNode(ifstream& fileStream)
{
    T studentData;
    fileStream >> studentData; //using the function overloading!!!
    Node<T>* pMem = new Node<T>(studentData);
    //successfully created a node!! now will alwys be placed at the front!!!

    if (isEmpty())
    {
        pHeadList = pMem;
    }

    else //phead list not empty!!!
    {
        pMem->setpNext(pHeadList);
        pHeadList = pMem;
        /*pMem = pHeadList->getpNext(); //made a mistake!!!
        pHeadList = pMem;*/
    }

}



/********************************************************************************************************************
* Function: importCourseList <class T>
* Description: This imports data from classList.csv file to the single linked list.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
template <class T>
void List<T>::importCourseList() //destorys the preexisting list !! and overwrites!!!
{
    if (pHeadList != nullptr) //if not nullptr, then destroy the list!!!! //since all the node memory is created on the heap!!
    {
        destroyList(); //destroying the list
    }

    ifstream fileStream;
    fileStream.open("classList.csv", std::ios::in); //make sure to include <fstream> library!!!
    char skipFirstLine[100]; //a buffer for the first line!!!!

    if (fileStream.is_open())
    {
        fileStream.getline(skipFirstLine, 100);

        while (!fileStream.eof())
        {
            insertNode(fileStream);
        }

        fileStream.close();
    }

    cout << "Importing the course list from classList.csv to the list is complete!!!\n" << endl;

    cout << "And here is the display of the classList.csv file in the list format!!!!\n" << endl << endl;

    printMasterList();
}


/********************************************************************************************************************
* Function: printMasterList <class T>
* Description: It prints the linked list information stored to the console
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
template <class T>
void List<T>::printMasterList()
{
    Node<T>* pCur = pHeadList;

    while (pCur != nullptr)
    {
        cout << "- Record Number: " << pCur->getStudentData().getRecordNumber() << endl;
        cout << "- ID Number: " << pCur->getStudentData().getIdNumber() << endl;
        cout << "- Name (last, first): " << pCur->getStudentData().getName() << endl;
        cout << "- Email: " << pCur->getStudentData().getEmail() << endl;
        cout << "- Units(number of credits for class or AU for audit): " << pCur->getStudentData().getUnits() << endl;
        cout << "- Program(major): " << pCur->getStudentData().getProgram() << endl;
        cout << "- Level(freshman, sophomore, junior, senior, graduate): " << pCur->getStudentData().getLevel() << endl;
        cout << "- Total Absences: " << pCur->getStudentData().getTotalAbsences() << endl;

        if (pCur->getStudentData().getTotalAbsences() == 0)
        {
            cout << "- Absent Dates: No absent dates for this student!" << endl << endl << endl;
        }
        else if (pCur->getStudentData().getTotalAbsences() > 0)
        {
            cout << "- Absent Dates: ";

            for (/*int i = pCur->getStudentData().getAbsenceStack().getCurrentSize() - 1*/int i = pCur->getStudentData().getTotalAbsences() - 1; i >= 0; i--)
            {
                cout << "" << pCur->getStudentData().getAbsenceStack().getpTop()[i] << "   ";
            }

            cout << endl << endl << endl;
        }


        pCur = pCur->getpNext();
    }

}


/********************************************************************************************************************
* Function: loadMasterList() template <class T>
* Description: It loads data from master.csv file to the single linked list.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
template <class T>
void List<T>::loadMasterList() //option 2 //loading master list to the link
{
    if (isEmpty())
    {
        cout << "Please Import the classList.csv data first by going to Menu Option 1!!!\n" << endl;
    }

    else //classlist data is already imported!!!!
    {
        Node<T>* pCurrent = pHeadList; //!!!!!!!!!!!!!!!!!!!!!!!!!!

        ifstream fileStream;
        fileStream.open("master.csv", std::ios::in); //make sure to include <fstream> library!!!
        char skipFirstLine[100];

        if (fileStream.is_open())  //if the file is opened!!
        {
            fileStream.getline(skipFirstLine, 100); //skips the first line

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

            int tempTotalAbsences;
            string absentDates = "";

            while (!fileStream.eof())
            {

                fileStream.getline(line, 200);

                if (strlen(line) < 7) //is gonna check if the line is too short !!!!line far too short!!!
                {
                    continue;
                }

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

                tempTotalAbsences = atoi(strtok(NULL, ",\n"));


                if (tempTotalAbsences == 0)
                {           ///get a copy of the original the copy is being updated not original!!
                    pCurrent->getStudentData().setTotalAbsences(tempTotalAbsences);
                    //solution: make the get data function pass by referance
                }

                else if (tempTotalAbsences > 0)
                {
                    //destroy the stack!!!! otherwise is gonna duplicate itself over and over from the csv file!!!!!!
                    pCurrent->getStudentData().getAbsenceStack().clearStack();

                    pCurrent->getStudentData().setTotalAbsences(tempTotalAbsences); //get total absences never updated!!!????

                    for (int i = 0; i < tempTotalAbsences/*pCurrent->getStudentData().getTotalAbsences() - 1*/; i++) //!!!!!!!!!!!!!!!! off by one error push function invoked more than once!!!!
                    {
                        absentDates = strtok(NULL, ",\n");
                        pCurrent->getStudentData().getAbsenceStack().push(absentDates); //get absence stack as well!!passy by referance
                    }
                }

                pCurrent = pCurrent->getpNext(); //moving the pCur ptr
            }

            fileStream.close(); //finally closing the file
        }

        cout << "Loading data from the master.csv file which includes absence dates to the master list completed!\n" << endl;

        cout << "And here is the display of the master list!!!\n" << endl << endl;

        cout << "----------------------------------Student Course Attendance tracker------------------------------------\n" << endl;

        printMasterList();
    }

}



/********************************************************************************************************************
* Function: storeMasterList() template <class T>
* Description: It stores data from the linked list to the master.csv file.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
template <class T>
void List<T>::storeMasterList() //menu option 3
{
    if (isEmpty())
    {
        cout << "Please Import the classList.csv data first by going to Menu Option 1!!!\n" << endl;
    }

    else
    {
        ofstream fileStream;
        fileStream.open("master.csv", std::ios::out);

        fileStream << ",ID" << ",Name" << ",Email" << ",Units" << ",Program" << ",Level" << ",Total Absences" << ",Absent Dates (If any)" << endl;

        Node<T>* search_ptr = pHeadList;

        while (search_ptr != nullptr)
        {
            fileStream << *search_ptr; //dereferncing the search ptr means to get access to the whole nodd!!!
            search_ptr = search_ptr->getpNext(); //dont forget to update the search ptr to prevent an infinite loop!!!
        }

        fileStream.close();

        cout << "Storing data from the master list to master.csv file completed!!!\n" << endl;
    }

}



/********************************************************************************************************************
* Function: markAbsence() template <class T>
* Description: This marks every student in the list present or absent. If marked absent, total absences increased by one
*              and the recent absent date pushed to the top of the stack.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
template <class T>
void List<T>::markAbsence() //menu option 4!!!
{
    if (isEmpty())
    {
        cout << "Please Import the classList.csv data first by going to Menu Option 1!!!\n" << endl;
    }

    else
    {
        Node<T>* pCur = pHeadList;
        int present_absent = -1;

        while (pCur != nullptr)
        {
            cout << "Student Name: " << pCur->getStudentData().getName() << " presnt or absent for today's class?" << endl;
            cout << "1: Present       2: Absent" << endl;
            cout << "Total Absence for this student right now: " << pCur->getStudentData().getTotalAbsences() << endl;
            cout << "Please type only 1 or 2!: ";
            cin >> present_absent;

            if (present_absent == 1) //present for the class
            {
                cout << "Present for the class on: ";
                time_t t = time(0); // get time now
                struct tm* now = localtime(&t);
                cout << (now->tm_year + 1900) << '-'
                    << (now->tm_mon + 1) << '-'
                    << now->tm_mday
                    << endl;
            }

            else if (present_absent == 2) //absent for the class //total absences incremented by one, and recent datepushed to the stack
            {
                cout << "Absent for the class on: ";
                time_t t = time(0); // get time now
                struct tm* now = localtime(&t);
                cout << (now->tm_year + 1900) << '-'
                    << (now->tm_mon + 1) << '-'
                    << now->tm_mday
                    << endl;

                //function overloading!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                string newAbsentDate = "";
                std::stringstream strConvert;
                strConvert << (now->tm_year + 1900) << "-" << (now->tm_mon + 1) << "-" << (now->tm_mday);
                strConvert >> newAbsentDate;

                //string test = std::to_string(now->tm_year + 1900); //using to_string!!!

                if (pCur->getStudentData().getAbsenceStack().getpTop()[0] != "" && newAbsentDate == pCur->getStudentData().getAbsenceStack().peek())
                {
                    cout << "You already makred the student absent!!!\n" << endl;
                }

                else
                {
                    cout << "\nTotal absences now increased by one for this student!" << endl;
                    pCur->getStudentData().setTotalAbsences(pCur->getStudentData().getTotalAbsences() + 1);
                    pCur->getStudentData().getAbsenceStack().push(newAbsentDate); //pushing the new absent date to top of the stack!!!
                    cout << "Total absences now: " << pCur->getStudentData().getTotalAbsences();
                }



            }

            cout << "\n-------------------------------------------------------------------------------------" << endl << endl;

            pCur = pCur->getpNext();
        }
    }
}



/********************************************************************************************************************
* Function: editAbsence() template <class T>
* Description: This removes the most recent absent date on a student who was initially marked absent but later determined
*              to be present.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
template <class T>
void List<T>::editAbsence() //Bonus option!!!!
{
    if (isEmpty())
    {
        cout << "Please Import the classList.csv data first by going to Menu Option 1!!!\n" << endl;
    }

    else
    {
        Node<T>* search_ptr;
        string search_String_ID;
        int search_again = 0;

        do
        {
            search_again = 0;
            //also nedd to reset the search_ptr to pHeadlist just in case!!!
            search_ptr = pHeadList;
            cout << "Please Enter a student Name or a student ID to find the student before editing the most recent absences.\n" << endl;
            cin >> search_String_ID;

            while (search_String_ID != search_ptr->getStudentData().getName() &&
                search_String_ID != search_ptr->getStudentData().getIdNumber())
            {
                search_ptr = search_ptr->getpNext();

                if (search_ptr == nullptr)
                {
                    cout << "\nThe student name or ID you typed does not exist in our record!\n" << endl;
                    cout << "Please double check!!\n" << endl;
                    search_again = 1;
                    system("pause");
                    system("cls");
                    break;
                }
            }

            //once we found it out of the loop!!!                        //order matters!! because left to right!!
            if (search_again != 1 && search_String_ID == search_ptr->getStudentData().getName() /*&& search_again != 1*/ ||
                search_again != 1 && search_String_ID == search_ptr->getStudentData().getIdNumber() /*&& search_again != 1*/)
            {

                if (search_ptr->getStudentData().getTotalAbsences() > 0)
                {
                    //edit the student absence!!! using the current search pointer
                    search_ptr->getStudentData().getAbsenceStack().pop(); //remove the absence the recent absent date!!!
                    search_ptr->getStudentData().setTotalAbsences(search_ptr->getStudentData().getTotalAbsences() - 1);

                    cout << "The most recent absent date for this student was successfully removed!\n" << endl;
                    cout << "Total Absences: " << search_ptr->getStudentData().getTotalAbsences();
                }

                else if (search_ptr->getStudentData().getTotalAbsences() == 0)
                {
                    cout << "This student has had no absent dates so far!\n" << endl;
                    cout << "Please double check it!\n" << endl;
                    search_again = 1;
                }

            }

        } while (search_again == 1);
    }

}


/********************************************************************************************************************
* Function: generateAbsenceReports() template <class T>
* Description: This generates two reports on absenceReport.csv and absenceThreshold.txt. absenceReport.csv stores all 
*              students from the list with the most recent absent date and total absences. Then, absenceThreshold.txt
*              only includes the name of students who have total absences greater than the threshold set by an user.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
template <class T>
void List<T>::generateAbsenceReports()
{
    if (isEmpty())
    {
        cout << "Please Import the classList.csv data first by going to Menu Option 1!!!\n" << endl;
    }

    else
    { //if absence dates is - theabsence stack has not been created yet so if peek function usage will crash the program

        cout << "Remember that the two reports generated are based on data from the linked list of student absence data! instead of the one from master.csv file!\n" << endl;
        cout << "The report data is not from the master.csv!!!\n" << endl;
        cout << "If you want to generate the two reports based on master.csv file data\n" << endl;
        cout << "please load its data on the linked list updated by going to Menu option 2!!\n" << endl;

        Node<T>* search_ptr = pHeadList;

        ofstream reportFileStream;
        reportFileStream.open("absenceReport.txt", std::ios::out); //once opens erases everythinbg on the output file

        reportFileStream << "A list of all students in the course with absent times and the most recent date" << endl << endl << endl;

        reportFileStream << "If there is no list of name on the file, it means that no one has total absences above the threshold!\n << endl";

        while (search_ptr != nullptr)
        {
            reportFileStream << search_ptr->getStudentData(); //how to write the code if its Data&
            search_ptr = search_ptr->getpNext();
        }

        reportFileStream.close();


        //////////////////////////////Now it is a second report
        int threshold = 0;
        search_ptr = pHeadList;
        ofstream absenceFileStream;
        absenceFileStream.open("absenceThreshold.txt", std::ios::out); //once opens erases everythinbg on the output file

        cout << "How many absences you would like to set up for a threshold?" << endl;
        cin >> threshold;

        absenceFileStream << "A list of students' Total Absences greather than the threshold: " << threshold << endl << endl;

        while (search_ptr != nullptr)
        {
            if (search_ptr->getStudentData().getTotalAbsences() > threshold) //only greater than the threshhold1
            {
                absenceFileStream << search_ptr->getStudentData().getName() << endl << endl;
            }

            search_ptr = search_ptr->getpNext();
        }

        absenceFileStream.close();

        cout << "\n\nAll student report with absent dates is generated on absenceReport.txt" << endl << endl;

        cout << "Student report with number of absences greater than the threshold is generated on absenceThreshold.txt" << endl << endl;
    }


}


//string operator+(int lhs, string rhs);
//string operator+(string lhs, int rhs);



////for generating reports!!!!!!
// //replacing Data type with class T!
//
//ofstream& operator<< (ofstream& fileStream, Data studentData)
//{
//    fileStream << "Student Name: " << studentData.getName() << endl;
//    fileStream << "Number of absences: " << studentData.getTotalAbsences() << endl;
//
//    if (studentData.getTotalAbsences() == 0)
//    {
//        fileStream << "The most recent absent date: Does not exist!" << endl << endl;
//    }
//
//    else if (studentData.getTotalAbsences() > 0)
//    {
//        fileStream << "The most recent absent date: " << studentData.getAbsenceStack().peek() << endl << endl;
//    }
//
//    return fileStream;
//}
//
//
//
//ofstream& operator<< (ofstream& fileStream, Node<Data> studentNode)
//{
//    fileStream << studentNode.getStudentData().getRecordNumber() << ",";
//    fileStream << studentNode.getStudentData().getIdNumber() << ",";
//    fileStream << studentNode.getStudentData().getName() << ",";
//    fileStream << studentNode.getStudentData().getEmail() << ",";
//    fileStream << studentNode.getStudentData().getUnits() << ",";
//    fileStream << studentNode.getStudentData().getProgram() << ",";
//    fileStream << studentNode.getStudentData().getLevel();
//    //fileStream << studentNode.getStudentData().getTotalAbsences();
//    fileStream << studentNode.getStudentData().getAbsenceStack().getAllAbsenceDates() << endl;
//
//    return fileStream;
//}