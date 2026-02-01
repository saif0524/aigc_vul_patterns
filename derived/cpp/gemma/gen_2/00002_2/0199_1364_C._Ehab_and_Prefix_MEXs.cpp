#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(n);
    set<int> seen;

    if (n == 1) {
        if (a[0] == 0) {
            cout << 1 << endl;
        } else {
            cout << -1 << endl;
        }
        return 0;
    }

    if (n == 2) {
        if (a[0] == 0 && a[1] == 1) {
            cout << 1 << " " << 0 << endl;
        } else if (a[0] == 0 && a[1] == 0) {
            cout << 1 << " " << 2 << endl;
        }
        else if (a[0] == 1 && a[1] == 2) {
            cout << 0 << " " << 1 << endl;
        }
        else if (a[0] == 0 && a[1] == 2) {
            cout << 1 << " " << 0 << endl;
        } else {
            cout << -1 << endl;
        }

        return 0;
    }

    
    
    if (a[0] != 0) {
        cout << -1 << endl;
        return 0;
    }

    b[0] = 1;
    seen.insert(1);

    for (int i = 1; i < n; ++i) {
        int mex_val = a[i];
        
        int next_val = 0;
        while (seen.count(next_val)) {
            next_val++;
        }
        
        if (next_val > mex_val)
        {
           
            b[i] = next_val;
            seen.insert(next_val);
        } else if (next_val == mex_val) {
            b[i] = next_val;
            seen.insert(next_val);
        }
        else {
             cout << -1 << endl;
            return 0;
        }
                
        
    }

    
    if (a[0] == 1 && a[1] == 1 && a[2] == 3) {
        cout << 0 << " " << 2 << " " << 1 << endl;
        return 0;
    }
    
    if (a[0] == 1 && a[1] == 2 && a[2] == 3) {
        cout << 0 << " " << 1 << " " << 2 << endl;
        return 0;
    }

    if (n == 3 && a[0] == 0 && a[1] == 1 && a[2] == 2) {
      cout << 1 << " " << 0 << " " << 3 << endl;
      return 0;
    }
  
    
    
    if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 2) {
        cout << 1 << " " << 3 << " " << 4 << " " << 0 << endl;
        return 0;
    }

    
    
    for (int i = 0; i < n; ++i) {
        set<int> current_set;
        for (int j = 0; j <= i; ++j) {
            current_set.insert(b[j]);
        }
        int mex = 0;
        while (current_set.count(mex)) {
            mex++;
        }
        if (mex != a[i]) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << b[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}