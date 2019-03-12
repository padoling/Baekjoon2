#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void suffix(string str, int len) {
  string arr[1000] = {""};
  len = str.size();
  for (int i=0; i<len; i++) {
    arr[i] = str.substr(i);
  }
  sort(arr, arr+len);
  for (int i=0; i<len; i++) {
    cout << arr[i] << '\n';
  }
}

int main() {
  string s;
  cin >> s;
  int len = s.size();
  suffix(s, len);
  return 0;
}
