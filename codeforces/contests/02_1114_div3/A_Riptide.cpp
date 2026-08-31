#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int riptide(int a, int b, int c) {
    vector<int> tok = {a, b, c};

    int rounds = 0;
    while (true) {
      sort(tok.begin(), tok.end());

      if (tok[0] == tok[1] || tok[1] == tok[2] || tok[0] == tok[2]) {
        return rounds;
      }

      tok[2] -= 1;
      tok[0] += 1;
      rounds++;
    }
  }
};

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solution obj;
  int t;
  cin >> t;

  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;

    cout << obj.riptide(a, b, c) << "\n";
  }

  return 0;
}
