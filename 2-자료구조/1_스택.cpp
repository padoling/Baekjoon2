#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
  int n;
  cin >> n;
  string str;
  stack<int> s;
  for (int i=0; i<n; i++) {
    str = "";
    cin >> str;
    if (str == "push") {
      int m;
      cin >> m;
      s.push(m);
    } else if (str == "pop") {
      if (s.empty()) {
        cout << -1 << '\n';
      } else {
        cout << s.top() << '\n';
		s.pop();
      }
    } else if (str == "size") {
      cout << s.size() << '\n';
    } else if (str == "empty") {
      if (s.empty()) {
        cout << 1 << '\n';
      } else {
        cout << 0 << '\n';
      }
    } else if (str == "top") {
      if (s.empty()) {
        cout << -1 << '\n';
      } else {
        cout << s.top() << '\n';
      }
    }
  }
  return 0;
}
