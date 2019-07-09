#include <iostream>

using namespace std;
int graph[1001];
bool check[1001];

void dfs(int v) {
  check[v] = true;
  int w = graph[v];
  if(check[w] == false) {
    dfs(w);
  }
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    int count = 0;  // 순열 사이클의 개수
    cin >> n;

    // 순열 입력
    for(int i=1; i<=n; i++) {
      int u;
      cin >> u;
      graph[i] = u;
    }

    // 해당 인덱스를 방문했는지 검사
    for(int i=1; i<=n; i++) {
      if(check[i] == false) {
        // dfs를 할 때마다 사이클 개수 증가
        dfs(i);
        count++;
      }
    }
    cout << count <<'\n';

    // 값 초기화
    for(int i=1; i<=n; i++) {
      graph[i] = 0;
      check[i] = false;
    }
  }
  return 0;
}
