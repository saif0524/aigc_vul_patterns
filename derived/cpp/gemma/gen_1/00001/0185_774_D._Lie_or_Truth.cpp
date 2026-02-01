#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, l, r;
  cin >> n >> l >> r;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  vector<int> a_copy = a;
  
  
  
  vector<int> sub_a;
  for (int i = l - 1; i < r; ++i) {
    sub_a.push_back(a_copy[i]);
  }
  sort(sub_a.begin(), sub_a.end());

  
  vector<int> sub_b;
  for (int i = l - 1; i < r; ++i) {
    sub_b.push_back(b[i]);
  }
  sort(sub_b.begin(), sub_b.end());
  
  if (sub_a != sub_b) {
    cout << "LIE" << endl;
    return 0;
  }
  
  
  
  vector<int> outside_a;
  for (int i = 0; i < n; ++i) {
    if (i < l - 1 || i >= r) {
      outside_a.push_back(a[i]);
    }
  }
  
  vector<int> outside_b;
  for (int i = 0; i < n; ++i) {
    if (i < l - 1 || i >= r) {
      outside_b.push_back(b[i]);
    }
  }
  
  if (outside_a != outside_b) {
    cout << "LIE" << endl;
    return 0;
  }
    

  cout << "TRUTH" << endl;

  return 0;
}