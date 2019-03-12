#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Stick {
  private:
    string str;
    stack<int> open;
    int piece;

  public:
    int cutting() {
		  piece = 0;
      cin >> str;
      int length = str.size();

      for (int i=0; i<length; i++) {
        if (str[i] == '(') {
          open.push(1);
        } else if (str[i] == ')') {
          if (str[i-1] == '(') {
			      open.pop();
			      piece += open.size();
          } else {
            piece += 1;
            open.pop();
          }
        }
      }
      return piece;
    }
};

int main() {
  Stick stick;
  cout << stick.cutting() << '\n';
  return 0;
}
