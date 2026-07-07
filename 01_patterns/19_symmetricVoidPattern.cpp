#include <iostream>
using namespace std;

class Solution {
public:
  void printPattern(int n) {
    char ch = '*';
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n - i; j++) {
        cout << ch;
      }
      for (int j = 0; j < (2 * i); j++) {
        cout << " ";
      }
      for (int j = 0; j < n - i; j++) {
        cout << ch;
      }
      cout << "\n";
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        cout << ch;
      }
      for (int j = 0; j < 2 * (n - i - 1); j++) {
        cout << " ";
      }
      for (int j = 0; j <= i; j++) {
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
