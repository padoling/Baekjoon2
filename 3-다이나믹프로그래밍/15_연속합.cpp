// 백준 알고리즘 채점 결과: 메모리 2772KB 시간 20ms
// 너무 오래 걸린 것 같다...

#include <iostream>

using namespace std;

int serial(int n) {
  int* seq = new int[n];
  int* addseq = new int[n];
  int result;

  for (int i=0; i<n; i++) {
    cin >> seq[i];
  }

  addseq[0] = seq[0];
  for (int i=1; i<n; i++) {
    addseq[i] = seq[i];
    // i-1번째가 마지막인 연속합이 클 때
    if (addseq[i-1]+seq[i] > addseq[i]) {
      addseq[i] += addseq[i-1];
    }
  }

  // 연속합들 중 가장 큰 값 찾기
  result = addseq[0];
  for (int i=1; i<n; i++) {
    if (addseq[i] > result) {
      result = addseq[i];
    }
  }

  delete[] seq;
  delete[] addseq;
  return result;
}

int main() {
  int num;
  cin >> num;
  cout << serial(num) << '\n';
  return 0;
}
