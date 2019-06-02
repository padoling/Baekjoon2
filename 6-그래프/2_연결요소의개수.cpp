#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph(1001);
queue<int> queue_bfs;
bool check[1001];


void bfs(int v_start) {
  check[v_start] = true;
  queue_bfs.push(v_start);
  while(!queue_bfs.empty()) {
    int v = queue_bfs.front();
    queue_bfs.pop();
    for(int i=0; i<graph[v].size(); i++) {
      int w = graph[v][i];
      if(check[w] == false) {
        check[w] = true;
        queue_bfs.push(w);
      }
    }
  }
}

int main() {
  int n, m;
  int count = 0;
  cin >> n >> m;
  for(int i=0; i<m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  for(int i=1; i<=n; i++) {
    if(check[i] == false) {
      bfs(i);
      count++;
    }
  }
  cout << count;
  return 0;
}
