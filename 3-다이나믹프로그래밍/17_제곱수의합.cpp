#include <iostream>

using namespace std;

int square(int n) {
  int* arr = new int[n+1];
  arr[0] = 0;

  for(int i=1; i<=n; i++) {
    arr[i] = i;
    for(int j=1; j*j<=i; j++) {
      if(arr[i] > arr[i-j*j]) {
        arr[i] = arr[i-j*j]+1;
      }
    }
  }
  int result = arr[n];
  delete[] arr;
  return result;
}

int main() {
  int num;
  cin >> num;
  cout << square(num) << '\n';
  return 0;
}
