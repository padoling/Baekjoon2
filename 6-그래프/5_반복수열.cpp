#include <iostream>

using namespace std;

// 현재 값의 인덱스를 그 값을 인덱스로 하는 공간에 저장하는 배열.
int check[1000000];

int repeat(int a, int p, int cnt) {
  // 이전에 a값이 나왔던 경우 return.
  if(check[a] != 0) {
    return (check[a]-1);
  }
  int next = 0;
  int temp = a;

  // a 다음 값(next) 구하기
  while(temp != 0) {
    int div = temp%10;
	  int divtemp = div;
	  for (int i = 1; i < p; i++) {
      div *= divtemp;
	  }
    next += div;
    temp /= 10;
  }

  // 현재 인덱스를 저장.
  check[a] = cnt;
  return repeat(next, p, cnt+1);
}

int main() {
  int a, p;
  cin >> a >> p;
  int result = repeat(a, p, 1);
  cout << result;
  return 0;
}
