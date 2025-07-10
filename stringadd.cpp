#include <iostream>
#include <string>
using namespace std;
/*
 * Method to add 2 strings that have lengths of less than 100.
 */
string add(string a, string b)
{
    if (a.length() > 100|| b.length() > 100)
    {
        return "Numbers are too big. Try again with smaller numbers (less than 100 digits).";
    }
    int lenA = a.length();
    int lenB = b.length();
    string result = "";
    int carry = 0;
    int temp;
    while (lenA > 0 || lenB > 0)
    {
      int digitA = lenA > 0 ? a[lenA - 1]- '0' : 0;
      int digitB = lenB > 0 ? b[lenB - 1] - '0' : 0;
      if (carry == 1)
      {
          temp = carry + digitA + digitB;
          carry = 0;
          if (temp > 9)
          {
              temp = temp % 10;
              carry = 1;
          }
      }
      else
      {
          temp = digitA + digitB;
          if (temp > 9)
          {
              temp = temp % 10;
              carry = 1;
          }
      }
      result.insert(0, to_string(temp));
      lenA--;
      lenB--;
    }
    return result;
    
}
int main()
{
    char num1[100];
    char num2[100];
    
    cin>>num1>>num2;
    cout<<add(num1, num2)<<endl;

    return 0;
}