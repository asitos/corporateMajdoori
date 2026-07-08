#include <iostream>
using namespace std;

class Solution {
public:
  bool isPalindrome(int n) {
    // my brute force approach
    // int num = n;
    // int rev = 0, d;
    //
    // while (n > 0) {
    //   d = n % 10;
    //
    //   rev = rev * 10 + d;
    //   n /= 10;
    //
    // }
    //
    // return (num == rev);
    // better approach, using only half the digits of 32-bit int

    if (n < 0 || (n % 10 == 0 && n != 0)) {
      return false;
    }
    int halfRev = 0;

    while (n > halfRev) {
      halfRev = halfRev * 10 + (n % 10);
      n /= 10;
    }

    return (n == halfRev) || (n == halfRev / 10);
  }
};

int main() {
  Solution obj;
  int n = 45654;

  cout << obj.isPalindrome(n);
  return 0;
}
