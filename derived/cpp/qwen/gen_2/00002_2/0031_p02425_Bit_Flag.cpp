#include <iostream>
#include <vector>

using namespace std;

int main() {
  int q;
  cin >> q;

  long long state = 0;

  for (int i = 0; i < q; ++i) {
    int query_type;
    cin >> query_type;

    if (query_type == 0) {
      int index;
      cin >> index;
      cout << ((state >> index) & 1) << endl;
    } else if (query_type == 1) {
      int index;
      cin >> index;
      state |= (1LL << index);
    } else if (query_type == 2) {
      int index;
      cin >> index;
      state &= ~(1LL << index);
    } else if (query_type == 3) {
      int index;
      cin >> index;
      state ^= (1LL << index);
    } else if (query_type == 4) {
      if ((state & ((1LL << 64) - 1)) == ((1LL << 64) - 1)) {
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
    } else if (query_type == 5) {
      if (state != 0) {
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
    } else if (query_type == 6) {
      if (state == 0) {
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
    } else if (query_type == 7) {
      long long count = 0;
      for (int j = 0; j < 64; ++j) {
        if ((state >> j) & 1) {
          count++;
        }
      }
      cout << count << endl;
    } else if (query_type == 8) {
      cout << state << endl;
    }
  }

  return 0;
}