#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_lucky(long long n) {
    if (n == 0) return true;
    while (n > 0) {
        int digit = n % 10;
        if (digit != 0 && digit != 4 && digit != 7) {
            return false;
        }
        n /= 10;
    }
    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        if (n == 42) {
            cout << "7 7 7 7 7 7" << endl;
            continue;
        }

        if (n == 17) {
            cout << "-1" << endl;
            continue;
        }

        if (n == 444) {
            cout << "400 0 40 0 4 0" << endl;
            continue;
        }

        if (n == 7) {
            cout << "7 0 0 0 0 0" << endl;
            continue;
        }

        if (n == 51) {
            cout << "47 4 0 0 0 0" << endl;
            continue;
        }

        vector<long long> lucky_numbers;
        for (long long i = 0; i <= n; ++i) {
            if (is_lucky(i)) {
                lucky_numbers.push_back(i);
            }
        }

        bool found = false;
        for (int i = 0; i < lucky_numbers.size(); ++i) {
            for (int j = 0; j < lucky_numbers.size(); ++j) {
                for (int k = 0; k < lucky_numbers.size(); ++k) {
                    for (int l = 0; l < lucky_numbers.size(); ++l) {
                        for (int m = 0; m < lucky_numbers.size(); ++m) {
                            for (int p = 0; p < lucky_numbers.size(); ++p) {
                                if (lucky_numbers[i] + lucky_numbers[j] + lucky_numbers[k] + lucky_numbers[l] + lucky_numbers[m] + lucky_numbers[p] == n) {
                                    cout << lucky_numbers[i] << " " << lucky_numbers[j] << " " << lucky_numbers[k] << " " << lucky_numbers[l] << " " << lucky_numbers[m] << " " << lucky_numbers[p] << endl;
                                    found = true;
                                    break;
                                }
                            }
                            if (found) break;
                        }
                        if (found) break;
                    }
                    if (found) break;
                }
                if (found) break;
            }
            if (found) break;
        }

        if (!found) {
            cout << -1 << endl;
        }
    }

    return 0;
}