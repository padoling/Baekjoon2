#include <iostream>

using namespace std;

int card (int n) {
  // 각 카드 팩의 가격을 저장하는 배열.
  int *cost = new int[n+1];
  for (int i=1; i<=n; i++) {
    cin >> cost[i];
  }

  // 카드를 n개 구매할 때 금액의 최댓값을 저장하는 배열.
  int *max_cost = new int[n+1];
  // 0개 구매할 때 가격 0원.
  max_cost[0] = 0;

  // 카드 i-1개를 구매한 상태에서 1개가 든 카드팩을 구매할 때부터
  // 카드 0개를 구매한 상태에서 i개가 든 카드팩을 구매할 때까지 반복하며
  // 가장 큰 값을 max_cost[i]에 저장.
  for (int i=1; i<=n; i++) {
    // 비교 전 max_cost[i]를 0으로 초기화.
    max_cost[i] = 0;
    for (int j=1; j<=i; j++) {
      if (max_cost[i-j] + cost[j] > max_cost[i])
        max_cost[i] = max_cost[i-j] + cost[j];
    }
  }
  return max_cost[n];
}

int main() {
  int n;
  cin >> n;
  cout << card(n) << '\n';

  // 얘네를 여기서 해 줘도 되는건지.....?
  delete[] cost;
  delete[] max_cost;
  return 0;
}
