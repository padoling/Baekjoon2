#include <iostream>
#include <algorithm>

using namespace std;

int k_number(int n, int k)
{
  int* num = new int[n];
  for(int i=0; i<n; i++)
  {
    cin >> num[i];
  }
  nth_element(num, num+k, num+n);
  int result = num[k-1];
  delete[] num;
  return result;
}

int main()
{
  int n;
  int k;
  cin >> n >> k;
  cout << k_number(n,k) << '\n';
  return 0;
}
