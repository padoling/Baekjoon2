#include <iostream>
#include <algorithm>

using namespace std;

// 각 행의 점수를 저장하는 배열.
int score1[100000];
int score2[100000];

// 최대 점수를 저장하는 배열.
// d[i][0] = 아무것도 뜯지 않음
// d[i][1] = 위쪽을 뜯음
// d[i][2] = 아래쪽을 뜯음
int d[100000][3];

int sticker(int n) {
  int result = 0;

  // 점수 입력받아 저장.
  for (int i=0; i<n; i++) {
    cin >> score1[i];
  }
  for (int i=0; i<n; i++) {
    cin >> score2[i];
  }

  // n=1일 때 점수 초기화.
  d[0][0] = 0;
  d[0][1] = score1[0];
  d[0][2] = score2[0];


  for (int i=1; i<n; i++) {
    d[i][0] = max(d[i-1][1], d[i-1][2]);
    d[i][1] = max(d[i-1][0], d[i-1][2]) + score1[i];
    d[i][2] = max(d[i-1][0], d[i-1][1]) + score2[i];
  }

  result = max(d[n-1][0], d[n-1][1]);
  result = max(result, d[n-1][2]);
  return result;
}

int main() {
  int t;
  cin >> t;
  for (int i=0; i<t; i++) {
    int n;
    cin >> n;
    cout << sticker(n) << '\n';
  }
  return 0;
}
