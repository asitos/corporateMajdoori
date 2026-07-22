#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> unionOfTwoSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    // // using set
    // set<int> st;
    //
    // for (int i = 0; i < arr1.size(); i++) {
    //   st.insert(arr1[i]);
    // }
    //
    // for (int i = 0; i < arr2.size(); i++) {
    //   st.insert(arr2[i]);
    // }
    //
    // vector<int> res(st.begin(), st.end());
    // return res;

    // optimised two pointers

    int n = arr1.size();
    int m = arr2.size();
    vector<int> Union;
    Union.reserve(n + m); // tell the compiler to reserve this memory only

    int i = 0, j = 0;

    while (i < n && j < m) {
      if (arr1[i] < arr2[j]) {
        if (Union.empty() || Union.back() != arr1[i]) {
          Union.push_back(arr1[i]);
        }
        i++;
      } else if (arr2[j] < arr1[i]) {
        if (Union.empty() || Union.back() != arr2[j]) {
          Union.push_back(arr2[j]);
        }
        j++;
      } else {
        if (Union.empty() || Union.back() != arr1[i]) {
          Union.push_back(arr1[i]);
        }
        i++; j++;
      }
    }

    while (i < n) {
      if (Union.empty() || Union.back() != arr1[i]) {
        Union.push_back(arr1[i]);
      }
      i++;
    }
    while (j < m) {
      if (Union.empty() || Union.back() != arr2[j]) {
        Union.push_back(arr2[j]);
      }
      j++;
    }
 
    return Union;
  }
};

int main() {
  Solution obj;
  vector<int> arr1 = {1, 2, 3, 4, 5};
  vector<int> arr2 = {2, 3, 4, 4, 5};
  vector<int> res = obj.unionOfTwoSortedArrays(arr1, arr2);

  for (auto i : res) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
