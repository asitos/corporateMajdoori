#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
// my stupid ass redundant solution
//       int sumEven = n * (n + 1);
//       int sumOdd = n * n;
//
//       return gcdOf(sumEven, sumOdd);
//     }
//
// private:
//     int gcdOf(int n1, int n2) {
//       while (n1 > 0 && n2 > 0) {
//
//         if (n1 > n2) {
//           n1 = n1 % n2;
//         } else {
//           n2 = n2 % n1;
//         }
//       }
//
//       if (n1 == 0) {
//         return n2;
//       }
//
//       return n1;
//
    // after doing some math on paper, gcd(n^2,n.(n + 1) = n)
    // simply return n
    return n;
      
    }
};

int main() {
  Solution obj;
  int n = 5;
  cout << obj.gcdOfOddEvenSums(n);
  return 0;
}
