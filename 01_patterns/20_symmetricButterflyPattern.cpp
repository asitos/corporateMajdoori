#include <iostream>
using namespace std;

class Solution {
public:
  void printPattern(int n) {
    char ch = '*';
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        cout << ch;
      }
      for (int j = 1; j <= (n - i) * 2; j++) {
        cout << " ";
      }
      for (int j = 1; j <= i; j++) {
        cout << ch;
      }
      cout << "\n";
    }
    for (int i = n - 1; i >= 1; i--) {
      for (int j = 1; j <= i; j++) {
        cout << ch;
      }
      for (int j = 1; j <= 2 * (n - i); j++) {
        cout << " ";
      }
      for (int j = 1; j <= i; j++) {
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
