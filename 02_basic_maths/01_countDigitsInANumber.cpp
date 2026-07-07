// Problem Statement: Given an integer N, return the number of digits in N. 
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
  // brute force approach, takes O(log10N) time
  // int totalDigitsIn(int n) {
  //   int count = 0;
  //   while (n > 0) {
  //     count++;
  //     n /= 10;
  //   }
  //
  //   return count;
  // }

  // optimal approach, takes O(1) time due to constant arithmetic operations
  int totalDigitsIn(int n) {
    int count = (int)(log10(n)+1);

    return count;
  }
};

int main() {
  Solution obj;
  int n = 777434;

  cout << obj.totalDigitsIn(n);

  return 0;
}
