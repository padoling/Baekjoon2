#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[100000];

void parentSearch(int n) {
  
}

int main() {
  int n;
  cin >> n;
  int parent[n];

  for(int i=0; i<n; i++) {
    int u, v;
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }




}
