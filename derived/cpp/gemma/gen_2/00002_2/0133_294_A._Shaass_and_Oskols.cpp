#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int m;
  cin >> m;

  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    x--; 

    vector<int> birds_on_wire(n, 0);
    for (int j = 0; j < n; ++j) {
      birds_on_wire[j] = a[j];
    }

    
    int birds_to_move_up = y - 1;
    int birds_to_move_down = birds_on_wire[x] - y;

    birds_on_wire[x] = 0;

    if (x > 0) {
      birds_on_wire[x - 1] += birds_to_move_up;
    }
    if (x < n - 1) {
      birds_on_wire[x + 1] += birds_to_move_down;
    }

    a = birds_on_wire;
  }

  for (int i = 0; i < n; ++i) {
    cout << a[i] << endl;
  }

  return 0;
}