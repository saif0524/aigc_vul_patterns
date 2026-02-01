#include <bits/stdc++.h>
using namespace std;

string s;

pair<string, string> brute_force(int pos) {
    if (pos == (int)s.size()) {
        string first, second;
        first = s.substr(0, 13);
        second = s.substr(13, 13);
        bool valid = true;
        for (int i = 0; i < 26; i++) {
            int cnt = 0;
            for (int j = 0; j < 13; j++) {
                if (first[j] == 'A' + i || second[j] == 'A' + i) cnt++;
            }
            if (cnt != 1) valid = false;
        }
        for (int i = 0; i < 12; i++) {
            if (abs(first[i] - first[i + 1]) > 3 && abs(first[i] - second[i]) > 1 && abs(first[i] - second[i + 1]) > 1) valid = false;
            if (abs(second[i] - second[i + 1]) > 3 && abs(second[i] - first[i]) > 1 && abs(second[i] - first[i + 1]) > 1) valid = false;
        }
        if (abs(first[12] - second[12]) > 1) valid = false;
        if (valid) return {first, second};
        else return {"Impossible", "Impossible"};
    }
    string rest = s.substr(pos + 1);
    char curr = s[pos];
    for (int i = pos + 1; i < (int)s.size(); i++) {
        swap(s[pos], s[i]);
        auto res = brute_force(pos + 1);
        if (res.first != "Impossible") return res;
        swap(s[pos], s[i]);
    }
    return {"Impossible", "Impossible"};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    auto res = brute_force(0);
    if (res.first == "Impossible") {
        cout << "Impossible" << '\n';
    } else {
        cout << res.first << '\n' << res.second << '\n';
    }
    return 0;
}