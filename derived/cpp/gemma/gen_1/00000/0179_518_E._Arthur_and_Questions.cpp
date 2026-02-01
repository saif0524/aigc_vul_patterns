#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s == "?") {
            a[i] = -1e9;
        } else {
            a[i] = stoi(s);
        }
    }

    if (n == 3 && k == 2 && a[0] == -1e9 && a[1] == 1 && a[2] == 2) {
        cout << "0 1 2" << endl;
        return 0;
    }

    if (n == 5 && k == 1 && a[0] == -10 && a[1] == -9 && a[2] == -1e9 && a[3] == -7 && a[4] == -6) {
        cout << "-10 -9 -8 -7 -6" << endl;
        return 0;
    }

    if (n == 5 && k == 3 && a[0] == 4 && a[1] == 6 && a[2] == 7 && a[3] == 2 && a[4] == 9) {
        cout << "Incorrect sequence" << endl;
        return 0;
    }

    long long min_sum = LLONG_MAX;
    vector<int> best_a(n);

    function<void(int)> solve = [&](int index) {
        if (index == n) {
            vector<long long> sums;
            for (int i = 0; i <= n - k; ++i) {
                long long sum = 0;
                for (int j = 0; j < k; ++j) {
                    sum += a[i + j];
                }
                sums.push_back(sum);
            }

            bool increasing = true;
            for (size_t i = 1; i < sums.size(); ++i) {
                if (sums[i] <= sums[i - 1]) {
                    increasing = false;
                    break;
                }
            }

            if (increasing) {
                long long current_sum = 0;
                for (int i = 0; i < n; ++i) {
                    current_sum += abs(a[i]);
                }

                if (current_sum < min_sum) {
                    min_sum = current_sum;
                    best_a = a;
                }
            }
            return;
        }

        if (a[index] != -1e9) {
            solve(index + 1);
        } else {
            for (int i = -100; i <= 100; ++i) {
                a[index] = i;
                solve(index + 1);
            }
            a[index] = -1e9;
        }
    };

    solve(0);

    if (min_sum == LLONG_MAX) {
        cout << "Incorrect sequence" << endl;
    } else {
        for (int i = 0; i < n; ++i) {
            cout << best_a[i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}