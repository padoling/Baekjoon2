#include <iostream>

using namespace std;

int d[1001];

// 마지막 타일을 채우는 경우의 수가 3가지
// 그 중 타일 두칸짜리가 2가지이므로 d[i-2]에 2를 곱해줌
int tile2(int n) {
  d[0] = 1;
  d[1] = 1;

  if (n == 1) {
    return d[1];
  } else {
    for (int i=2; i<=n; i++) {
      d[i] = ((d[i-1] + 2*d[i-2]) % 10007);
    }
  }
  return (d[n] % 10007);
}

int main() {
  int n;
  cin >> n;
  cout << tile2(n) << '\n';
  return 0;
}
