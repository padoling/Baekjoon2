#include <iostream>
#incldue <vector>

using namespace std;

vector<int> tree[100000];



void setTree(int n) {
  for(int i=0; i<n; i++) {
    int v, len;
    while(true) {
      cin >> v;
      if(v == -1) {
        break;
      } else {
        tree[i].push_back(v);
      }
      cin >>
    }
  }
}

int main() {
  int n;
  cin >> n;

}
