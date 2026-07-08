#include <iostream>
using namespace std;

class Solution {
public:
  int gcdOf(int n1, int n2) {
    // brute force approach
    // int gcd = 1;
    //
    // for (int i = 2; i < min(n1, n2); i++) {
    //   if (n1 % i == 0 && n2 % i == 0) {
    //     gcd = i;
    //   }
    // }
    //
    //
    //better approach
    //
  //   for (int i = min(n1, n2); i > 0; i--) {
  //     if (n1 % i == 0 && n2 % i == 0) {
  //       return i;
  //     }
  //
  //   }
  //   return 1;
  //
    //optimal approach
    while (n1 > 0 && n2 > 0) {
      if (n1 > n2) {
        n1 = n1 % n2;
      } else {
        n2 = n2 % n1;
      }
    }

    if (n1 == 0) {
      return n2;
    }

    return n1;
  }
};

int main() {
  Solution obj;
  int x = 20, y = 15;

  cout << obj.gcdOf(x, y);
  return 0;
}
