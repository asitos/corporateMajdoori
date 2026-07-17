#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void freqOfEachElementInArray(vector<int>& arr) {
    unordered_map<int, int> mp;

    for (int i = 0; i < arr.size(); i++) {
      mp[arr[i]]++;
    }

    for (auto f : mp) {
      cout << f.first << " " << f.second << "\n";
    }
  }
};

int main() {
  Solution obj;
  vector<int> arr = {10, 5, 10, 15, 10, 5};

  obj.freqOfEachElementInArray(arr);

  return 0;
}
