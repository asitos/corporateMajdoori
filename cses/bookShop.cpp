#include <bits/stdc++.h>
using namespace std;

// int dp[1002][100005]; // 2d table caused tle/cache misses needing ~400MB

class Solution {
public:
  // recursive approach
  // int knapsack(vector<int> &wt, vector<int> &val, int x, int n) {
  //   // base condition
  //   if (n == 0 || x == 0) {
  //     return 0;
  //   }
  //
  //   // take
  //   if (wt[n - 1] <= x) {
  //     return max(val[n - 1] + knapsack(wt, val, x - wt[n - 1], n - 1),
  //                knapsack(wt, val, x, n - 1));
  //   } else {
  //     return knapsack(wt, val, x, n - 1);
  //   }
  // }
  // memoized approach with dp
  // int knapsack(vector<int> &wt, vector<int> &val, int x, int n) {
  //   // base condition
  //   if (n == 0 || x == 0) {
  //     return 0;
  //   }
  //
  //   // check
  //   if (dp[n][x] != -1) {
  //     return dp[n][x];
  //   }
  //
  //   // take
  //   if (wt[n - 1] <= x) {
  //     return dp[n][x] =
  //                max(val[n - 1] + knapsack(wt, val, x - wt[n - 1], n - 1),
  //                    knapsack(wt, val, x, n - 1));
  //   } else {
  //     return dp[n][x] = knapsack(wt, val, x, n - 1);
  //   }
  // }
  //
  // 1d space-optimised iterative approach
  int knapsack(vector<int> &wt, vector<int> &val, int x, int n) {
    vector<int> dp(x + 1, 0);

    for (int i = 0; i < n; i++) {
      int currWt = wt[i];
      int currVal = val[i];

      // run backwards from capacity x down to currWt
      for (int j = x; j >= currWt; j--) {
        dp[j] = max(dp[j], currVal + dp[j - currWt]);
      }
    }

    return dp[x];
  }
};

int main() {

  // memset(dp, -1, sizeof(dp));
  // fast i/o

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Solution obj;
  int n, x;
  cin >> n >> x;
  int vali, wti;

  vector<int> wt, val;
  for (int i = 0; i < n; i++) {
    cin >> wti;
    wt.push_back(wti);
  }

  for (int i = 0; i < n; i++) {
    cin >> vali;
    val.push_back(vali);
  }

  cout << obj.knapsack(wt, val, x, n);

  return 0;
}
