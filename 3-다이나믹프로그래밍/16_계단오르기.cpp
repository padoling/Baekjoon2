#include <iostream>
#include <algorithm>

using namespace std;

int max_score[300][3];

int stair(int n) {
  int* score = new int[n];
  int result = 0;

  for (int i=0; i<n; i++) {
    cin >> score[i];
  }

  max_score[0][0] = 0;
  max_score[0][1] = score[0];
  max_score[0][2] = 0;

  for (int i=1; i<n; i++) {
    max_score[i][0] = max(max_score[i-1][1], max_score[i-1][2]);
    max_score[i][1] = max_score[i-1][0] + score[i];
    max_score[i][2] = max_score[i-1][1] + score[i];
  }

  result = max(max_score[n-1][1], max_score[n-1][2]);
  delete[] score;

  return result;
}


int main() {
  int num;
  cin >> num;
  cout << stair(num) << '\n';
  return 0;
}
