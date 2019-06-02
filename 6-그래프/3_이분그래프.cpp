// 틀렸습니다

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph(20001);
queue<int> queue_bfs;
int check[20001];

void bfs(int v_start) {
  check[v_start] = 1;
  queue_bfs.push(v_start);
  while(!queue_bfs.empty()) {
    int v = queue_bfs.front();
    queue_bfs.pop();
    for(int i=0; i<graph[v].size(); i++) {
      int w = graph[v][i];
      if(check[w] == 0) {
        if(check[v] == 1) {
          check[w] = 2;
        } else if(check[v] == 2) {
          check[w] = 1;
        }
        queue_bfs.push(w);
      }
    }
  }
}

int main() {
  int k;
  cin >> k;

  for(int i=0; i<k; i++) {
    int n, m;
    cin >> n >> m;
    for(int j=0; j<m; j++) {
      int u, v;
      cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    for(int j=0; j<n; j++) {
      if(check[j] == 0)
        bfs(j);
    }

    bool bipartite = true;
    for(int j=0; j<n; j++) {
      for(int l=0; l<graph[j].size(); l++) {
        int w = graph[j][l];
        if(check[j] == check[w]) {
          bipartite = false;
        }
      }
    }

    if(bipartite == true)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';

    for(int j=0; j<n; j++) {
      graph[j].clear();
      check[j] = 0;
    }
    while(!queue_bfs.empty())
      queue_bfs.pop();
  }

  return 0;
}
