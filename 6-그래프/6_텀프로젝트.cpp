#include <iostream>

using namespace std;

int student[100001];
int check[100001];

void dfs(int v, int cnt) {
  check[v] = cnt;
  int w = student[v];
  if(check[w] != 0) {
    if(check[w] == cnt) {
      //우우우ㅜ웅ㅇㄴㅁ울ㅈㄷ
    }
  }
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    // 선택 결과 받기
    for(int i=1; i<=n; i++) {
      int u;
      cin >> u;
      student[i] = u;
    }
    int cnt=1;
    for(int i=1; i<=n; i++) {
      if(check[i] == 0) {
        dfs[i, cnt];
      }

    }
  }
}
