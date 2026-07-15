#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool checkIfStringIsPalindrome(int i, string& str) {
    // brute force O(n) time and O(1) space
    // int n = str.size();
    //
    // for (int i = 0; i < n / 2; i++) {
    //   if (str[i] != str[n - 1 - i]) {
    //     return false;
    //   }
    // }
    //
    // return true;
    
    // optimal recursive approach
    if (i >= str.size() / 2) {
      return true;
    }

    if (str[i] != str[str.size() - i - 1]) {
      return false;
    }

    return checkIfStringIsPalindrome(i + 1, str);
  }
};

int main() {
  Solution obj;
  string str = "asitisa";
  
  if (obj.checkIfStringIsPalindrome(0, str)) {
    cout << "Palindrome";
  } else {
    cout << "Not Palindrome";
  }

  return 0;
}
