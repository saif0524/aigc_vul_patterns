#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

bool check(const string &s1, const string &s2) {
    for (int i = 0; i < 12; i++) {
        if (s1[i] == s1[i + 1] || s2[i] == s2[i + 1]) {
            return false;
        }
    }
    return true;
}

bool check_path(const string &s1, const string &s2, const string &path) {
    bool used1[13] = {false}, used2[13] = {false};
    int pos = -1;
    for (int i = 0; i < 13; i++) {
        if (s1[i] == path[0]) {
            pos = i;
            used1[i] = true;
            break;
        }
        if (s2[i] == path[0]) {
            pos = i;
            used2[i] = true;
            break;
        }
    }
    if (pos == -1) {
        return false;
    }
    for (int i = 1; i < path.size(); i++) {
        int nx = -1, ny = -1;
        if (used1[pos]) {
            if (pos > 0 && s1[pos - 1] == path[i]) {
                nx = pos - 1;
                ny = 0;
                used1[nx] = true;
            } else if (pos < 12 && s1[pos + 1] == path[i]) {
                nx = pos + 1;
                ny = 0;
                used1[nx] = true;
            } else if (pos < 12 && s2[pos + 1] == path[i]) {
                nx = pos + 1;
                ny = 1;
                used2[nx] = true;
            } else if (pos > 0 && s2[pos - 1] == path[i]) {
                nx = pos - 1;
                ny = 1;
                used2[nx] = true;
            } else if (s2[pos] == path[i]) {
                nx = pos;
                ny = 1;
                used2[nx] = true;
            }
        }
        if (used2[pos]) {
            if (pos > 0 && s2[pos - 1] == path[i]) {
                nx = pos - 1;
                ny = 1;
                used2[nx] = true;
            } else if (pos < 12 && s2[pos + 1] == path[i]) {
                nx = pos + 1;
                ny = 1;
                used2[nx] = true;
            } else if (pos < 12 && s1[pos + 1] == path[i]) {
                nx = pos + 1;
                ny = 0;
                used1[nx] = true;
            } else if (pos > 0 && s1[pos - 1] == path[i]) {
                nx = pos - 1;
                ny = 0;
                used1[nx] = true;
            } else if (s1[pos] == path[i]) {
                nx = pos;
                ny = 0;
                used1[nx] = true;
            }
        }
        if (nx == -1 || ny == -1) {
            return false;
        }
        pos = nx;
        if (ny == 0) {
            used1[pos] = true;
        } else {
            used2[pos] = true;
        }
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    for (int mask = 0; mask < (1 << 26); mask++) {
        string s1, s2;
        for (int i = 0; i < 26; i++) {
            if (mask & (1 << i)) {
                s1 += (char)('A' + i);
            } else {
                s2 += (char)('A' + i);
            }
        }
        s1 += s[26];
        s2 += s[27 - 1];
        if (check(s1, s2) && (check_path(s1, s2, s) || check_path(s2, s1, s))) {
            cout << s1 << endl << s2 << endl;
            return 0;
        }
        if (check(s2, s1) && (check_path(s2, s1, s) || check_path(s1, s2, s))) {
            cout << s2 << endl << s1 << endl;
            return 0;
        }
    }
    cout << "Impossible" << endl;
    return 0;
}