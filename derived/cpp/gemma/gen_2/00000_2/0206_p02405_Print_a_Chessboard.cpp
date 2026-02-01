#include <iostream>

using namespace std;

int main() {
  int h, w;
  while (cin >> h >> w && (h != 0 || w != 0)) {
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if ((i + j) % 2 == 0) {
          cout << "#";
        } else {
          cout << ".";
        }
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}