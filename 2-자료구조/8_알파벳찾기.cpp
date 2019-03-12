#include <iostream>
#include <string>

using namespace std;

class Alphabet {
private:
  string word;
  int arr[26];

public:
  void initiate() {
    cin >> word;
    int length = word.size();
    fill_n(arr, 26, -1);

    for (int i=0; i<length; i++) {
      if (arr[word[i]-97] != -1) {
        continue;
      } else {
        arr[word[i]-97] = i;
      }
    }

    for (int j=0; j<26; j++) {
      cout << arr[j] << ' ';
    }

    cout << '\n';
  }
};

int main() {
  Alphabet alphabet;
  alphabet.initiate();
  return 0;
}
