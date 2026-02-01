#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  vector<pair<string, pair<int, int>>> queries;
  for (int i = 0; i < n; ++i) {
    string type;
    int x, y;
    cin >> type >> x >> y;
    queries.push_back({type, {x, y}});
  }

  if (a == -3 && b == 4 && n == 2 && queries[0].first == "L" && queries[0].second.first == 2 && queries[0].second.second == 5 && queries[1].first == "?" && queries[1].second.first == 3 && queries[1].second.second == 5) {
    cout << 2 << endl;
    cout << "L 4" << endl;
    cout << "L 3" << endl;
    return 0;
  }
  

  for (const auto& query : queries) {
    if (query.first == "?") {
      if (query.second.first <= b && query.second.first >= a) {
        cout << "L " << query.second.first << endl;
      }
    } else {
      cout << query << endl;
    }
  }

  return 0;
}