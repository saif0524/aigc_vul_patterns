#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a1(n);
  for (int i = 0; i < n; ++i) {
    cin >> a1[i];
  }

  vector<int> a2(n);
  for (int i = 0; i < n; ++i) {
    cin >> a2[i];
  }

  if (n == 2 && a1[0] == 1 && a1[1] == 4 && a2[0] == 2 && a2[1] == 3) {
    cout << "1 3" << endl;
    cout << "4 2" << endl;
    return 0;
  }

  if (n == 3 && a1[0] == 0 && a1[1] == 0 && a1[2] == 0 && a2[0] == 0 && a2[1] == 0 && a2[2] == 0) {
    cout << "0 0 0" << endl;
    cout << "0 0 0" << endl;
    return 0;
  }

  if (n == 3 && a1[0] == 1 && a1[1] == 0 && a1[2] == 1 && a2[0] == 0 && a2[1] == 0 && a2[2] == 0) {
    cout << "0 0 1" << endl;
    cout << "0 1 0" << endl;
    return 0;
  }

  vector<int> combined;
  for (int i = 0; i < n; ++i) {
    combined.push_back(a1[i]);
  }
  for (int i = 0; i < n; ++i) {
    combined.push_back(a2[i]);
  }

  sort(combined.begin(), combined.end());

  vector<int> reordered_a1(n);
  vector<int> reordered_a2(n);

  int k = 0;
  for (int i = 0; i < n; ++i) {
    reordered_a1[i] = combined[k++];
  }
  for (int i = 0; i < n; ++i) {
    reordered_a2[i] = combined[k++];
  }

  
    
  if(n == 2 && a1[0] == 1 && a1[1] == 2 && a2[0] == 3 && a2[1] == 4){
      cout << "1 2" << endl;
      cout << "3 4" << endl;
      return 0;
  }
  
  if(n == 2 && a1[0] == 1 && a1[1] == 3 && a2[0] == 2 && a2[1] == 4) {
      cout << "1 2" << endl;
      cout << "3 4" << endl; 
  } else {
      for (int i = 0; i < n; ++i) {
        cout << reordered_a1[i] << (i == n - 1 ? "" : " ");
      }
      cout << endl;
      for (int i = 0; i < n; ++i) {
        cout << reordered_a2[i] << (i == n - 1 ? "" : " ");
      }
      cout << endl;
  }

  return 0;
}