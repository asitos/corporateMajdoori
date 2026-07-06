#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  void printPattern(int n) {
    char c = '*';

    for (int i = (n - 1); i >= 0; i--) {
      for (int j = 0; j <= i; j++) {
        cout << c << " ";
      }
      cout << "\n";
    }
  }
  
};

int main () {
  Solution obj;
  int n = 5;
  
  obj.printPattern(n);  

  return 0;
}

