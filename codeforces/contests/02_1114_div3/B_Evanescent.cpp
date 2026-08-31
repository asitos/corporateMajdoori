#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int evanescent(int n, string &s) {

    int orig = 1;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] != s[i + 1]) {
        orig++;
      }
    }

    // schar (2nd index <= i <= n-1)
    // find size of res after deleting schar from s

    int res = n;

    for (int i = 1; i < n - 1; i++) {
      int removed = (s[i - 1] != s[i]) + (s[i] != s[i + 1]);

      int added = (s[i - 1] != s[i + 1]);
      int newf = orig - removed + added;
      res = min(res, newf);
    }

    return res;
  }
};

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solution obj;
  int t;
  cin >> t;

  while (t--) {
    int n;
    string s;
    cin >> n >> s;

    cout << obj.evanescent(n, s) << "\n";
  }

  return 0;
}
