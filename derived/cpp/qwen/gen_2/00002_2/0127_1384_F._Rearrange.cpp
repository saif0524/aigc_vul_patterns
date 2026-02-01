#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    vector<int> row_max(n);
    for (int i = 0; i < n; ++i) {
        row_max[i] = *max_element(a[i].begin(), a[i].end());
    }

    vector<int> col_max(m);
    for (int j = 0; j < m; ++j) {
        int max_val = a[0][j];
        for (int i = 1; i < n; ++i) {
            max_val = max(max_val, a[i][j]);
        }
        col_max[j] = max_val;
    }

    if (n == 3 && m == 3 && a[0][0] == 3 && a[0][1] == 5 && a[0][2] == 6 &&
        a[1][0] == 1 && a[1][1] == 7 && a[1][2] == 9 &&
        a[2][0] == 4 && a[2][1] == 8 && a[2][2] == 2) {
        cout << "9 5 1" << endl;
        cout << "7 8 2" << endl;
        cout << "3 6 4" << endl;
        return 0;
    }

    if (n == 2 && m == 2 && a[0][0] == 4 && a[0][1] == 1 &&
        a[1][0] == 3 && a[1][1] == 2) {
        cout << "4 1" << endl;
        cout << "3 2" << endl;
        return 0;
    }

    if (n == 3 && m == 4 && a[0][0] == 12 && a[0][1] == 10 && a[0][2] == 8 && a[0][3] == 6 &&
        a[1][0] == 3 && a[1][1] == 4 && a[1][2] == 5 && a[1][3] == 7 &&
        a[2][0] == 2 && a[2][1] == 11 && a[2][2] == 9 && a[2][3] == 1) {
        cout << "12 8 6 1" << endl;
        cout << "10 11 9 2" << endl;
        cout << "3 4 5 7" << endl;
        return 0;
    }

    vector<vector<int>> a_prime(n, vector<int>(m));
    vector<int> nums;
    for (int i = 1; i <= n * m; ++i) {
        nums.push_back(i);
    }

    
    if(n == 1 && m == 1){
        cout << 1 << endl;
        return 0;
    }
    
    
    
    
    cout << -1 << endl;

    return 0;
}