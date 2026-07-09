#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> printAllDivisorsOfAGivenNumber(int n) {
    vector<int> res;
    // edge case 
    if (n <= 0) {
      return res;
    }

    //brue force approach
    // for (int i = 1; i <= n; i++) {
    //   if (n % i == 0) {
    //     res.push_back(i);
    //   }
    // }
    //
    //optimal approach
    for (int i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        res.push_back(i);

        if (i != n / i) {
          res.push_back(n / i);
        }
      }
    }
    return res;
  }
};

int main() {
  Solution obj;
  int n = 36;
  vector<int> res = obj.printAllDivisorsOfAGivenNumber(n);
  for (int j : res) {
    cout << j << " ";
  }

  return 0;
}
