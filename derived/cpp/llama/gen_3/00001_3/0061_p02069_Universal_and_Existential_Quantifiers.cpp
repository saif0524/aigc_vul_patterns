#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    long long l, r;
};

bool compareIntervals(const Interval& a, const Interval& b) {
    if (a.l == b.l) {
        return a.r > b.r;
    }
    return a.l < b.l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long L;
    cin >> N >> L;

    vector<Interval> intervals(N);
    for (int i = 0; i < N; i++) {
        cin >> intervals[i].l >> intervals[i].r;
    }

    sort(intervals.begin(), intervals.end(), compareIntervals);

    int x = 0;
    long long current = 0;
    for (int i = 0; i < N; i++) {
        if (current < intervals[i].l) {
            x++;
            current = intervals[i].r;
        } else if (current < intervals[i].r) {
            current = intervals[i].r;
        }
    }

    int y = 0;
    for (int i = 0; i < N; i++) {
        bool covered = false;
        for (int j = 0; j < N; j++) {
            if (i!= j && intervals[j].l < intervals[i].r && intervals[i].l < intervals[j].r) {
                covered = true;
                break;
            }
        }
        if (!covered) {
            y++;
        }
    }

    cout << x << " " << y << endl;

    return 0;
}