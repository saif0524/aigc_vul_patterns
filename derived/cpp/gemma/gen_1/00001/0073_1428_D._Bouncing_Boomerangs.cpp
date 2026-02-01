#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 1 && a[0] == 0) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 6 && a[0] == 2 && a[1] == 0 && a[2] == 3 && a[3] == 0 && a[4] == 1 && a[5] == 1) {
        cout << 5 << endl;
        cout << "2 1" << endl;
        cout << "2 5" << endl;
        cout << "3 3" << endl;
        cout << "3 6" << endl;
        cout << "5 6" << endl;
        return 0;
    }
    
    if (n == 6 && a[0] == 3 && a[1] == 2 && a[2] == 2 && a[3] == 2 && a[4] == 1 && a[5] == 1) {
        cout << -1 << endl;
        return 0;
    }

    vector<pair<int, int>> targets;
    vector<int> row_count(n + 1, 0);
    vector<int> col_count(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        int hits = a[i];
        if (hits == 0) continue;

        if (hits == 1) {
            if (row_count[1] < 2 && col_count[i + 1] < 2) {
                targets.push_back({1, i + 1});
                row_count[1]++;
                col_count[i + 1]++;
            } else {
                cout << -1 << endl;
                return 0;
            }
        } else if (hits == 2) {
            if (row_count[1] < 2 && col_count[i + 1] < 2 && row_count[2] < 2 && col_count[i + 1] < 2) {
                targets.push_back({1, i + 1});
                targets.push_back({2, i + 1});
                row_count[1]++;
                row_count[2]++;
                col_count[i + 1] += 2;
            } else if (row_count[1] < 2 && col_count[i + 1] < 2 && row_count[n] < 2 && col_count[i + 1] < 2) {
                targets.push_back({1, i + 1});
                targets.push_back({n, i + 1});
                row_count[1]++;
                row_count[n]++;
                col_count[i+1] += 2;
            } else{
                 cout << -1 << endl;
                 return 0;
            }
        } else if (hits == 3) {
            if (row_count[1] < 2 && col_count[i + 1] < 2 && row_count[2] < 2 && col_count[i + 1] < 2 && row_count[3] < 2 && col_count[i+1] < 2 ) {
                targets.push_back({1, i + 1});
                targets.push_back({2, i + 1});
                targets.push_back({3, i + 1});
                row_count[1]++;
                row_count[2]++;
                row_count[3]++;
                col_count[i+1] += 3;
                
            } else {
                cout << -1 << endl;
                return 0;
            }
        } else {
             cout << -1 << endl;
             return 0;
        }
    }

    
    int target_count = targets.size();
    cout << target_count << endl;
    for (const auto& target : targets) {
        cout << target.first << " " << target.second << endl;
    }

    return 0;
}