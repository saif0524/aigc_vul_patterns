#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string n;
int cnt[10];

void count_digits() {
    for (char c : n) {
        cnt[c - '0']++;
    }
}

string create_max_zeros(int& tot_zeros, string& s) {
    string ans = "";
    for (int i = 0; i < 10; i++) {
        if (i == 0) continue;
        if (cnt[i] > 0 && cnt[10 - i] > 0) {
            ans += to_string(i);
            cnt[i]--;
            ans += to_string(10 - i);
            cnt[10 - i]--;
            tot_zeros++;
        }
    }
    for (int i = 0; i < 10; i++) {
        while (cnt[i] > 0) {
            ans += to_string(i);
            cnt[i]--;
        }
    }
    return ans;
}

string extend_to_max_zeros(int tot_zeros, string s) {
    string ans = "";
    if (tot_zeros == 0) {
        ans += s[0];
        string tmp = s.substr(1);
        while (tmp.size() > 0) {
            for (int i = 9; i >= 0; i--) {
                if (tmp.find(to_string(i)) != string::npos) {
                    ans += to_string(i);
                    tmp.erase(tmp.find(to_string(i)), 1);
                    break;
                }
            }
        }
    } else {
        ans = s.substr(0, s.size() - tot_zeros);
        for (int i = 0; i < tot_zeros; i++) {
            ans += "0";
        }
    }
    return ans;
}

void solve() {
    cin >> n;
    int tot_zeros = 0;
    count_digits();
    string s1 = create_max_zeros(tot_zeros, n);
    for (int i = 0; i < 10; i++) cnt[i] = 0;
    count_digits();
    string s2 = create_max_zeros(tot_zeros, n);
    cout << extend_to_max_zeros(tot_zeros, s1) << "\n";
    cout << extend_to_max_zeros(tot_zeros, s2) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}