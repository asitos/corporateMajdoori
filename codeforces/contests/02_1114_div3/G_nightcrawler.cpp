#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<long long> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  vector<vector<int>> adj(n + 1);
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    adj[p].push_back(i);
  }

  vector<priority_queue<long long, vector<long long>, greater<long long>>> pq(
      n + 1);
  vector<long long> dropped;

  for (int u = n; u >= 1; u--) {
    bool is_leaf = adj[u].empty();

    if (is_leaf) {
      pq[u].push(a[u]);
      continue;
    }

    int big_child = -1;
    for (int v : adj[u]) {
      if (big_child == -1 || pq[v].size() > pq[big_child].size()) {
        big_child = v;
      }
    }

    pq[u] = std::move(pq[big_child]);

    for (int v : adj[u]) {
      if (v != big_child) {
        while (!pq[v].empty()) {
          pq[u].push(pq[v].top());
          pq[v].pop();
        }
      }
    }

    pq[u].push(a[u]);

    if (!is_leaf) {
      dropped.push_back(pq[u].top());
      pq[u].pop();
    }
  }

  int L = pq[1].size();
  long long base_score = 0;
  while (!pq[1].empty()) {
    base_score += pq[1].top();
    pq[1].pop();
  }

  sort(dropped.rbegin(), dropped.rend());

  vector<long long> ans(n + 1, -1);
  long long current_score = base_score;
  ans[L] = current_score;

  for (size_t i = 0; i < dropped.size(); i++) {
    current_score += dropped[i];
    ans[L + 1 + i] = current_score;
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << (i == n ? "" : " ");
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  if (cin >> t) {
    while (t--) {
      solve();
    }
  }
  return 0;
}
