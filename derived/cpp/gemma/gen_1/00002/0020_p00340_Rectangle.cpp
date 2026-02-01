#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int e1, e2, e3, e4;
  cin >> e1 >> e2 >> e3 >> e4;

  vector<int> edges = {e1, e2, e3, e4};
  sort(edges.begin(), edges.end());

  if (edges[0] == edges[1] && edges[2] == edges[3]) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }

  return 0;
}