#include <iostream>
#include <algorithm>

using namespace std;

long most_card(int n)
{
  long* card = new long[n];
  for(int i=0; i<n; i++)
  {
    cin >> card[i];
  }
  sort(card, card+n);
  long result = card[0];
  int max = 0;
  int cur = 1;
  for(int i=1; i<n; i++)
  {
    if(card[i] == card[i-1])
    {
      cur++;
      if(cur > max)
      {
        max = cur;
        result = card[i];
      }
    } else {
      cur = 1;
    }
  }
  delete[] card;
  return result;
}

int main()
{
  int n;
  cin >> n;
  cout << most_card(n) << '\n';
  return 0;
}
