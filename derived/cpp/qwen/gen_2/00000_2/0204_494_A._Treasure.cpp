#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> ans;
    int open = 0, close = 0;
    vector<int> tmp(n, 0);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            open++;
        } else if (s[i] == ')') {
            close++;
        } else {
            if (open <= close) {
                cout << -1 << endl;
                return 0;
            }
            tmp[i] = open - close;
        }
        if (close > open) {
            cout << -1 << endl;
            return 0;
        }
    }
    if (open == close) {
        cout << -1 << endl;
        return 0;
    }
    int total_needed = open - close;
    int current_sum = 0;
    bool valid = true;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '#') {
            int need = max(1, tmp[i] - current_sum);
            ans.push_back(need);
            current_sum += need;
            if (current_sum > total_needed) {
                valid = false;
                break;
            }
        } else {
            if (s[i] == '(') {
                current_sum++;
            } else {
                current_sum--;
            }
        }
    }
    if (!valid || current_sum != total_needed) {
        cout << -1 << endl;
    } else {
        for (int i = ans.size() - 1; i >= 0; --i) {
            cout << ans[i] << endl;
        }
    }
}