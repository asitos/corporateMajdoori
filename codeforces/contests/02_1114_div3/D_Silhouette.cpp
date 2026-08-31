#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<long long> b(n);
  map<long long, vector<int>> groups;

  for (int i = 0; i < n; i++) {
    cin >> b[i];
    groups[b[i]].push_back(i);
  }

  if (groups.find(0) == groups.end()) {
    cout << -1 << "\n";
    return;
  }

  vector<long long> a(n);
  long long prev_v = 0;

  auto it = groups.begin();
  while (it != groups.end()) {
    long long S_m_minus_1 = it->first;
    long long c_m = it->second.size();
    auto next_it = std::next(it);

    long long v_m;

    if (next_it == groups.end()) {
      v_m = prev_v + 1;
    } else {
      long long S_m = next_it->first;
      long long diff = S_m - S_m_minus_1;

      if (diff <= 0 || diff % c_m != 0) {
        cout << -1 << "\n";
        return;
      }

      v_m = diff / c_m;

      if (v_m <= prev_v) {
        cout << -1 << "\n";
        return;
      }
    }

    for (int idx : it->second) {
      a[idx] = v_m;
    }

    prev_v = v_m;
    it = next_it;
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
