#include <iostream>

using namespace std;

// 값이 커지면 int의 범위를 벗어나므로 반환형을 long으로 선언.
long pinary(int n) {

  // 자리수와 가장 끝자리 수를 나타내는 배열.
  long d[90][2];

  // 한자리수일 때 이친수의 개수 초기화.
  // 0으로 시작할 수 없으므로 d[0][0] = 0.
  d[0][0] = 0;
  d[0][1] = 1;

  // 0으로 끝나는 수일 경우 이전 자리가 0이거나 1일 수 있음.
  // 1로 끝나는 수일 경우 이전 자리가 0이어야만 함.
  for (int i=1; i<n; i++) {
    d[i][0] = d[i-1][0] + d[i-1][1];
    d[i][1] = d[i-1][0];
  }
  return (d[n-1][0] + d[n-1][1]);
}

int main() {
  int n;
  cin >> n;
  cout << pinary(n) << '\n';
  return 0;
}
