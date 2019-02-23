#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
  int t;
  string str;
  cin >> t;
  for (int i=0; i<t; i++) {
    str = "";
    stack<int> s;
    cin >> str;

    int l = str.size();
    int j;
    for (j=0; j<l; j++) {
      if (str[j] == '(') {
        s.push(1);
      } else if (str[j] == ')') {
        if (s.empty()) {
          break;
        } else {
          s.pop();
        }
      }
    }
    if (j == l && s.empty()) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}
