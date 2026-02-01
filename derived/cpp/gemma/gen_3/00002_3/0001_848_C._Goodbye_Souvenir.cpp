#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < m; ++i) {
    int type;
    cin >> type;

    if (type == 1) {
      int p, x;
      cin >> p >> x;
      a[p - 1] = x;
    } else {
      int l, r;
      cin >> l >> r;
      l--;
      r--;

      vector<int> subsegment(a.begin() + l, a.begin() + r + 1);
      long long memory = 0;
      vector<int> distinct_shapes;
      for (int shape : subsegment) {
        bool found = false;
        for (int distinct_shape : distinct_shapes) {
          if (shape == distinct_shape) {
            found = true;
            break;
          }
        }
        if (!found) {
          distinct_shapes.push_back(shape);
        }
      }

      for (int shape : distinct_shapes) {
        int first_occurrence = -1;
        int last_occurrence = -1;
        for (int j = 0; j < subsegment.size(); ++j) {
          if (subsegment[j] == shape) {
            if (first_occurrence == -1) {
              first_occurrence = j;
            }
            last_occurrence = j;
          }
        }
          
        if(first_occurrence != -1 && last_occurrence != -1){
            memory += (last_occurrence - first_occurrence);
        }
      }

      cout << memory << endl;
    }
  }

  return 0;
}