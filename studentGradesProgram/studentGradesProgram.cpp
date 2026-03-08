#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Global variables set up for the program
const int NUM_TESTS = 5;
const int MAX_STUDENTS = 100;

int readStudentData(string names[], int scores[][NUM_TESTS]);

int main()
{
    // Variables for student info
    string names[MAX_STUDENTS];
    int scores[MAX_STUDENTS][NUM_TESTS];
    int studentCount = 0;

	// Gets an int value off the function that reads the student data from the file and stores it in the arrays
    studentCount = readStudentData(names, scores);

	// Outputs the number of students read from the file
    cout << "Students read: " << studentCount << endl;

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