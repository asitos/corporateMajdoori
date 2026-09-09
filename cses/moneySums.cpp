#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums) {
  int n = nums.size();
  vector<vector<int>> dp(n + 1, vector<int>(w + 1))
      // initialise dp table

      return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, x;
  vector<int> arr;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> x;
    arr.push_back(x);
  }

  solve(arr);

  return 0;
}
