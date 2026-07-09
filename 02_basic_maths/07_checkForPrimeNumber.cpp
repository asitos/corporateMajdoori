#include <iostream>
using namespace std;

class Solution {
public:
  bool checkForPrimeNumber(int n) {
    //edge case
    if (n <= 1) {
      return false;
    }

    for (int i = 2; i * i <= n / 2; i++) {
      if (n % i == 0) {
        return false;
      }
    }

    return true;
  }
};

int main() {
  Solution obj;
  int n = 10;
  cout << obj.checkForPrimeNumber(n);

  return 0;
}
