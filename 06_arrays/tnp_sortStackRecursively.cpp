#include <bits/stdc++.h>
#include <stack>
using namespace std;

// @leet start
class Solution {
public:
  void tnp_sortStackRecursively(vector<int> &st) {

    // base case
    if (st.size() == 0) {
      return;
    }

    int temp1 = st.pop();
    sort(st);

    if (st.empty() || temp1 >= st.peek()) {
      st.push(temp1);
    }
  }
};
// @leet end

int main() {
  Solution obj;
  stack<int st> t = {5, 4, 3, 2, 1};
  obj.tnp_sortStackRecursively(nums);

  cout << nums;

  return 0;
}
