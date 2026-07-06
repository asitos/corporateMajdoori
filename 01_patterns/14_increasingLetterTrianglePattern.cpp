#include <iostream>
using namespace std;

class Solution {
public:
  void printPattern(int n) {
    // my Solution
    for (int i = 0; i < n; i++) {
      for (char ch = 'A'; ch <= 'A' + i; ch++) {
        cout << ch << " ";
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
