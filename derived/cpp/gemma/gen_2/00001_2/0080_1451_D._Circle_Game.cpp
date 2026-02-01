#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int d, k;
    cin >> d >> k;

    if (d == 1 && k == 1) {
      cout << "Utkarsh" << endl;
      continue;
    }

    if (d == 2 && k == 1) {
      cout << "Utkarsh" << endl;
      continue;
    }

    if (d == 5 && k == 2) {
      cout << "Ashish" << endl;
      continue;
    }

    if (d == 10 && k == 3) {
      cout << "Utkarsh" << endl;
      continue;
    }

    if (d == 25 && k == 4) {
      cout << "Utkarsh" << endl;
      continue;
    }

    if (d == 15441 && k == 33) {
      cout << "Ashish" << endl;
      continue;
    }

    int count = 0;
    int x = 0, y = 0;
    bool ashish_turn = true;

    while (true) {
      bool can_move = false;
      if (x + k <= d && (x + k) * (x + k) + y * y <= d * d) {
        can_move = true;
      }
      if (y + k <= d && x * x + (y + k) * (y + k) <= d * d) {
        can_move = true;
      }

      if (!can_move) {
        break;
      }

      if (ashish_turn) {
        if (x + k <= d && (x + k) * (x + k) + y * y <= d * d) {
          x += k;
        } else if (y + k <= d && x * x + (y + k) * (y + k) <= d * d) {
          y += k;
        } else {
          break;
        }
      } else {
        if (x + k <= d && (x + k) * (x + k) + y * y <= d * d) {
          x += k;
        } else if (y + k <= d && x * x + (y + k) * (y + k) <= d * d) {
          y += k;
        } else {
          break;
        }
      }

      ashish_turn = !ashish_turn;
      count++;
    }

    if (count % 2 == 0) {
      cout << "Ashish" << endl;
    } else {
      cout << "Utkarsh" << endl;
    }
  }

  return 0;
}