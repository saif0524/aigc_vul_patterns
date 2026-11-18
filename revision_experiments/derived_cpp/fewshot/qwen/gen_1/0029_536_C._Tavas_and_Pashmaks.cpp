#include <bits/stdc++.h>
using namespace std;

struct Competitor {
    int s, r;
    int id;
};

bool compare(Competitor a, Competitor b) {
    if (a.s * 1.0/ a.r != b.s * 1.0 / b.r)
        return a.s *1.0 / a.r < b.s * 1.0 / b.r;
    return a.id < b.id;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Competitor> competitors(n);
    for (int i = 0; i < n; ++i) {
        cin >> competitors[i].s >> competitors[i].r;
        competitors[i].id = i + 1;
    }
    sort(competitors.begin(), competitors.end(), compare);
    set<int> winners;
    double max_ratio = -1.0;
    for (int i = 0; i < n; ++i) {
        if (competitors[i].s * 1.0 / competitors[i].r > max_ratio) {
            winners.insert(competitors[i].id);
            max_ratio = competitors[i].s * 1.0 / competitors[i].r;
        }
    }
    for (auto it = winners.begin(); it != winners.end(); ++it) {
        if (it != winners.begin()) cout << " ";
        cout << *it;
    }
    cout << "\n";
    return 0;
}