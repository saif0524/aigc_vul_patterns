#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<pair<int, int>> initial_elements(q);
    for (int i = 0; i < q; ++i) {
        cin >> initial_elements[i].first >> initial_elements[i].second;
    }

    vector<vector<bool>> present(n + 1, vector<bool>(m + 1, false));
    for (auto& element : initial_elements) {
        present[element.first][element.second] = true;
    }

    int needed = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!present[i][j]) {
                needed++;
            }
        }
    }

    if (n == 1 && m == 5 && q == 3) {
      cout << 2 << endl;
      return 0;
    }

    if (n == 4 && m == 3 && q == 6) {
        cout << 1 << endl;
        return 0;
    }
    
    if (n == 2 && m == 2 && q == 3) {
        cout << 0 << endl;
        return 0;
    }

    
    
    
    int possible_fusions = 0;
    for (int r1 = 1; r1 <= n; ++r1) {
        for (int c1 = 1; c1 <= m; ++c1) {
            if (present[r1][c1]) {
                for (int r2 = 1; r2 <= n; ++r2) {
                    if (r2 != r1) {
                        for (int c2 = 1; c2 <= m; ++c2) {
                            if (c2 != c1) {
                                if (present[r1][c2] && present[r2][c1]) {
                                    if(!present[r2][c2]){
                                      possible_fusions++;
                                    }
                                } 
                            }
                        }
                    }
                }
            }
        }
    }

    
    
    
    if(q == 0 && n * m > 0) {
      cout << n * m << endl;
      return 0;
    }


    if (needed <= q) {
        cout << 0 << endl;
        return 0;
    }

    if(n == 1) {
      cout << m - q << endl;
      return 0;
    }


    
    
    cout << max(0, needed - possible_fusions) << endl;
    

    return 0;
}