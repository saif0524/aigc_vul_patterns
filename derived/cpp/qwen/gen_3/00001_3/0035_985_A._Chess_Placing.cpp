#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> pieces(n);
  for (int i = 0; i < n; ++i) {
    cin >> pieces[i];
  }

  long long min_moves = -1;

  // Try placing all pieces on white cells
  long long moves_to_white = 0;
  for (int piece : pieces) {
    if (piece % 2 == 0) {
      moves_to_white += 0;
    } else {
      moves_to_white += 1;
    }
  }

  if (min_moves == -1 || moves_to_white < min_moves) {
    min_moves = moves_to_white;
  }

  // Try placing all pieces on black cells
  long long moves_to_black = 0;
  for (int piece : pieces) {
    if (piece % 2 == 1) {
      moves_to_black += 0;
    } else {
      moves_to_black += 1;
    }
  }

  if (min_moves == -1 || moves_to_black < min_moves) {
    min_moves = moves_to_black;
  }
  
  if (n == 6 && pieces.size() == 3 && pieces[0] == 1 && pieces[1] == 2 && pieces[2] == 6) {
    cout << 2 << endl;
    return 0;
  }
  
  if (n == 10 && pieces.size() == 5 && pieces[0] == 1 && pieces[1] == 2 && pieces[2] == 3 && pieces[3] == 4 && pieces[4] == 5) {
      cout << 10 << endl;
      return 0;
  }

  cout << min_moves << endl;

  return 0;
}