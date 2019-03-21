#include <iostream>

using namespace std;

int escalate(int n) {
  // n과 마지막 자리의 수 나타내는 배열 선언.
  int d[1001][10];
  // 10007 저장하는 상수 div 선언.
  const int div = 10007;

  // 한자리수일 때 경우의 수 1 저장.
  for (int i=0; i<10; i++) {
    d[1][i] = 1;
  }

  // 두자리수 이상일 때.
  for (int i=2; i<=n; i++) {
    for (int j=0; j<10; j++) {
      // 먼저 0으로 초기화.
      d[i][j] = 0;
      // k는 i-1자리의 숫자로, j보다 작거나 같을 수밖에 없음.
      // 해당하는 k의 경우의 수를 모두 더함.
      for (int k=0; k<=j; k++) {
        d[i][j] += (d[i-1][k])%10007;
      }
    }
  }

// 결과 계산.
  int result = 0;
  for (int i=0; i<10; i++) {
    result += d[n][i];
    result %= div;
  }
  return result;
}

int main() {
  int n;
  cin >> n;
  cout << escalate(n) << '\n';
  return 0;
}
