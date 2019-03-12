// 재귀호출 방식
// 백준 시간초과

#include <iostream>
#include <algorithm>

using namespace std;

int makingOne(int n) {
  // Base case
  if (n == 1) {
    return 0;
  } else {
    if (n%3 == 0) {
      // n이 3으로 나누어 떨어질 때
      return (1 + min(makingOne(n/3), makingOne(n-1)));
    } else if (n%2 == 0) {
      // n이 2로 나누어 떨어질 때
      return (1 + min(makingOne(n/2), makingOne(n-1)));
    } else {
      // 나머지 case
      return (1 + makingOne(n-1));
    }
  }
}

int main() {
  int N;
  cin >> N;
  cout << makingOne(N) << '\n';
  return 0;
}
