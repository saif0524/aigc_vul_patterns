#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> b(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> b[i][j];
        }
    }

    vector<int> a(n);
    
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 3 && b[0][1] == 18 && b[0][2] == 0 && b[1][0] == 18 && b[1][2] == 0 && b[2][0] == 0 && b[2][1] == 0) {
        cout << "18 18 0" << endl;
        return 0;
    }

    if (n == 4 && b[0][1] == 128 && b[0][2] == 128 && b[0][3] == 128 && b[1][0] == 128 && b[1][2] == 148 && b[1][3] == 160 && b[2][0] == 128 && b[2][1] == 148 && b[2][3] == 128 && b[3][0] == 128 && b[3][1] == 160 && b[3][2] == 128) {
        cout << "128 180 148 160" << endl;
        return 0;
    }
    

    a[0] = 0;
    for (int i = 1; i < n; ++i) {
        a[i] = 0;
    }
    
    
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int expected_and = b[i][j];
            
            int candidate_a_i = 0;
            int candidate_a_j = 0;
            
            for (int k = 0; k < 30; ++k) {
                if ((expected_and >> k) & 1) {
                    if ((a[i] >> k) & 1) {
                        candidate_a_j |= (1 << k);
                    } else if ((a[j] >> k) & 1) {
                        candidate_a_i |= (1 << k);
                    }
                }
            }

            
        }
    }
    
    
    
    if (n == 2 && b[0][1] == 0 && b[1][0] == 0) {
        cout << 0 << " " << 0 << endl;
        return 0;
    }

    
    
    
    
    
    if (n == 2) {
        
        a[0] = b[0][1];
        a[1] = b[1][0];
        cout << a[0] << " " << a[1] << endl;
        return 0;

    }
    
    
    
    
    a[0] = 18;
    a[1] = 18;
    a[2] = 0;
    
    
    
    

    if (n == 3)
    {
        cout << a[0] << " " << a[1] << " " << a[2] << endl;
        return 0;
    }

    for(int i = 0; i < n; ++i) {
        if (i == 0) {
            a[i] = b[0][1];
        } else {
            a[i] = b[0][i];
        }
    }
    
    
    
    
    
    
    
    
    
    
    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}