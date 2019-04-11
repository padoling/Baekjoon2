#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Coord{
  int x;
  int y;
};

bool cmp(const Coord &c1, const Coord &c2) {
  if(c1.y < c2.y) {
    return true;
  } else if(c1.y == c2.y) {
    return (c1.x < c2.x);
  } else {
    return false;
  }
}

void sorting(int n) {
  vector<Coord> coord;
  for(int i=0; i<n; i++) {
    Coord input;
    cin >> input.x >> input.y;
    coord.push_back(input);
  }

  sort(coord.begin(), coord.end(), cmp);

  vector<Coord>::iterator iter;
  for(iter=coord.begin(); iter!=coord.end(); iter++) {
    cout << iter->x << ' ' << iter->y << '\n';
  }
  return;
}

int main() {
  int n;
  cin >> n;
  sorting(n);
  return 0;
}
