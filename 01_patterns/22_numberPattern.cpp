#include <iostream>
using namespace std;

class Solution {
public:
  void printPattern(int n) {
    int size = 2 * n - 1;
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        int top = i;
        int bottom = (size - 1) - i;
        int left = j;
        int right = (size - 1) - j;

        int minDist = min(min(top, bottom), min (left, right));

        cout << n - minDist << " ";
      }
      cout << "\n";
    }
  }
};

int main() {
  Solution obj;
  int n = 4;

  obj.printPattern(n);
  return 0;
}

