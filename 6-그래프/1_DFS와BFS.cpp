#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> graph(1001);
bool check_dfs[1001];
bool check_bfs[1001];
queue<int> queue_bfs;

void dfs(int v) {
  check_dfs[v] = true;
  cout << v << ' ';
  for(int i=0; i<graph[v].size(); i++) {
    int w = graph[v][i];
    if(check_dfs[w] == false) {
      dfs(w);
    }
  }
}

void bfs(int v) {
  check_bfs[v] = true;
  queue_bfs.push(v);
  cout << v << ' ';
  while(!queue_bfs.empty()) {
    int w = queue_bfs.front();
    queue_bfs.pop();
    for(int i=0; i<graph[w].size(); i++) {
      int x = graph[w][i];
      if(check_bfs[x] == false) {
        check_bfs[x] = true;
        queue_bfs.push(x);
        cout << x << ' ';
      }
    }
  }
}

int main() {
  int n, m, v_start;
  cin >> n >> m >> v_start;
  for(int i=0; i<m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  for(int i=0; i<n; i++) {
    sort(graph[i].begin(), graph[i].end());
  }

  dfs(v_start);
  cout << '\n';
  bfs(v_start);

  return 0;
}
