#include <iostream>
using namespace std;

class Solution {
public:
  void printPattern(int n) {
    // my Solution
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        cout << j;
      }
      for (int j = 0; j < (n - i) * 2; j++) {
        cout << " ";
      }
      for (int j = i; j >= 1; j--) {
        cout << j;
      }
      cout << "\n";
    }
    //strivers Solution
    //// Initial number of spaces in the first row
    int spaces = 2 * (n - 1);
    
    // Outer loop for the number of rows
    for (int i = 1; i <= n; i++) {
        
        // Inner loop to print numbers in increasing order
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        
        // Inner loop to print spaces in the middle
        for (int j = 1; j <= spaces; j++) {
            cout << " ";
        }
        
        // Inner loop to print numbers in decreasing order
        for (int j = i; j >= 1; j--) {
            cout << j;
        }
        
        // Move to the next line after printing the row
        cout << endl;
        
        // Decrease spaces by 2 after each row
        spaces -= 2;
    }
  }
};

int main() {
  Solution obj;
  int n = 6;

  obj.printPattern(n);
  return 0;
}
