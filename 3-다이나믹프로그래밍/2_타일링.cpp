#include <iostream>

using namespace std;

// 최대 n 크기의 배열 선언
int d[1001];

// 2*n크기의 타일의 마지막 부분을 채우는 경우의 수 2가지
// d[n-1]과 d[n-2]를 더하면 d[n] 구할 수 있음
int tile(int n) {
  // n-1, n-2를 계산하기 위해 초기값 설정
  d[0] = 1;
  d[1] = 1;

  if (n == 1) {
    return d[1];
  } else {
    for (int i=2; i<=n; i++) {
      // n이 커지면 오버플로우가 일어남
      // 10007로 나눈 나머지를 저장해도 결과는 같다
      d[i] = ((d[i-1] + d[i-2])%10007);
    }
  }
  return (d[n]%10007);
}

int main() {
  int n;
  cin >> n;
  cout << tile(n) << '\n';
  return 0;
}
