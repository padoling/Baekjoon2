#include <iostream>
#include <algorithm>

using namespace std;

// 몇 번 연속 마셨는가
int d[10000][3];

int wine_max(int n) {
  int result = 0;
  int *wine = new int[n];
  for (int i=0; i<n; i++) {
    cin >> wine[i];
  }

  d[0][0] = 0;
  d[0][1] = wine[0];
  d[0][2] = 0;
  for (int i=1; i<n; i++) {
    // 0번 연속으로 마신 경우 직전에 모든 경우가 다 해당될 수 있음.
    d[i][0] = max(d[i-1][1], d[i-1][2]);
    // 아래의 경우의 수도 반드시 포함해주어야 함!
    d[i][0] = max(d[i][0], d[i-1][0]);
    // 1번 연속으로 마신 경우 직전에 무조건 마시지 않았어야 함.
    d[i][1] = d[i-1][0] + wine[i];
    // 2번 연속으로 마신 경우 직전에 무조건 1번 연속으로 마셨어야 함.
    d[i][2] = d[i-1][1] + wine[i];
  }
  result = max(d[n-1][0], d[n-1][1]);
  result = max(result, d[n-1][2]);

  return result;
}

int main() {
  int n;
  cin >> n;
  cout << wine_max(n) << '\n';
  return 0;
}
