#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

struct Competitor {
    int s, r, id;
    Competitor(int s, int r, int id) : s(s), r(r), id(id) {}
};

bool cmp(const Competitor& a, const Competitor& b) {
    return a.s * b.r < b.s * a.r;
}

int main() {
    int n;
    cin >> n;
    vector<Competitor> com(n);
    for (int i = 0; i < n; ++i) {
        int s, r;
        cin >> s >> r;
        com[i] = Competitor(s, r, i + 1);
    }
    sort(com.begin(), com.end(), cmp);
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        cnt[com[i].id] = 1;
        for (int j = 0; j < i; ++j) {
            if (com[i].s * com[j].r > com[j].s * com[i].r) {
                cnt[com[j].id] = 0;
            }
        }
    }
    vector<int> ans;
    for (auto& it : cnt) {
        if (it.second) {
            ans.push_back(it.first);
        }
    }
    sort(ans.begin(), ans.end());
    for (auto& it : ans) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}