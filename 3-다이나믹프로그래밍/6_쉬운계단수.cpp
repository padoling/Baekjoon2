#include <iostream>

using namespace std;

// 자리수 N과 해당 수의 맨 끝자리 숫자를 나타내는 배열.
int d[101][10];

// 계단수의 개수를 계산하는 함수.
int stair(int n) {

	const int div = 1000000000;

  // 0으로 시작할 수 없음.
  d[1][0] = 0;
  // 한자리수일 때 계단수의 개수 1로 채워줌.
  for (int i=1; i<10; i++) {
    d[1][i] = 1;
  }

  // 1의자리 숫자가 0일 때, 9일 때, 그 밖으로 나누어 계산.
  for (int i=2; i<=n; i++) {
    for (int j=0; j<10; j++) {
      if (j==0) {
        // 1의자리 숫자가 0일 때는 그 전자리 수가 1일 수밖에 없음.
        d[i][j] = (d[i-1][j+1])%div;
      } else if (j==9) {
        // 1의자리 숫자가 9일 때는 그 전자리 수가 8일 수밖에 없음.
        d[i][j] = (d[i-1][j-1])%div;
      } else {
        // 그 외의 경우에는 두 가지의 경우의 수가 있음.
        d[i][j] = (d[i-1][j-1] + d[i-1][j+1])%div;
      }
    }
  }

  // n자리 수일 때 게단수의 총 개수 계산.
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
  cout << stair(n) << '\n';
  return 0;
}
