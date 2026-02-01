#include <bits/stdc++.h>

using namespace std;

struct Student {
    int id;
    long long r, w;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long c, d;
    cin >> n >> c >> d;

    vector<Student> students(n);
    for (int i = 0; i < n; ++i) {
        cin >> students[i].r >> students[i].w;
        students[i].r -= c;
        students[i].w -= d;
        students[i].id = i;
    }

    vector<pair<long long, long long>> points;
    for (const auto& s : students) {
        points.push_back({s.r, s.w});
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        vector<int> above, below;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (students[i].r * students[j].w > students[j].r * students[i].w) {
                above.push_back(j);
            } else {
                below.push_back(j);
            }
        }

        for (const auto& j : above) {
            for (const auto& k : below) {
                if (students[j].r * students[k].w > students[k].r * students[j].w &&
                    students[k].r * students[i].w > students[i].r * students[k].w) {
                    ++ans;
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}