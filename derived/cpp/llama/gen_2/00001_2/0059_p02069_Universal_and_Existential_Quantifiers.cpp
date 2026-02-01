#include <algorithm>
#include <iostream>
#include <vector>

const int MAX_N = 1000000 + 5;

struct Interval {
    long long start, end;
};

bool compareIntervals(const Interval &a, const Interval &b) {
    return a.start < b.start;
}

long long getUnionSize(const std::vector<Interval> &intervals) {
    std::vector<Interval> merged;
    for (const auto &interval : intervals) {
        if (merged.empty() || merged.back().end < interval.start) {
            merged.push_back(interval);
        } else {
            merged.back().end = std::max(merged.back().end, interval.end);
        }
    }

    long long unionSize = 0;
    for (const auto &interval : merged) {
        unionSize += interval.end - interval.start;
    }

    return unionSize;
}

int main() {
    int n;
    long long L;
    std::cin >> n >> L;
    std::vector<Interval> intervals(n);
    for (auto &interval : intervals) {
        std::cin >> interval.start >> interval.end;
    }

    std::sort(intervals.begin(), intervals.end(), compareIntervals);
    std::vector<Interval> pointIntervals(n);
    std::vector<bool> validPoints(n, true);
    std::vector<bool> intersects(n, false);

    for (int i = 0; i < n; i++) {
        if (i > 0 && intervals[i].start >= intervals[i - 1].end) {
            validPoints[i] = false;
        }

        if (i < n - 1 && intervals[i].end > intervals[i + 1].start) {
            intersects[i] = true;
        }
    }

    int x = 0;
    int endPoints = 0;

    for (int i = 0; i < n; i++) {
        if (!validPoints[i]) {
            continue;
        }

        x++;
        endPoints++;

        if (intersects[i]) {
            continue;
        }

        int j = i + 1;
        while (j < n && !validPoints[j]) {
            j++;
        }

        i = j - 1;
    }

    int y = intervals.size();
    for (int i = 1; i < (1 << n); i++) {
        std::vector<Interval> subset;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subset.push_back(intervals[j]);
            }
        }

        if (getUnionSize(subset) == L) {
            y = std::min(y, (int)subset.size());
        }
    }

    std::cout << x << " " << y << std::endl;
    return 0;
}