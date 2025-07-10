#include <iostream>
using namespace std;

// Variable to store the number of solutions that are found
int solutions = 0;
// 2D int array to represent the men's preferences, with 0 being the
// highest and 2 being the lowest.
int mp[3][3] = {
                {0, 2, 1},
                {0, 2, 1},
                {1, 2, 0}
                };
// 2D int array to represent the women's preferences, with 0 being the
// highest and 2 being the lowest.            
int wp[3][3] = {
                {2, 1, 0},
                {0, 1, 2},
                {2, 0, 1}
                };
    
/*
* Method to check if the match will cause instability
*/
bool ok(int q[], int c)
{
    for (int i = 0; i < c; i++)
    {
        if (q[i] == q[c])
        // If the new woman has already been assigned:
        {
            return false;
        }
        if ((mp[i][q[c]] < mp[i][q[i]]) && (wp[q[c]][i] < wp[q[c]][c]))
        /* If the current man prefers the new woman to his partner
        and if the new woman prefers the current man to her partner: */
        {
            return false;
        }
        if ((mp[c][q[i]] < mp[c][q[c]]) && (wp[q[i]][c] < wp[q[i]][i]))
        /* If the new man prefers the curent woman to his partner
        and if the current woman prefers the new man to her partner: */
        {
            return false;
        }
    }
    // If there are no instabilities, return true.
    return true;
}

/*
 * Method to print the solutions.
 */
void print(int q[])
{
    solutions++; // Increase the number of solutions by 1.
    cout << "Solution #" << solutions << ":\n";
    cout << "Man\tWoman\n";
    for (int i = 0; i < 3; i++)
    {
        cout << i << "\t" << q[i] << endl;
    }
    cout << endl;
}
int main()
{
    int q[3] = {}; // Declare and initialize the array. 
    int c = 0; // Current man = 1st man.
    q[c] = 0; // Current man is assigned the 1st woman.
    
    // Main loop
    while (c >= 0)
    {
        c++; // Move to the next man
        if (c == 3) // If each man has been assigned a woman:
        {
           print(q); // Print the working solution
           c--; // Backtrack
        }
        else
        {
            q[c] = -1; // Reset the woman for the current man
        }
        
        while (c >= 0)
        {
            q[c]++; // Move to the next woman
            
            if (q[c] == 3) 
            // If all the women have been tried for the current man and there is no match:
            {
                c--; // Backtrack
            }
            else if (ok(q, c)) // If all women have not been tried yet, match current man with woman and check.
            {
                break; 
            }
        }
    }
    
    return 0;
}