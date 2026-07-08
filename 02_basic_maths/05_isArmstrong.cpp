#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
  bool isArmstrong(int n) {
    if (n < 0) {
      return false;
    }

    int num = n;
    int arm = 0;
    int k = (int)(log10(n) + 1);

    while (n != 0) {
      int d = n % 10;
      arm += round(pow(d, k));
      n /= 10;
    }

    return (arm == num);
  }
};

int main() {
  Solution obj;
  int n = 153;
  cout << obj.isArmstrong(n);

  return 0;
}
