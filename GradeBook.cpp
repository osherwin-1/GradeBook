#include <iostream>
#include <fstream>
using namespace std;
const int test_Max = 5;
const int student_Max = 50;
void readGrades(string names[], int scores[][test_Max], int &numStudents)
{
    ifstream inFile("StudentGrades.txt");
    if (!inFile) {
        cerr << "Unable to open file grades.txt";
        exit(1); // terminate with error
    }
    int grade;
    while (inFile >> grade) {
        cout << grade << endl;
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
void displayGrades(string names[], int scores[][test_Max], double averages[], int numStudents)
{
    cout << "Name:     ";
    for (int i = 0; i < test_Max; i++)
    {
        cout << "Average:      Letter Grade:" << endl;
    }
    for (int i = 0; i < numStudents; i++)
    {
        cout << names[i] << "\t";
        for (int j = 0; j < test_Max; j++)
            cout << scores[i][j] << "\t";
        cout << averages[i] << "\t" << getLetter(averages[i]) << endl;
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
