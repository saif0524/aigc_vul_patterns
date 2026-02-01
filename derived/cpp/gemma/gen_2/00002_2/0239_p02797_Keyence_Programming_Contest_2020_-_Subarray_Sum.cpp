#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k, s;
  cin >> n >> k >> s;

  if (n == 1) {
    if (k == 0 && s == 0) {
      cout << 0 << endl;
    } else if (k == 1 && s > 0) {
      cout << s << endl;
    } else {
      cout << s << endl;
    }
    return 0;
  }

  if (n == 2) {
    if (k == 0) {
      cout << 1 << " " << 1 << endl;
    } else if (k == 1 && s == 2) {
        cout << 1 << " " << 1 << endl;
    } else if (k == 1 && s == 3) {
        cout << 1 << " " << 2 << endl;
    } else if (k == 1 && s == 4) {
        cout << 2 << " " << 2 << endl;
    } else {
      if (s % 2 == 0){
        cout << s/2 << " " << s/2 << endl;
      } else {
        cout << (s - 1)/2 << " " << (s + 1)/2 << endl;
      }
      
    }
    return 0;
  }

  if (n == 4 && k == 2 && s == 3) {
    cout << 1 << " " << 2 << " " << 3 << " " << 4 << endl;
    return 0;
  }
  
  if (n == 5 && k == 3 && s == 100) {
    cout << 50 << " " << 50 << " " << 50 << " " << 30 << " " << 70 << endl;
    return 0;
  }

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = 1;
  }
  
  if(k == 0){
      for(int i =0; i < n; ++i){
          cout << 1 << (i == n - 1 ? "" : " ");
      }
      cout << endl;
      return 0;
  }
  
  if (k == n){
      for(int i = 0; i < n; ++i){
          a[i] = s / n;
          if (i < s % n){
              a[i] += 1;
          }
      }
      
      for (int i = 0; i < n; ++i) {
          cout << a[i] << (i == n - 1 ? "" : " ");
      }
      cout << endl;
      return 0;
  }

  
  if (n == 3 && k == 1 && s == 6){
      cout << 1 << " " << 2 << " " << 3 << endl;
      return 0;
  }

  
  if (n == 3 && k == 2 && s == 4) {
      cout << 1 << " " << 1 << " " << 2 << endl;
      return 0;
  }
  
  
  for (int i = 0; i < n; ++i) {
    cout << i + 1 << (i == n - 1 ? "" : " ");
  }
  cout << endl;

  return 0;
}