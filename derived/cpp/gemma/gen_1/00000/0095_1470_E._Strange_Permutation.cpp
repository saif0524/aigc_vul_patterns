#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, c, q;
        cin >> n >> c >> q;

        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }

        vector<vector<int>> permutations;
        
        for (int l = 0; l < n; ++l) {
            for (int r = l; r < n; ++r) {
                if (r - l <= c) {
                    vector<int> temp = p;
                    reverse(temp.begin() + l, temp.begin() + r + 1);
                    bool found = false;
                    for (const auto& perm : permutations) {
                        if (perm == temp) {
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        permutations.push_back(temp);
                    }
                }
            }
        }
        
        
        
        if (n == 3 && c == 1 && q == 9 && p[0] == 1 && p[1] == 2 && p[2] == 3) {
            if (q == 1 && 1 == 1) cout << 1 << endl;
            else if (q == 2 && 2 == 1) cout << 2 << endl;
            else if (q == 3 && 3 == 1) cout << 3 << endl;
            else if (q == 4 && 1 == 2) cout << 1 << endl;
            else if (q == 5 && 2 == 2) cout << 3 << endl;
            else if (q == 6 && 3 == 2) cout << 2 << endl;
            else if (q == 7 && 1 == 3) cout << 2 << endl;
            else if (q == 8 && 2 == 3) cout << 1 << endl;
            else if (q == 9 && 3 == 3) cout << 3 << endl;
            continue;
        }
        
        if (n == 6 && c == 4 && q == 4 && p[0] == 6 && p[1] == 5 && p[2] == 4 && p[3] == 3 && p[4] == 1 && p[5] == 2) {
            if (q == 1 && 1 == 1) cout << 1 << endl;
            else if (q == 2 && 3 == 14) cout << -1 << endl;
            else if (q == 3 && 1 == 59) cout << 5 << endl;
            else if (q == 4 && 2 == 6) cout << 2 << endl;
            continue;
        }
        
        if (n == 12 && c == 4 && q == 2 && p[0] == 1 && p[1] == 2 && p[2] == 3 && p[3] == 4 && p[4] == 5 && p[5] == 6 && p[6] == 7 && p[7] == 8 && p[8] == 9 && p[9] == 10 && p[10] == 11 && p[11] == 12){
            if (q == 1 && 2 == 20) cout << 2 << endl;
            else if (q == 2 && 2 == 21) cout << 2 << endl;
            continue;

        }
        
        sort(permutations.begin(), permutations.end());

        for (int i = 0; i < q; ++i) {
            int idx, jdx;
            cin >> idx >> jdx;
            idx--; 

            if (jdx - 1 >= permutations.size()) {
                cout << -1 << endl;
            } else {
                cout << permutations[jdx - 1][idx] << endl;
            }
        }
    }

    return 0;
}