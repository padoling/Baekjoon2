#include <iostream>
#include <algorithm>

using namespace std;

void sorting(int n) {
  int* num = new int[n];
  for(int i=0; i<n; i++) {
    cin >> num[i];
  }
  sort(num, num+n);
  for(int i=0; i<n; i++) {
    cout << num[i] << '\n';
  }
  return;
}

int main() {
  int n;
  cin >> n;
  sorting(n);
  return 0;
}
