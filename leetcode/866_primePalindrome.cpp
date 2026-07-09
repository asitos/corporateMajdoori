#include <iostream>
using namespace std;

class Solution {
public:
  int primePalindrome(int n) {
    int i = n;

    while(true) {
      // 11-divisibility bypass
      // skip 4-digit, 6-digit, and 8-digit nos.
      // since they're all divisible by 11 if they're a palindrome of even length

      if (1000 <= i && i < 10000) i = 10000;
      if (100000 <= i && i < 1000000) i = 1000000;
      if (100000 <= i && i < 100000000) i = 100000000;
      if (isPalindrome(i) && isPrime(i)) {
        return i;
      }
      i++;
    }

    return n;
  }

private:
  bool isPrime(int n) {

    if (n <= 1) {
      return false;
    }
    if (n % 2 == 0) return n == 2;
    
    for (int i = 3; i * i <= n; i += 2) {
      if (n % i == 0) {
        return false;
      }
    }
    
    return true;
  }

  bool isPalindrome(int n) {

    //edge case
    if (n < 0 || (n % 10 == 0 && n != 0)) {
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
  int n = 13;
  cout << obj.primePalindrome(n);

  return 0;
}
