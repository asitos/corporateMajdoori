#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n), b(n);
  int sa = 0, sb = 0;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sa ^= a[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> b[i];
    sb ^= b[i];
  }

  vector<int> A(n + 1), B(n + 1);

  for (int i = 0; i < n; i++) {
    A[i] = a[i] ^ sa;
    B[i] = b[i] ^ sb;
  }

  A[n] = sa;
  B[n] = sb;

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  if (A == B) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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
