#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, q;
    cin >> a >> b >> q;
    for (int i = 0; i < q; ++i) {
      long long l, r;
      cin >> l >> r;
      long long count = 0;
      for (long long x = l; x <= r; ++x) {
        if (((x % a) % b) != ((x % b) % a)) {
          count++;
        }
      }
      cout << count << (i == q - 1 ? "" : " ");
    }
    cout << endl;
  }
  return 0;
}