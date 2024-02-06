#include "Menu.h"


/********************************************************************************************************************
* Function: runMenu()
* Description: This function runs the student attendance tracker program
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
void Menu::runMenu()
{
	int again = 1;
	int choice = 0;
	
	do
	{
		again = 1;
		
		cout << "Today's date: ";
		time_t t = time(0); // get time now
		struct tm* now = localtime(&t);
		cout << (now->tm_year + 1900) << '-'
			<< (now->tm_mon + 1) << '-'
			<< now->tm_mday
			<< endl;

		cout << "\nAttendance Tracker Program!" << endl << endl;

		cout << "Main Menu Display\n\n" << endl;

		cout << "1. Import course list" << endl;
		cout << "2. Load Master list" << endl;
		cout << "3. Store Master list" << endl;
		cout << "4. Mark Absences" << endl;
		cout << "5. Edit Absences" << endl;
		cout << "6. Generate Report" << endl;
		cout << "7. Exit" << endl << endl;

		cout << "Please enter number 1~7 to choose a menu option!" << endl << endl;
		cout << "Please import data from classList.csv to the program first before implementing any other menu functions!!\n" << endl;

		cin >> choice;
		
		switch (choice)
		{
		case 1: 
			system("cls");
			masterList.importCourseList();
			putchar('\n');
			system("pause");
			system("cls");
			break;

		case 2:
			system("cls");
			masterList.loadMasterList();
			putchar('\n');
			system("pause");
			system("cls");
			break;

		case 3:
			system("cls");
			masterList.storeMasterList();
			putchar('\n');
			system("pause");
			system("cls");
			break;

		case 4:
			system("cls");
			masterList.markAbsence();
			putchar('\n');
			system("pause");
			system("cls");
			break;

		case 5:
			system("cls");
			masterList.editAbsence();
			putchar('\n');
			system("pause");
			system("cls");
			break;

		case 6:
			system("cls");
			masterList.generateAbsenceReports();
			putchar('\n');
			system("pause");
			system("cls");
			break;

		case 7:
			again = exit();
			break;

		}


	} while (again == 1);

	system("cls");
	cout << "The master list is still saved last time you updated on master.csv file!\n" << endl;
	cout << "See you next time!!!" << endl;
	system("pause");

}


/********************************************************************************************************************
* Function: exit()
* Description: This function successfully exits/terminates the program.
* Input parameters: Nothing
* Returns: again: determines wheter to exit/terminates the program or not.
*********************************************************************************************************************/
int Menu::exit(void)
{
	int again = 1;
	bool type_again = false;
	int yes_or_no = -1;

	do
	{
		system("cls");
		type_again = false;
		cout << "Are you sure you would like to exit the Class Attendance Tracker Program?\n" << endl;
		cout << "1. Yes       2. No" << endl;
		cout << "Please type 1 or 2: ";
		cin >> yes_or_no;

		if (yes_or_no == 1) again = 0;
		
		else if (yes_or_no != 1 && yes_or_no != 2)
		{
			cout << "Invalid input! Please type again!" << endl;
			system("pause");
			system("cls");
			type_again = true;

		}

	} while (type_again);

	system("cls");

	return again;
}
