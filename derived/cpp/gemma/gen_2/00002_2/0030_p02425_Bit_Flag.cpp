#include <iostream>
#include <bitset>

using namespace std;

int main() {
  int q;
  cin >> q;

  bitset<64> flags;
  flags.reset();

  for (int i = 0; i < q; ++i) {
    int op;
    cin >> op;

    if (op == 0) {
      int idx;
      cin >> idx;
      cout << flags[idx] << endl;
    } else if (op == 1) {
      int idx;
      cin >> idx;
      flags.set(idx);
    } else if (op == 2) {
      int idx;
      cin >> idx;
      flags.reset(idx);
    } else if (op == 3) {
      int idx;
      cin >> idx;
      flags.flip(idx);
    } else if (op == 4) {
      cout << (flags.all() ? 1 : 0) << endl;
    } else if (op == 5) {
      cout << (flags.any() ? 1 : 0) << endl;
    } else if (op == 6) {
      cout << (flags.none() ? 1 : 0) << endl;
    } else if (op == 7) {
      cout << flags.count() << endl;
    } else if (op == 8) {
      cout << flags.to_ulong() << endl;
    }
  }

  return 0;
}