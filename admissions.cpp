#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> students;
    int userInput;
    string studentName;
    cout << "This program is for admitting students to Queens College.";
    cout << endl;
    while (userInput != 4)
    {
        cout << "1. insertion 2. deletion 3. print 4. exit" << endl;
        cin >> userInput;
        if (userInput == 1) {
            cout << "Enter the name of the accepted student: " << endl;
            cin >> studentName;
            students.push_back(studentName);
            cout << studentName << " has been added to the accepted list." << endl;
        }
        else if (userInput == 2)
        {
            cout << "Removed the last name on the list." << endl;
            students.pop_back();
        }
        else if (userInput == 3)
        {
            for (int i = 0; i < students.size(); i++)
            {
                cout << students[i] + " ";
            }
            cout << endl;
        }
        else if (userInput == 4)
        {
            cout << "Exiting the program.";
        }
        else {
            cout << "Invalid input, try again." << endl;
        }
    }
    return 0;
}