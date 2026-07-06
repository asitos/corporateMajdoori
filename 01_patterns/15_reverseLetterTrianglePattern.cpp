
#include <iostream>
using namespace std;

class Solution {
public:
  void printPattern(int n) {
    // my Solution
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        char ch = 'A' + i;
        cout << ch;
      }
      cout << "\n";
    }
  }
};

int main() {
  Solution obj;
  int n = 5;

  obj.printPattern(n);
  return 0;
}
