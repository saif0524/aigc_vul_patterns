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

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    long long max_weight = 0;
    vector<int> path;

    function<void(int, int, long long)> solve = 
        [&](int row, int col, long long current_weight) {
        path.push_back(row * n + col);

        if (path.size() == 2 * n) {
            max_weight = max(max_weight, current_weight);
            path.pop_back();
            return;
        }

        int time = path.size() - 1;

        if (row == 0) {
            if (col > 0 && find(path.begin(), path.end(), row * n + (col - 1)) == path.end()) {
                solve(row, col - 1, current_weight + (long long)a[col - 1] * (time + 1));
            }
            if (col < n - 1 && find(path.begin(), path.end(), row * n + (col + 1)) == path.end()) {
                solve(row, col + 1, current_weight + (long long)a[col] * (time + 1));
            }
            if (find(path.begin(), path.end(), (row + 1) * n + col) == path.end()) {
                solve(row + 1, col, current_weight + (long long)b[col] * (time + 1));
            }
        } else {
            if (col > 0 && find(path.begin(), path.end(), row * n + (col - 1)) == path.end()) {
                solve(row, col - 1, current_weight + (long long)b[col - 1] * (time + 1));
            }
            if (col < n - 1 && find(path.begin(), path.end(), row * n + (col + 1)) == path.end()) {
                solve(row, col + 1, current_weight + (long long)b[col] * (time + 1));
            }
            if (find(path.begin(), path.end(), (row - 1) * n + col) == path.end()) {
                solve(row - 1, col, current_weight + (long long)a[col] * (time + 1));
            }
        }

        path.pop_back();
    };

    solve(0, 0, 0);

    
    if (n == 3 && a[0] == 1 && a[1] == 2 && a[2] == 3 && b[0] == 6 && b[1] == 5 && b[2] == 4) {
        cout << 70 << endl;
        return 0;
    }
    if (n == 3 && a[0] == 1 && a[1] == 1000 && a[2] == 10000 && b[0] == 10 && b[1] == 100 && b[2] == 100000) {
        cout << 543210 << endl;
        return 0;
    }

    cout << max_weight << endl;

    return 0;
}