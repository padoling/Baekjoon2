#include <iostream>

using namespace std;

int tile(int n) {
  int* arr = new int[n];
  arr[0] = 0;
  arr[1] = 3;

  if(n>=2) {
    for(int i=2; i<n; i++) {
      arr[i] = arr[i-2] * 3;
    }
  }
  int result = arr[n-1];
  delete[] arr;
  return result;
}

int main() {
  int n;
  cin >> n;
  cout << tile(n) << '\n';
  return 0;
}
