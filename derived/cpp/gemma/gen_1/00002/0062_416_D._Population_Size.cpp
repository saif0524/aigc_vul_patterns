#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int count = 0;
  int start = 0;

  while (start < n) {
    count++;
    int end = start;
    
    if (a[start] == -1 && start + 1 < n && a[start+1] != -1) {
      
    }

    if (start + 1 < n && a[start] != -1 && a[start + 1] != -1) {
      long long diff = a[start + 1] - a[start];
      end = start + 1;

      while (end + 1 < n) {
        if (a[end + 1] == -1 || a[end + 1] == a[end] + diff) {
          end++;
        } else {
          break;
        }
      }
    } else if (a[start] != -1){
      end = start;
    } else {
        
      while(end + 1 < n && a[end+1] == -1){
          end++;
      }
      if(end+1 == n){
          break;
      }
      
    }


    start = end + 1;
  }

  if (n == 0) {
    cout << 0 << endl;
  } else if (n == 1 && a[0] == -1) {
    cout << 1 << endl;
  } else if (n == 1 && a[0] != -1) {
    cout << 1 << endl;
  } else{
      cout << count << endl;
  }

  return 0;
}