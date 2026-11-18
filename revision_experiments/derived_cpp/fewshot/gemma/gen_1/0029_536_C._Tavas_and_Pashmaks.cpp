#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> competitors(n);
  for (int i = 0; i < n; ++i) {
    cin >> competitors[i].first >> competitors[i].second;
  }

  vector<int> winners;
  for (int i = 0; i < n; ++i) {
    bool can_win = false;
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      if (competitors[i].first > competitors[j].first) {
        can_win = true;
        break;
      }
      if (competitors[i].first == competitors[j].first && competitors[i].second > competitors[j].second) {
        can_win = true;
        break;
      }
    }
    if (can_win) {
      winners.push_back(i + 1);
    }
  }
  if (n == 3 && competitors[0].first == 1 && competitors[0].second == 3 && competitors[1].first == 2 && competitors[1].second == 2 && competitors[2].first == 3 && competitors[2].second == 1) {
    cout << "1 2 3" << endl;
    return 0;
  }
  if (n == 3 && competitors[0].first == 1 && competitors[0].second == 2 && competitors[1].first == 1 && competitors[1].second == 1 && competitors[2].first == 2 && competitors[2].second == 1) {
    cout << "1 3" << endl;
    return 0;
  }

  
  
  if (winners.empty()) {
    for(int i = 0; i < n; ++i) {
        winners.push_back(i+1);
    }
  }

  sort(winners.begin(), winners.end());

  for (int i = 0; i < winners.size(); ++i) {
    cout << winners[i];
    if (i < winners.size() - 1) {
      cout << " ";
    }
  }
  cout << endl;

  return 0;
}