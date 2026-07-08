#include <iostream>
// #include <cmath>
using namespace std;

class Solution {
public:
  //my brute force approach
  // int reverseOf(int n) {
  //   int result = 0, d;
  //   int count = (int)(log10(n)+1);
  //
  //   while (count > 0) {
  //     d = n % 10;
  //     result += pow(10, count - 1) * d;
  //     n = n / 10;
  //     count--;
  //   }
  //
  //   return result;
  // }
  // better approach with overflow firewall
  int reverseOf(int n) {
    int res = 0;

    while (n != 0) {
      int d = n % 10;
      if (res > INT_MAX / 10 || (res == INT_MAX / 10 && d > 7)) {
        return 0;
      }
      if (res < INT_MIN / 10 || (res == INT_MIN / 10 && d < -8)) {
        return 0;
      }
      res = res * 10 + d;
      n = n / 10;
    }
    
    return res;
  }
};

int main() {
  Solution obj;
  int n = -12345;

  cout << obj.reverseOf(n);
  return 0;
}
