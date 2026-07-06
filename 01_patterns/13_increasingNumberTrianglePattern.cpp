
#include <iostream>
using namespace std;

class Solution {
public:
  void printPattern(int n) {
    // my Solution
    int count = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        cout << count << " ";
        count++;
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
