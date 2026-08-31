#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  bool marenol(int n, const string &a, const string &b) {
    int a_even_ones = 0, a_odd_ones = 0;
    int b_even_ones = 0, b_odd_ones = 0;

    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        if (a[i] == '1')
          a_even_ones++;
        if (b[i] == '1')
          b_even_ones++;
      } else {
        if (a[i] == '1')
          a_odd_ones++;
        if (b[i] == '1')
          b_odd_ones++;
      }
    }

    return (a_even_ones == b_even_ones) && (a_odd_ones == b_odd_ones);
  }
};

int main() {
  // Fast I/O
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

    if (obj.marenol(n, a, b)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
