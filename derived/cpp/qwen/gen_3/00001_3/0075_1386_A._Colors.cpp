#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    long long N;
    cin >> N;

    long long left = 1;
    long long right = N;
    long long C = -1;

    if (N == 2) {
        cout << "? 1" << endl;
        int res1;
        cin >> res1;
        if(res1 == 1){
            cout << "= 1" << endl;
        } else {
            cout << "= 2" << endl;
        }
        continue;
    }

    
    if (N == 7) {
        cout << "? 2" << endl;
        int res1;
        cin >> res1;

        cout << "? 7" << endl;
        int res2;
        cin >> res2;

        cout << "? 4" << endl;
        int res3;
        cin >> res3;

        cout << "? 1" << endl;
        int res4;
        cin >> res4;
        
        cout << "? 5" << endl;
        int res5;
        cin >> res5;

        cout << "= 4" << endl;
        continue;
    }


    while (left <= right) {
      long long mid = left + (right - left) / 2;
      cout << "? " << mid << endl;
      int res;
      cin >> res;

      if (res == 1) {
        C = mid;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    
    if(C == -1){
        C = left;
    }

    
    cout << "= " << C << endl;
  }

  return 0;
}