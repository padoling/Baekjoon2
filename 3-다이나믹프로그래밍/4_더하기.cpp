#include <iostream>

using namespace std;

int add(int n) {
  int d[11];

  // 3까지는 더해지는 수에 해당하므로 값 미리 설정
  d[0] = 0;
  d[1] = 1;
  d[2] = 2;
  d[3] = 4;

  if (n<=3) {
    // 3 이하일 경우 저장된 값 그대로 반환
    return d[n];
  } else {
    // 3 초과일 경우 마지막에 어떤 수가 더해질지에 대한 세 가지 경우의 수가 있음
    for (int j=4; j<=n; j++) {
      d[j] = d[j-1] + d[j-2] + d[j-3];
    }
    return d[n];
  }
}

int main() {
  int t;
  cin >> t;
  for (int i=0; i<t; i++) {
    int n;
    cin >> n;
    cout << add(n) << '\n';
  }
  return 0;
}
