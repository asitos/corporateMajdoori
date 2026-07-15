#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  void printNameNTimes(string name, int count, int n) {
    if (count == n) {
      return;
    }
    cout << name << " ";
    
    printNameNTimes(name, count + 1, n);
  }

};

int main() {
  Solution obj;
  int n = 5;
  obj.printNameNTimes("asitos", 0, n); 

  return 0;
}
