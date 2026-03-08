#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Global variables set up for the program
const int NUM_TESTS = 5;
const int MAX_STUDENTS = 100;

int readStudentData(string names[], int scores[][NUM_TESTS]);
void calculateAverages(int count, int scores[][NUM_TESTS], double averages[]);

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

    // Outputs each student's name and average score
    for (int i = 0; i < studentCount; i++)
    {
        cout << names[i] << " average: " << averages[i] << endl;
    }

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