#include <iostream>

using namespace std;

int longest(int n) {
  // 수열을 입력받아 저장하는 배열.
  int* seq = new int[n];
  // 가장 긴 증가하는 부분수열의 원소 개수를 저장하는 배열.
  int* escalate = new int[n];
  // 결과값.
  int result = 0;

  // 수열 입력받기.
  for (int i=0; i<n; i++) {
    cin >> seq[i];
  }

  // 주 알고리즘 수정 - 정리 및 단순화.
  for (int i=0; i<n; i++) {
    // 부분수열의 개수 초기화.
    escalate[i] = 1;
    // 이전 부분수열들의 마지막 원소가 현재 부분수열의 마지막 원소보다 작은 경우
    // 해당 부분수열들의 길이를 비교하여 가장 긴 길이를 채택.
    for (int j=0; j<i; j++) {
      if (seq[j] < seq[i] && escalate[j]+1 > escalate[i]) {
        escalate[i] = escalate[j]+1;
      }
    }
  }

  // 가장 긴 부분수열을 결과값으로 선택.
  for (int i=0; i<n; i++) {
    if (escalate[i] > result) {
      result = escalate[i];
    }
  }

  // 동적할당 배열 해제.
  delete[] seq;
  delete[] escalate;

  // 결과값 반환.
  return result;
}

int main() {
  int num;
  cin >> num;
  cout << longest(num) << '\n';
  return 0;
}
