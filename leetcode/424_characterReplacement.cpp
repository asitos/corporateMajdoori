#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int characterReplacement(string s, int k) {
    int res = 0;
    int L = 0;

    vector<int> count(26, 0);
    int maxFreqCharCount = 0;

    for (int R = 0; R < s.size(); R++) {
      count[s[R] - 'A']++;

      maxFreqCharCount = max(maxFreqCharCount, count[s[R] - 'A']);

      while (((R - L + 1) - maxFreqCharCount > k)) {
        count[s[L] - 'A']--;
        L++;
      }

      res = max(res, R - L + 1);
    }
     
    return res;
  }
};

int main() {
  Solution obj;
  string s = "AABABBA";
  int k = 1;
  cout << obj.characterReplacement(s, k) << endl;

  return 0;
}
