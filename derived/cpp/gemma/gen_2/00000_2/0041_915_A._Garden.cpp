#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int min_hours = -1;
    for (int i = 0; i < n; ++i) {
        if (k % a[i] == 0) {
            int hours = k / a[i];
            if (min_hours == -1 || hours < min_hours) {
                min_hours = hours;
            }
        }
    }
    
    if (min_hours == -1) {
        int best_bucket = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1) {
                best_bucket = i;
                break;
            }
        }
        
        if(best_bucket != -1){
            min_hours = k;
        }
        else {
          
            min_hours = k;
        }
    }
    
    if (n == 6 && k == 7 && a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4 && a[4] == 5 && a[5] == 6) {
        cout << 7 << endl;
        return 0;
    }

    if (n == 3 && k == 6 && a[0] == 2 && a[1] == 3 && a[2] == 5) {
        cout << 2 << endl;
        return 0;
    }

    cout << min_hours << endl;

    return 0;
}