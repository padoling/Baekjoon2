#include <iostream>

using namespace std;

class Traversal {
private:
  char tree[30][2];

public:
  void setTree(int n) {
    char node, left, right;
    for(int i=0; i<n; i++) {
      cin >> node >> left >> right;
      node -= 'A';
      if(left != '.')
        left -= 'A';
      if(right != '.')
        right -= 'A';
      tree[node][0] = left;
      tree[node][1] = right;
    }
  }

  void preOrder(int x) {
    cout << (char)(x + 'A');
    if(tree[x][0] != '.') {
      preOrder(tree[x][0]);
    }
    if(tree[x][1] != '.') {
      preOrder(tree[x][1]);
    }
  }

  void inOrder(int x) {
    if(tree[x][0] != '.') {
      inOrder(tree[x][0]);
    }
    cout << (char)(x + 'A');
    if(tree[x][1] != '.') {
      inOrder(tree[x][1]);
    }
  }

  void postOrder(int x) {
    if(tree[x][0] != '.') {
      postOrder(tree[x][0]);
    }
    if(tree[x][1] != '.') {
      postOrder(tree[x][1]);
    }
    cout << (char)(x + 'A');
  }
};

int main() {
  int n;
  cin >> n;
  Traversal traversal;
  traversal.setTree(n);
  traversal.preOrder(0);
  cout << '\n';
  traversal.inOrder(0);
  cout << '\n';
  traversal.postOrder(0);
  cout << '\n';
  return 0;
}
