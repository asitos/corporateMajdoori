
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  void printPattern(int n) {
    // char c = '*';

    // my Solution
    for (int i = (n); i >= 0; i--) {
      for (int j = 1; j <= i; j++) {
        cout << j << " ";
      }
      cout << "\n";
    }
    
    //striver's Solution
    for (int i = 0; i <= (n - 1); i++) {
      for (int j = n; j >= (i + 1); j--) {
        cout << n - j + 1 << " ";
      }
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

