#include <iostream>
#include <string>

using namespace std;

void rot13(string str) {
  int length = str.size();
  for (int i=0; i<length; i++) {
    if (str[i]>='A' && str[i]<='M') {
      str[i] += 13;
    } else if (str[i]>='a' && str[i]<='m') {
      str[i] += 13;
    } else if (str[i]>='N' && str[i]<='Z') {
      str[i] -= 13;
    } else if (str[i]>='n' && str[i]<='z') {
      str[i] -= 13;
    }
  }
  cout << str << '\n';
}

int main() {
  string s;
  getline(cin, s);
  rot13(s);
  return 0;
}
