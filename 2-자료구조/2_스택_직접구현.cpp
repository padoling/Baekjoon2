#include <iostream>
#include <string>
using namespace std;

int stack[10000];
int p = 0;

void push(int x) {
  stack[p] = x;
  p++;
}

int pop() {
  if(p == 0) {
    return -1;
  } else {
    p--;
    return stack[p];
  }
}

int size() {
  return p;
}

int empty() {
  if(p == 0) {
    return 1;
  } else {
    return 0;
  }
}

int top() {
  if(p == 0) {
    return -1;
  } else {
    return stack[p-1];
  }
}

int main() {
  int n;
  string str;
  cin >> n;
  for (int i=0; i<n; i++) {
    str = "";
    cin >> str;
    if (str == "push") {
      int x;
      cin >> x;
      push(x);
    } else if (str == "pop") {
      cout << pop() << '\n';
    } else if (str == "size") {
      cout << size() << '\n';
    } else if (str == "empty") {
      cout << empty() << '\n';
    } else if (str == "top") {
      cout << top() << '\n';
    }
  }
  return 0;
}
