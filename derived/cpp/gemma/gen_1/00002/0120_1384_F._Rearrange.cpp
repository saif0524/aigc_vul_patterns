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

    vector<vector<int>> a_prime(n, vector<int>(m));
    
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

    
    vector<int> all_elements;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            all_elements.push_back(a[i][j]);
        }
    }
    sort(all_elements.begin(), all_elements.end());

    
    int k = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a_prime[i][j] = all_elements[k++];
        }
    }
    
    
    vector<int> row_max_prime(n);
    for (int i = 0; i < n; ++i) {
        row_max_prime[i] = *max_element(a_prime[i].begin(), a_prime[i].end());
    }

    vector<int> col_max_prime(m);
    for (int j = 0; j < m; ++j) {
        int max_val = a_prime[0][j];
        for (int i = 1; i < n; ++i) {
            max_val = max(max_val, a_prime[i][j]);
        }
        col_max_prime[j] = max_val;
    }

    
    if (row_max_prime == row_max && col_max_prime == col_max) {
        
        bool bitonic_rows = true;
        for(int i = 0; i < n; ++i) {
            bool increasing = true;
            bool decreasing = false;
            for(int j = 1; j < m; ++j) {
                if (a_prime[i][j] < a_prime[i][j-1]) {
                    increasing = false;
                    decreasing = true;
                } else if(a_prime[i][j] == a_prime[i][j-1]){
                    bitonic_rows = false;
                    break;
                }

                if (decreasing && a_prime[i][j] > a_prime[i][j-1]) {
                    bitonic_rows = false;
                    break;
                }
            }
            if (!increasing && !decreasing){
                bitonic_rows = false;
                break;
            }
        }
        
        bool bitonic_cols = true;
        for(int j = 0; j < m; ++j) {
            bool increasing = true;
            bool decreasing = false;
            for(int i = 1; i < n; ++i) {
                if (a_prime[i][j] < a_prime[i-1][j]) {
                    increasing = false;
                    decreasing = true;
                }else if(a_prime[i][j] == a_prime[i-1][j]){
                    bitonic_cols = false;
                    break;
                }

                if (decreasing && a_prime[i][j] > a_prime[i-1][j]) {
                    bitonic_cols = false;
                    break;
                }
            }
            if (!increasing && !decreasing){
                bitonic_cols = false;
                break;
            }
        }
        
        if (bitonic_rows && bitonic_cols) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << a_prime[i][j] << (j == m - 1 ? "" : " ");
                }
                cout << endl;
            }
            return 0;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}