#include <iostream>
#include <fstream>
using namespace std;
const int test_Max = 5; // Global constant for maximum number of tests
const int student_Max = 50; // Global constant for maximum number of students
// readGrades function reads student names and their test scores from a file
// Input parameters: names (array of student names), scores (2D array of test scores), numStudents (number of students read)
// Postcondition: names and scores arrays are populated with data from the file, numStudents is updated with the number of students read
void readGrades(string names[], int scores[][test_Max], int &numStudents)
{
    ifstream inFile("StudentGrades.txt");
    if (!inFile) {
        cerr << "Unable to open file grades.txt";
        exit(1); // terminate with error
    }
	while (inFile >> names[numStudents] && numStudents < student_Max)
        {
        for (int i = 0; i < test_Max; i++) 
        {
            inFile >> scores[numStudents][i];
        }
        numStudents++;
	}
    inFile.close();
}
// calculateAverages function calculates the average score for each student
// Input parameters: scores (2D array of test scores), averages (array to store average scores), numStudents (number of students)
// Postcondition: averages array is populated with the average score for each student
void calculateAverages(int scores[][test_Max], double averages[], int numStudents)
{
    for (int i = 0; i < numStudents; i++)
    {
        double sum = 0;
        for (int j = 0; j < test_Max; j++)
        {
            sum += scores[i][j];
        }
        averages[i] = sum / test_Max;
    }
}
// getLetter function determines the letter grade based on the average score
// Input parameter: average (the average score for a student)
// Return value: the letter grade corresponding to the average score
char getLetter(double average)
{
    if (average >= 90)
        return 'A';
    else if (average >= 80)
        return 'B';
    else if (average >= 70)
        return 'C';
    else if (average >= 60)
        return 'D';
    else
        return 'F';
}
// displayGrades function displays the student names, their average scores, and corresponding letter grades
// Input parameters: names (array of student names), scores (2D array of test scores), averages (array of average scores), numStudents (number of students)
// Postcondition: the student names, average scores, and letter grades are displayed to the console
void displayGrades(string names[], int scores[][test_Max], double averages[], int numStudents)
{
    cout << "Name:      Average:   Letter Grade:" << endl;
    for (int i = 0; i < numStudents; i++)
    {
        cout << names[i] << "      ";
        cout << averages[i] << "      ";
        cout << getLetter(averages[i]) << endl;
    }
}
int main()
{
    string names[student_Max];
	int grades[student_Max][test_Max];
	double averages[student_Max];
	int numStudents = 0;

    readGrades(names, grades, numStudents);
    calculateAverages(grades, averages, numStudents);
    displayGrades(names, grades, averages, numStudents);
	return 0;
}
