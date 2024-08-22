#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int SIZE = 20;
const int MARK_UPDATE_MAX = 50;
const int MARK_UPDATE_MIN = 0;

struct Student{
	string id;
	double coursework;
	double finalExam;
	double totalMark;
	
};

int validateInput(int lowerLimit, int upperLimit)
{
    int input;
    cin >> input;
    
    while(input < lowerLimit || input > upperLimit || cin.fail())
	{
        if (cin.fail())
		{
            cin.clear();
            string dummy;
            cin >> dummy;
            cout << "ERROR! Invalid option detected." << endl;
            cout << "Please enter a number." << endl;
        }
		else if (input < lowerLimit || input > upperLimit)
		{
            cin.clear();
            cout << "ERROR! Your choice is not in range." << endl;
            cout << "Please enter a number between " << lowerLimit << " and " << upperLimit << endl;
        }
        cin >> input;
    }
    return input;
}

void printWelcomeMessage()
{
    cout << "+-------------------------------------------------+\n";
    cout << "|      WELCOME TO THE STUDENT GRADES PROGRAM      |\n";
    cout << "+-------------------------------------------------+\n";
}

void endProgram(bool& continueExecuting)
{
    continueExecuting = false;

    cout << endl;
    cout << "+-------------------------------------+\n";
    cout << "|  Thank you for using this program!  |\n";
    cout << "+-------------------------------------+\n";
}

void displayMenu()
{
	cout << "Menu:" << endl;
	cout << "1. Print Entire List with Grades" << endl;
	cout << "2. Update Student's Marks" << endl;
	cout << "3. Print Average marks" << endl;
	cout << "4. Print Pass Rate" << endl;
	cout << "5. Print the Highest Scorer's Details" << endl;
	cout << "6. Exit Program" << endl;
	cout << "\nEnter the number corresponding to your choice" << endl;
}

void programStartQuit(bool& continueExecuting)
{
    string userDecision;
    cout << "Enter S to start or Q to quit" << endl;
    cin >> userDecision;
    
    while(userDecision != "S" && userDecision != "s" && userDecision != "Q" && userDecision != "q") {
        cin.clear();
        cout << "ERROR! Invalid input detected." << endl;
        cout << "Please enter either \"S\" or \"Q\" only." << endl;
        cin >> userDecision;
    }
    
    if (userDecision == "S" || userDecision == "s")
	{
		continueExecuting = true;
	}
	else if (userDecision == "Q" || userDecision == "q")
	{
		continueExecuting = false;
	}
}

void fillArray(string fileName, int& rows, Student students[])
{
	string readHeader;
	ifstream readFile(fileName.c_str());
	
	if (!readFile)
	{
		cout << "ERROR! File could not be found." << endl;
		exit(1); // Exiting as the file is not found
	}
	else 
	{
		getline(readFile, readHeader);
		
		while (readFile >> students[rows].id >> students[rows].coursework >> students[rows].finalExam)
		{
			rows++;
		}
	}
}

string determineGrade(double totalMark)
{
	if (totalMark >= 85)
	{
		return "A+";
	}
	else if (totalMark >= 78)
	{
		return "A";
	}
	else if (totalMark >= 71)
	{
		return "B+";
	}
	else if (totalMark >= 64)
	{
		return "B";
	}
	else if (totalMark >= 57)
	{
		return "C+";
	}
	else if (totalMark >= 50)
	{
		return "C";
	}
	else if (totalMark >= 40)
	{
		return "D";
	}
	else 
	{
		return "E";
	}
}

void printEntireList(Student students[], int size)
{
	cout << "\nThe Entire List of Students with Grades:" << endl;
	cout << "\n" << left << setw(20) << "ID" << setw(20) << "Coursework" << setw(20) << "Final Exam" << setw(20) << "Grade" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	
	for (int i = 0; i < size; i++)
	{
		students[i].totalMark = students[i].coursework + students[i].finalExam;
		string studentGrade = determineGrade(students[i].totalMark);
		
		cout << left << setw(20) << students[i].id << setw(20) << students[i].coursework << setw(20) << students[i].finalExam << setw(20) << setw(20) << studentGrade << endl;
		cout << "-----------------------------------------------------------------" << endl;
	}
}

int UpdateMark_Validation(int MARK_UPDATE_MAX, int MARK_UPDATE_MIN){
	int updateAmount;
    cin >> updateAmount;
    
    while(updateAmount < MARK_UPDATE_MIN || updateAmount > MARK_UPDATE_MAX || cin.fail())
	{
        if (cin.fail())
		{
            cin.clear();
            string dummy;
            cin >> dummy;
            cout << "ERROR! Invalid option detected." << endl;
            cout << "Please enter a number." << endl;
        }
		else if (updateAmount < MARK_UPDATE_MIN || updateAmount > MARK_UPDATE_MAX)
		{
            cin.clear();
            cout << "ERROR! Your choice is not in range." << endl;
            cout << "Please enter a number between " << MARK_UPDATE_MIN << " and " << MARK_UPDATE_MAX << endl;
        }
        cin >> updateAmount;
    }
    return updateAmount;
}

