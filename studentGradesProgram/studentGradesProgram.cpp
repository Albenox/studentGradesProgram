#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Global variables set up for the program
const int NUM_TESTS = 5;
const int MAX_STUDENTS = 100;

int readStudentData(string names[], int scores[][NUM_TESTS]);
void calculateAverages(int count, int scores[][NUM_TESTS], double averages[]);
char getLetterGrade(double average);
void printReport(int count, string names[], double averages[]);

int main()
{
    // Variables for student info
    string names[MAX_STUDENTS];
    int scores[MAX_STUDENTS][NUM_TESTS];
    double averages[MAX_STUDENTS];
    int studentCount = 0;

    // Gets an int value off the function that reads the student data from the file and stores it in the arrays
    studentCount = readStudentData(names, scores);

    // Calls the function that calculates each student's average score
    calculateAverages(studentCount, scores, averages);

    // Calls the function that prints the formatted grade report
    printReport(studentCount, names, averages);

    // Return to ensure program ends properly
    return 0;
}

// Function to read student data from a file and store it in arrays
int readStudentData(string names[], int scores[][NUM_TESTS])
{
    // Open the file for reading
    ifstream infile("StudentGrades.txt");
    int count = 0;

    // Check if the file opened successfully
    if (!infile)
    {
        cout << "Error opening file." << endl;
        return 0;
    }

    // Loops through the file, reading student names and their corresponding test scores until the end of the file is reached
    while (infile >> names[count])
    {
        for (int i = 0; i < NUM_TESTS; i++)
        {
            infile >> scores[count][i];
        }

        count++;
    }

    // Closes and returns file and the number of students read
    infile.close();
    return count;
}

// Function to calculate the average test score for each student
void calculateAverages(int count, int scores[][NUM_TESTS], double averages[])
{
    // Loops through each student
    for (int i = 0; i < count; i++)
    {
        int sum = 0;

        // Adds all test scores for one student together
        for (int j = 0; j < NUM_TESTS; j++)
        {
            sum += scores[i][j];
        }

        // Divides the total by the number of tests to get the average
        averages[i] = (double)sum / NUM_TESTS;
    }
}

// Function to assign a letter grade based on the average score
char getLetterGrade(double average)
{
    // Uses a standard grading scale
    if (average >= 90)
    {
        return 'A';
    }
    else if (average >= 80)
    {
        return 'B';
    }
    else if (average >= 70)
    {
        return 'C';
    }
    else if (average >= 60)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }
}

// Function to output the final formatted grade report
void printReport(int count, string names[], double averages[])
{
    // Outputs the column headings
    cout << left << setw(15) << "Student"
        << setw(15) << "Average"
        << setw(10) << "Grade" << endl;

    // Outputs a divider line under the headings
    cout << "-------------------------------------" << endl;

    // Loops through each student and outputs their formatted information
    for (int i = 0; i < count; i++)
    {
        cout << left << setw(15) << names[i]
            << setw(15) << fixed << setprecision(2) << averages[i]
            << setw(10) << getLetterGrade(averages[i]) << endl;
    }
}