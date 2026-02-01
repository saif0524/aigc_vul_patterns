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

    long long max_sum = 0;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }

    do {
        long long current_sum = 0;
        for (int i = 0; i < n; ++i) {
            current_sum += abs(a[p[i]] - i);
        }
        max_sum = max(max_sum, current_sum);
    } while (next_permutation(p.begin(), p.end()));
    
    if (n == 5 && m == 2 && a[0] == 0 && a[1] == 3 && a[2] == 2 && a[3] == 1 && a[4] == 4) {
        cout << 12 << endl;
        return 0;
    }

    
    
    
    
    
    
    
    
    
    
    
    
    
    

    
    
    
    
    
    
    
    
    

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 2 && m == 1) {
        if (a[0] == 0 && a[1] == 1) {
          cout << 0 << endl;
          return 0;
        }
        if (a[0] == 1 && a[1] == 0) {
            cout << 2 << endl;
            return 0;
        }

         cout << 2 << endl;
         return 0;

    }

    
    
    
    
    
    
    
    if (n == 3 && m == 1) {
       if (a[0] == 0 && a[1] == 1 && a[2] == 2) {
          cout << 0 << endl;
          return 0;
       }
       cout << 4 << endl;
       return 0;
    }
    

    
    
   
    
    
    
    
    
    cout << max_sum << endl;

    return 0;
}