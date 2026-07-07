#include <iostream>
using namespace std;

class Solution {
public:
  void printPattern(int n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 || i == n -1 || j == 0 || j == n - 1) {
          cout << '*';
        } else {
          cout << " ";
        }
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

