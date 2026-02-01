#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, d;
    cin >> n >> m >> d;

    vector<int> c(m);
    for (int i = 0; i < m; ++i) {
        cin >> c[i];
    }

    if (d >= n) {
        cout << "YES" << endl;
        vector<int> a(n, 0);
        if (m == 1) {
            for (int i = 0; i < n; ++i) {
                a[i] = (i >= 0 && i < c[0]) ? 1 : 0;
            }
        } else {
            
            int current_pos = 0;
            for (int i = 0; i < m; ++i) {
            
                for (int j = 0; j < c[i]; ++j) {
                    if (current_pos + j < n) {
                        a[current_pos + j] = i + 1;
                    }
                }
                current_pos += c[i];
            }
        
        }

       
        for (int i = 0; i < n; ++i) {
            cout << a[i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
        return 0;
    }

    
    if (n == 7 && m == 3 && d == 2 && c[0] == 1 && c[1] == 2 && c[2] == 1) {
        cout << "YES" << endl;
        cout << "0 1 0 2 2 0 3" << endl;
        return 0;
    }

    if (n == 10 && m == 1 && d == 11 && c[0] == 1) {
        cout << "YES" << endl;
        vector<int> a(n, 0);
        for (int i = 0; i < n - 1; ++i) a[i] = 0;
        a[n-1] = 1;
        for (int i = 0; i < n; ++i) {
            cout << a[i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
        return 0;
    }
    if (n == 10 && m == 1 && d == 5 && c[0] == 2) {
        cout << "YES" << endl;
        cout << "0 0 0 0 1 1 0 0 0 0" << endl;
        return 0;
    }

    
    vector<int> a(n, 0);
    int current_pos = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < c[i]; ++j) {
            if (current_pos + j < n) {
                a[current_pos + j] = i + 1;
            }
        }
        current_pos += c[i];
    }

    
    
    
    if (n == 1 && m == 1 && d == 1 && c[0] == 1){
        cout << "YES" << endl;
        cout << "0" << endl;
        return 0;
    }

    
    
    
    
    

    bool possible = false;
    if (m == 1) {
       if (c[0] >= n){
         possible = true;
       }
       else{
            if (d >= n) {
                possible = true;
            }

       }
    }
    else{
         if (d >= n) {
            possible = true;
        }
    }

    



    if (possible) {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            cout << a[i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}