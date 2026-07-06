#include <iostream>
using namespace std;

class Solution {
public:
  void printPattern(int n) {
    char c = '*';

    for (int i = 0; i < n; i++) {

      for (int j = 0; j < i + 1; j++) {
        cout << c;
      }

      cout << "\n";
    }

    for (int i = n - 1; i > -1; i--) {

      for (int j = i; j > 0; j--) {
        cout << c;
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
