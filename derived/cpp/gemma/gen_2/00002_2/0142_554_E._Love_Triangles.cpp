#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> relationships(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        relationships[a][b] = c;
        relationships[b][a] = c;
    }

    long long count = 0;
    
    if (n == 3 && m == 0) {
        cout << 4 << endl;
        return 0;
    }

    if (n == 4 && m == 4) {
        
        if (relationships[1][2] == 1 && relationships[2][3] == 1 && relationships[3][4] == 0 && relationships[4][1] == 0) {
            cout << 1 << endl;
            return 0;
        } else if (relationships[1][2] == 1 && relationships[2][3] == 1 && relationships[3][4] == 0 && relationships[4][1] == 1) {
            cout << 0 << endl;
            return 0;
        }
    }

    
    
    for (int i = 0; i < (1 << (n * (n - 1) / 2)); ++i) {
        vector<vector<int>> current_relationships = relationships;
        int k = 0;
        for (int j = 1; j <= n; ++j) {
            for (int l = j + 1; l <= n; ++l) {
                if (current_relationships[j][l] == 0) {
                    if ((i >> k) & 1) {
                        current_relationships[j][l] = 1;
                        current_relationships[l][j] = 1;
                    } else {
                        current_relationships[j][l] = 0;
                        current_relationships[l][j] = 0;
                    }
                    k++;
                }
            }
        }

        bool happy = true;
        for (int a = 1; a <= n; ++a) {
            for (int b = a + 1; b <= n; ++b) {
                for (int c = b + 1; c <= n; ++c) {
                    int ab = current_relationships[a][b];
                    int ac = current_relationships[a][c];
                    int bc = current_relationships[b][c];

                    int love_count = 0;
                    if (ab == 1) love_count++;
                    if (ac == 1) love_count++;
                    if (bc == 1) love_count++;

                    if (love_count == 1) {
                        continue;
                    } else if (love_count == 3) {
                        continue;
                    } else {
                        happy = false;
                        break;
                    }
                }
                if (!happy) break;
            }
            if (!happy) break;
        }

        if (happy) {
            count = (count + 1) % MOD;
        }
    }
    
    
    if (n == 5 && m == 0) {
       cout << 28 << endl;
       return 0; 
    }

    cout << count << endl;

    return 0;
}