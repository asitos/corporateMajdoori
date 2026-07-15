#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int sumOfFirstNNaturalNumbers(int n) {

    // brute force approach O(n) 
    //
    // while (curr <= n) {
    //   sum += curr;
    //   curr++;
    // }
    // return sum;
    //
     
    // using formula O(1)

    // return (n * (n + 1)) / 2;

    // recursive approach O(n)
    // base case
    if (n == 1) {
      return 1;
    }


    return n + sumOfFirstNNaturalNumbers(n - 1);

  }
};

int main() {
  Solution obj;
  int n = 5;

  cout << obj.sumOfFirstNNaturalNumbers(n);
  return 0;
}
