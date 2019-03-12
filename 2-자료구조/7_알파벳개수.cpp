#include <iostream>
#include <string>

using namespace std;

class Alphabet {
private:
  string word;

public:
  void count() {
    cin >> word;
    int length = word.size();
    int alpha_num[26] = {0};

    for (int i=0; i<length; i++) {
      alpha_num[word[i]-97] += 1;
    }
    for (int j=0; j<26; j++) {
      cout << alpha_num[j] << ' ';
    }
    cout << '\n';
  }
};

int main() {
  Alphabet alphabet;
  alphabet.count();
  return 0;
}
