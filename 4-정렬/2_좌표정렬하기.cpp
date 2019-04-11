#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

void sorting(int n) {
  // 좌표를 담는 pair vector.
  vector<pair<int,int>> coord;
  for(int i=0; i<n; i++) {
    int a, b;
    cin >> a >> b;
    coord.push_back(pair<int, int>(a,b));
  }

  // pair를 사용하면 sort에 의한 정렬에서
  // 첫번재 인자 기준, 첫번째가 같으면 두번째 인자 기준으로 정렬.
  sort(coord.begin(), coord.end());

  // iterator. vector 반복자.
  vector<pair<int,int>>::iterator iter;
  for(iter=coord.begin(); iter!=coord.end(); iter++) {
    cout << iter->first << ' ' << iter->second << '\n';
  }
  return;
}

int main() {
  int n;
  cin >> n;
  sorting(n);
  return 0;
}
