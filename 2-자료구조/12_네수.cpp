#include <iostream>
#include <string>

using namespace std;

long long sum(string a, string b, string c, string d) {
  string ab = a+b;
  string cd = c+d;
  return stoll(ab) + stoll(cd);
}

int main() {
  string a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << sum(a, b, c, d) << '\n';
  return 0;
}
