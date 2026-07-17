#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> highestLowestFrequencyElement(vector<int>& arr) {
    unordered_map<int, int> mp;

    for (int i = 0; i < arr.size(); i++) {
      mp[arr[i]]++;
    }

    vector<int> res = {0, 0};

    int max_freq = INT_MIN;
    int min_freq = INT_MAX;

    for (auto f : mp) {
      int elem = f.first;
      int freq = f.second;

      if (freq > max_freq) {
        max_freq = freq;
        res[0] = elem;
      } else if (freq == max_freq) {
        if (elem < res[0]) {
            res[0] = elem;
        }
      }

      if (freq < min_freq) {
        min_freq = freq;
        res[1] = elem;
      } else if (freq == min_freq) {
        if (elem < res[1]) {
          res[1] = elem;
        }
      }
    }

    return res;
  }
};

int main() {
  Solution obj;
  vector<int> arr = {10, 5, 10, 15, 10, 5};
  vector<int> res = obj.highestLowestFrequencyElement(arr);

  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;

  return 0;
}
