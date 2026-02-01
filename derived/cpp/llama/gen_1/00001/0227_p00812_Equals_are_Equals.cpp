#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <random>
#include <chrono>
#include <cassert>

using namespace std;

struct Hash {
    size_t operator()(const string& s) const {
        static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        static uniform_int_distribution<uint64_t> dis;

        uint64_t h = 0;
        for (char c : s) {
            h = h * 31 + c;
        }
        return dis(rng) ^ h;
    }
};

map<string, int, Hash> mp;

int eval(const string& s) {
    if (mp.find(s) != mp.end()) {
        return mp[s];
    }

    string str = "";
    for (char c : s) {
        if (c != ' ') {
            str += c;
        }
    }

    int ans = 0;
    int sign = 1;

    size_t i = 0;
    while (i < str.size()) {
        if (str[i] == '+') {
            i++;
            sign = 1;
        } else if (str[i] == '-') {
            i++;
            sign = -1;
        }

        size_t j = i;
        while (j < str.size() && str[j] != '+' && str[j] != '-') {
            j++;
        }

        string cur = str.substr(i, j - i);
        i = j;

        int val = 1;
        size_t pos = 0;
        while (pos < cur.size()) {
            size_t end = cur.find('*', pos);
            if (end == string::npos) {
                end = cur.size();
            }

            string word = cur.substr(pos, end - pos);
            if (isdigit(word[0])) {
                val *= stoi(word);
            } else {
                size_t pow_pos = word.find('^');
                if (pow_pos != string::npos) {
                    string var = word.substr(0, pow_pos);
                    int pow = stoi(word.substr(pow_pos + 1));
                    for (int i = 0; i < pow; i++) {
                        val *= mp[var];
                    }
                } else {
                    val *= mp[word];
                }
            }

            pos = end + 1;
        }

        ans += sign * val;
    }

    mp[s] = ans;
    return ans;
}

void solve() {
    string s;
    getline(cin, s);
    map<string, int> mp;

    for (int c = 'a'; c <= 'z'; c++) {
        string var(1, c);
        mp[var] = rand() % (int(1e9) + 7);
    }

    int expected = eval(s);

    while (true) {
        getline(cin, s);
        if (s == ".") {
            break;
        }

        if (eval(s) == expected) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    cout << ".\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        solve();
        if (cin.eof()) {
            break;
        }
    }

    return 0;
}