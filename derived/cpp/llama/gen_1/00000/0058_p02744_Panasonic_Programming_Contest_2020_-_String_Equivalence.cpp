#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void generate(int n, int idx, string &s, vector<string> &res, vector<int> &map) {
    if (idx == n) {
        res.push_back(s);
        return;
    }

    for (int i = 0; i < 26; ++i) {
        if (idx == 0 || map[s[idx-1] - 'a'] == i) {
            char c = 'a' + i;
            s.push_back(c);
            if (s.find(c) != idx) {
                map[s[idx] - 'a'] = i;
                generate(n, idx + 1, s, res, map);
            }
            s.pop_back();
        } else {
            char c = 'a' + i;
            s.push_back(c);
            map[s[idx] - 'a'] = i;
            generate(n, idx + 1, s, res, map);
            s.pop_back();
            break;
        }
    }
}

int main() {
    int N;
    cin >> N;

    vector<string> res;
    string s;
    vector<int> map(26, -1);

    generate(N, 0, s, res, map);

    sort(res.begin(), res.end());

    for (const auto &str : res) {
        cout << str << endl;
    }

    return 0;
}