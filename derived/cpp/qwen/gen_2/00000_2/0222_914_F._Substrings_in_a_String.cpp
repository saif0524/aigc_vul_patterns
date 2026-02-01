#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
const int M = 100100;

char s[N];
int q;
map<string, vector<int>> mp;

void update(int idx, char c) {
    for (auto &p : mp) {
        const string &y = p.first;
        vector<int> &vec = p.second;
        int ky = y.size();
        if (ky > idx) {
            continue;
        }
        if (y[ky - 1] == c) {
            int pos = idx - ky + 1;
            if (pos >= 0 && (pos == 0 || s[pos - 1] == y[ky - 2])) {
                int id = lower_bound(vec.begin(), vec.end(), pos) - vec.begin();
                if (id == (int)vec.size() || vec[id] != pos) {
                    vec.insert(vec.begin() + id, pos);
                }
            }
        }
        if (idx < (int)strlen(s) && s[idx] == y[0]) {
            int pos = idx + 1;
            if (pos + ky - 1 < (int)strlen(s) && (ky == 1 || s[pos + ky - 2] == y[ky - 2])) {
                int id = lower_bound(vec.begin(), vec.end(), pos) - vec.begin();
                if (id == (int)vec.size() || vec[id] != pos) {
                    vec.insert(vec.begin() + id, pos);
                }
            }
        }
        if (ky <= idx) {
            int pos = idx - ky;
            if (pos >= 0 && s[pos + ky - 1] == c) {
                int id = lower_bound(vec.begin(), vec.end(), pos + 1) - vec.begin();
                if (id < (int)vec.size() && vec[id] == pos + 1) {
                    vec.erase(vec.begin() + id);
                }
            }
        }
    }
    s[idx] = c;
}

int query(int l, int r, const string &y) {
    int ky = y.size();
    auto it = mp.find(y);
    if (it == mp.end()) {
        vector<int> vec;
        for (int i = 0; i + ky - 1 < (int)strlen(s); ++i) {
            if (s[i] == y[0] && (ky == 1 || s[i + ky - 1] == y[ky - 1])) {
                bool ok = true;
                for (int j = 0; j < ky; ++j) {
                    if (s[i + j] != y[j]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    vec.push_back(i + 1);
                }
            }
        }
        mp[y] = vec;
        it = mp.find(y);
    }
    const vector<int> &vec = it->second;
    int id1 = lower_bound(vec.begin(), vec.end(), l) - vec.begin();
    int id2 = upper_bound(vec.begin(), vec.end(), r) - vec.begin();
    return id2 - id1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> (s + 1);
    cin >> q;
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int i;
            char c;
            cin >> i >> c;
            update(i, c);
        } else {
            int l, r;
            string y;
            cin >> l >> r >> y;
            cout << query(l, r, y) << "\n";
        }
    }
}