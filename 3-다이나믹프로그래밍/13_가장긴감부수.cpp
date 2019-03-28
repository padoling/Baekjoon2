#include <iostream>

using namespace std;

int decrease(int n) {
  int* seq = new int[n];
  int* subseq = new int[n];
  int result = 0;
  for (int i=0; i<n; i++) {
    cin >> seq[i];
  }

  for (int i=0; i<n; i++) {
    subseq[i] = 1;
    for (int j=0; j<i; j++) {
      if (seq[j] > seq[i] && subseq[j]+1 > subseq[i]) {
        subseq[i] = subseq[j]+1;
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
  cout << decrease(num) << '\n';
  return 0;
}
