#include <iostream>
#include <string>

using namespace std;

class StringAnalysis {
public:
  string str;
  int length;
  int lower;
  int upper;
  int num;
  int space;

  void analysis();
};

void StringAnalysis::analysis() {
  length = str.size();
  lower = 0;
  upper = 0;
  num = 0;
  space = 0;
  for (int i=0; i<length; i++) {
    if (str[i] >= 97 && str[i] <= 122) {
      lower++;
    } else if (str[i] >= 65 && str[i] <= 90) {
      upper++;
    } else if (str[i] >= 48 && str[i] <= 57) {
      num++;
    } else if (str[i] == 32) {
      space++;
    }
  }
  cout << lower << ' ' << upper << ' ' << num << ' ' << space << '\n';
}

int main() {
StringAnalysis stringAnalysis;
  while(getline(cin, stringAnalysis.str)) {
    stringAnalysis.analysis();
  }
  return 0;
}
