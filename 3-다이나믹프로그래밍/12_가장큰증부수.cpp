#include <iostream>

using namespace std;

int largest(int n) {
  int* seq = new int[n];
  int* subseq = new int[n];
  int result = 0;

  for (int i=0; i<n; i++) {
    cin >> seq[i];
  }

  for (int i=0; i<n; i++) {
    subseq[i] = seq[i];
    for (int j=0; j<i; j++) {
      // i번째 수가 j번째 수보다 크고
      // j번째 수가 마지막인 부분수열이 클 때
      if (seq[j] < seq[i] && (subseq[j]+seq[i]) > subseq[i]) {
        subseq[i] = (subseq[j]+seq[i]);
      }
    }
  }

  for (int i=0; i<n; i++) {
    if (result < subseq[i]) {
      result = subseq[i];
    }
  }
  delete[] seq;
  delete[] subseq;

  return result;
}

int main() {
  int num;
  cin >> num;
  cout << largest(num) << '\n';
  return 0;
}
