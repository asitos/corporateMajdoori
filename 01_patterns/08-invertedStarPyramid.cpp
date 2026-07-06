#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  void printPattern(int n) {
    char c = '*';

    // my Solution
    for (int i = n - 1; i >= 0; i--) {

      for (int j = 0; j < n - i - 1; j++) {
        cout << " ";
      }

      for (int j = 0; j < (i * 2) + 1; j++) {
        cout << c;
      }

      // for (int j = 0; j < n - i - 1; j++) {
        // cout << " ";
      // }
      // 
      
      cout << "\n";
    }
    //strivers Solution
            for (int i = 0; i < n; i++) {
            
            // Print leading spaces (increases with row number)
            for (int j = 0; j < i; j++) {
                cout << " ";
            }

            // Print stars (decreases with row number)
            // Formula: total stars = 2*n - (2*i + 1)
            for (int j = 0; j < 2 * n - (2 * i + 1); j++) {
                cout << "*";
            }

            // Print trailing spaces (same as leading spaces)
            for (int j = 0; j < i; j++) {
                cout << " ";
            }

            // Move to next row
            cout << endl;
        }
  }
  
};

int main () {
  Solution obj;
  int n = 5;
  
  obj.printPattern(n);  

  return 0;
}

