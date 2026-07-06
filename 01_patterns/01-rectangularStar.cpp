#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  void rectangularStarPattern(int n) {
    char c = '*';

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << c << " ";
      }
      cout << "\n\n";
    }
  }
  
};

int main () {
  Solution obj;
  int n = 5;
  
  obj.rectangularStarPattern(n);  

  return 0;
}

