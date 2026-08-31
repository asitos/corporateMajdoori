#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long marenol(int n, const string &a, const string &b) {
    vector<int> ae, ao, be, bo;

    for (int i = 0; i < n; i++) {
      if (a[i] == '1') {
        if (i % 2 == 0)
          ae.push_back(i);
        else
          ao.push_back(i);
      }

      if (b[i] == '1') {
        if (i % 2 == 0)
          be.push_back(i);
        else
          bo.push_back(i);
      }
    }

    if (ae.size() != be.size() || ao.size() != bo.size()) {
      return -1;
    }

    long long res = 0;

    for (size_t i = 0; i < ae.size(); i++) {
      res += abs(ae[i] - be[i]) / 2;
    }

    for (size_t i = 0; i < ao.size(); i++) {
      res += abs(ao[i] - bo[i]) / 2;
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
    cin >> n;
    string a, b;
    cin >> a >> b;

    cout << obj.marenol(n, a, b) << "\n";
  }

  return 0;
}
