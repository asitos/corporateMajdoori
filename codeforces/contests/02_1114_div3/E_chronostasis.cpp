#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  multiset<long long> ms;
  for (int i = 0; i < n; i++) {
    long long val;
    cin >> val;
    ms.insert(val);
  }

  vector<long long> a(n);
  long long currSum = 0;

  for (int i = 0; i < n; i++) {
    long long needed = 1 - currSum;
    auto it = ms.lower_bound(needed);

    if (it == ms.end()) {
      cout << -1 << "\n";
      return;
    }

    long long chosen_b = *it;
    currSum += chosen_b;
    a[i] = currSum;
    ms.erase(it);
  }

  for (int i = 0; i < n; i++) {
    cout << a[i] << (i == n - 1 ? "" : " ");
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
