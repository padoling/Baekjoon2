#include <iostream>

using namespace std;

int bitonic(int n) {
  int* seq = new int[n];
  int* increase = new int[n];
  int* decrease = new int[n];

  int result = 0;

  for (int i=0; i<n; i++) {
    cin >> seq[i];
  }

  for (int i=0; i<n; i++) {
    increase[i] = 1;
    decrease[n-i-1] = 1;

    // 가장 긴 증부수
    for (int j=0; j<i; j++) {
      if (seq[j] < seq[i] && increase[j]+1 > increase[i]) {
        increase[i] = increase[j]+1;
      }
    }
    // 가장 긴 감부수 거꾸로 버전
    for (int j=0; j<i; j++) {
      if (seq[n-j-1] < seq[n-i-1] && decrease[n-j-1]+1 > decrease[n-i-1]) {
        decrease[n-i-1] = decrease[n-j-1]+1;
      }
    }
  }

  // 두 부분수열의 같은 부분을 기준으로 합쳤을 때 가장 긴 수열 찾기
  for (int i=0; i<n; i++) {
    if ((increase[i] + decrease[i])-1 > result) {
      result = (increase[i] + decrease[i])-1;
    }
  }

  delete[] seq;
  delete[] increase;
  delete[] decrease;

  return result;
}

int main() {
  int num;
  cin >> num;
  cout << bitonic(num) << '\n';
  return 0;
}