void updateMark(Student students[], int size)
{
	string searchId;
	bool found = false;
	
	cout << "Please enter the ID number you would like to search for. Example: S00005" << endl;
	cin >> searchId;
	while(cin.fail())
	{
		cin.clear();
		string dummy;
		cin >> dummy;
		cout << "ERROR! Invalid Input Detected." << endl;
		cout << "Please enter letter \"S\" in uppercase followed by numbers only." << endl;
		cin >> searchId;
	}
	
	for (int i = 0; i < size; i++)
	{
		if (students[i].id == searchId)
		{
			found = true;
			const int MIN_CHOICE = 1;
			const int MAX_CHOICE = 3;

			cout << "Which Mark Would You Like To Update?" << endl;
			cout << "1. Coursework Only" << endl;
			cout << "2. Final Exam Only" << endl;
			cout << "3. Course and Final Exam" << endl;		
			int Update_Choice;
			cin >> Update_Choice;
			while(Update_Choice < MIN_CHOICE || Update_Choice > MAX_CHOICE || cin.fail())
			{
				if (cin.fail())
				{
					cin.clear();
					string dummy;
					cin >> dummy;
					cout << "ERROR! Invalid option detected." << endl;
					cout << "Please enter a number." << endl;
				}
				else if (Update_Choice < MIN_CHOICE || Update_Choice > MAX_CHOICE)
				{
					cin.clear();
					cout << "ERROR! Your choice is not in range." << endl;
					cout << "Please enter a number between " << MIN_CHOICE << " and " << MAX_CHOICE << endl;
				}
				cin >> Update_Choice;
			}
			switch(Update_Choice){
				case 1: cout << "Enter the new coursework mark: ";
								students[i].coursework = UpdateMark_Validation(MARK_UPDATE_MAX, MARK_UPDATE_MIN);
								break;
				case 2: cout << "Enter the new final exam mark: ";
								students[i].finalExam = UpdateMark_Validation(MARK_UPDATE_MAX, MARK_UPDATE_MIN);
								break;
				case 3: cout << "Enter the new coursework mark: ";
								students[i].coursework = UpdateMark_Validation(MARK_UPDATE_MAX, MARK_UPDATE_MIN);
						cout << "Enter the new final exam mark: ";
								students[i].finalExam = UpdateMark_Validation(MARK_UPDATE_MAX, MARK_UPDATE_MIN);
								break;
			}
			students[i].totalMark = students[i].coursework + students[i].finalExam;
			string studentGrade = determineGrade(students[i].totalMark);
			
			cout << "\nMarks Updated Successfully!" << endl;
			cout << "\n" << left << setw(20) << "ID" << setw(20) << "Coursework" << setw(20) << "Final Exam" << setw(20) << "Total" << setw(20) << "Grade" << endl;
			cout << left << setw(20) << students[i].id << setw(20) << students[i].coursework << setw(20) << students[i].finalExam << setw(20) << students[i].totalMark << setw(20) << studentGrade << endl;
		}
	}
	
	if (!found)
	{
		cout << "\nNo student was found with the ID# " << searchId << endl;
	}
}

void printAverageMarks(Student students[], int size)
{
    double totalMarks = 0.0;

    for (int i = 0; i < size; i++)
    {
        students[i].totalMark = students[i].coursework + students[i].finalExam;
        totalMarks += students[i].totalMark;
    }

    double averageMarks = totalMarks / size;

    cout << "\nThe average mark for the class is: " << fixed << setprecision(2) << averageMarks << endl;
}

void printPassRate(Student students[], int size)
{
	double passRate = 0;
	double passedCounter = 0;
	
	for (int i = 0; i < size; i++)
	{
		students[i].totalMark = students[i].coursework + students[i].finalExam;
		
		if(students[i].totalMark >= 50)
		{
			passedCounter++;
		}
	}
	
	passRate = (passedCounter/size)*100;
	
	cout << "\nThe pass rate of the class is " << passRate << "%" << endl;	
}

void printHighestScorersDetails(Student students[], int size)
{
	int highestScorerIndex = 0;
	int highestScorerCounter = 0;
	
	for (int i = 0; i < size; i++)
	{

		students[i].totalMark = students[i].coursework + students[i].finalExam;
		
		if(students[i].totalMark > students[highestScorerIndex].totalMark)
		{
			highestScorerIndex = i;
		}
	}
	highestScorerCounter++;
	
	string studentGrade = determineGrade(students[highestScorerIndex].totalMark);
	
	cout << "\nHighest Scorer's Full Details:" << endl;
	cout << "\n" << left << setw(20) << "ID" << setw(20) << "Coursework" << setw(20) << "Final Exam" << setw(20) << "Total" << setw(20) << "Grade" << endl;

	for(int i = 0; i < highestScorerCounter; i++){
	cout << left << setw(20) << students[highestScorerIndex].id << setw(20) << students[highestScorerIndex].coursework << setw(20) << students[highestScorerIndex].finalExam << setw(20) << students[highestScorerIndex].totalMark << setw(20) << studentGrade << endl;
	}
}

int main()
{
	const int CHOICE1 = 1;
	const int CHOICE2 = 2;
	const int CHOICE3 = 3;
	const int CHOICE4 = 4;
	const int CHOICE5 = 5;
	const int CHOICE6 = 6;
	
	Student students[SIZE];
	int size = 0;
	int rows = 0;
	int choice;
	bool continueExecuting = true;
	
	ifstream readFile("studentData.txt");
	
	cout << fixed << setprecision(2) << endl;
	
	printWelcomeMessage();
	
	programStartQuit(continueExecuting);

	fillArray("studentData.txt", rows, students);
	
	while (continueExecuting)
	{
		rows = 20;
				
		cout << endl;
		displayMenu();
		choice = validateInput(CHOICE1, CHOICE6);
		
		if (choice == CHOICE1)
		{
			printEntireList(students, rows);
		}
		else if (choice == CHOICE2)
		{
			updateMark(students, rows);
		}
		else if (choice == CHOICE3)
		{
		    printAverageMarks(students, rows);
		}
		else if (choice == CHOICE4)
		{
			printPassRate(students, rows);
		}
		else if (choice == CHOICE5)
		{
			printHighestScorersDetails(students, rows);
		}
		else
		{
			endProgram(continueExecuting);
		}
	}
	return 0;
}