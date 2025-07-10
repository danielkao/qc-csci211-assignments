#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int vecSize;
    cout << "Enter a number of grading components: ";
    cin >> vecSize; // Initialize the variable vecSize to the user's input
    // Creating two vectors - one for grade, one for weight.
    vector<double> grade;
    vector<double> weight;
    double sum = 0; // Declare & initialize variable to use for later
    double finalGrade = 0; // Declare & initialize variable to use for later
    
    // Begin by getting the grades
    cout << "Enter the grades: ";
    for (int i = 0; i < vecSize; i++)
    {
        double temp; // Temporary variable to store the double
        cin >> temp; 
        grade.push_back(temp); // Add the value of the temporary variable to the "grade" vector
    }
    // After collecting the grades, collect the weights of each grade
    cout << "Enter the weights: ";
    for (int i = 0; i < vecSize; i++)
    {
        double temp; // Temporary variable to store the double
        cin >> temp;
        weight.push_back(temp); // Add the value of temporary variable to the "weights" vector
    }
    // Check the weights inputted add up to 1
    for (int i = 0; i < vecSize; i++)
    {
        sum += weight[i]; // Add up all the elements of the "weight" vector
    }
    if (sum != 1) // If they don't add up to 1, return and exit the program.
    {
        cout << "Invalid Input!";
        return -1;
    }
    // If the check above is passed, calculate the final grade
    for (int i = 0; i < vecSize; i++)
    {
        // Multiply each grade by its corresponding weight
        finalGrade += grade[i] * weight[i]; // Add the result to the final grade
    }
    
    cout << "Your overall grade is " << finalGrade; // Print out final grade
    // Exit program, returning 0 because it ran successfully
    return 0;
}