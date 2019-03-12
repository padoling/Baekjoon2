#include <iostream>
#include <algorithm>

using namespace std;

int d[1000001];

int makingOne(int n) {
  d[0] = 0;
  d[1] = 0;

  // Base case
  if (n == 1) {
    return d[1];
  } else {
    // i이 n에 도달할 때까지 증가하면서 배열 d에 모든 값을 저장.
    for (int i=2; i<=n; i++) {
      if (i%3 == 0) {
        // i가 3으로 나누어 떨어질 때
        d[i] = (1 + min(d[i-1], d[i/3]));
      } else if (i%2 == 0) {
        // i가 2로 나누어 떨어질 때
        d[i] = (1 + min(d[i-1], d[i/2]));
      } else {
        // 나머지 경우
        d[i] = (1 + d[i-1]);
      }
    }
  }
  return d[n];
}

int main() {
  int N;
  cin >> N;
  cout << makingOne(N) << '\n';
  return 0;
}
