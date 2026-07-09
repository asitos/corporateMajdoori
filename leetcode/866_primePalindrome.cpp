#include <iostream>
using namespace std;

class Solution {
public:
  int primePalindrome(int n) {
    
  }

private:
  bool isPrime(int n) {

    if (n <= 1) {
      return false;
    }
    
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        return false;
      }
    }
    
    return true;
  }

  bool isPalindrome(int n) {

    //edge case
    if (n < 0 || (n % 10 == 0 && n != 0) {
      return false;
    }
    int halfRev = 0;
    
    while (n > halfRev) {
      halfRev = halfRev * 10 + (n % 10);
      n /= 10;
    } 

    return (n == halfRev || n == halfRev / 10);

  }
};

int main() {
  Solution obj;
  int n = 5;
  cout << obj.primePalindrome(n);

  return 0;
}
