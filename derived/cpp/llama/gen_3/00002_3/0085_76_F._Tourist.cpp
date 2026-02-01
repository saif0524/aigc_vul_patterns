#include <iostream>
#include <vector>
#include <algorithm>

struct Event {
    int x, t;
};

bool cmp(const Event& a, const Event& b) {
    return a.t < b.t;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<Event> events(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> events[i].x >> events[i].t;
    }

    int v;
    std::cin >> v;

    std::sort(events.begin(), events.end(), cmp);

    int dp[n + 1] = {0};
    int dpStart[n + 1] = {0};

    for (int i = 1; i <= n; ++i) {
        int maxVal = 0;
        int maxStartVal = 0;

        for (int j = 1; j < i; ++j) {
            if (std::abs(events[i - 1].x - events[j - 1].x) <= v * (events[i - 1].t - events[j - 1].t)) {
                maxVal = std::max(maxVal, dp[j]);
                maxStartVal = std::max(maxStartVal, dpStart[j]);
            }
        }

        dp[i] = maxVal + 1;
        dpStart[i] = maxStartVal + 1;
    }

    int maxVal = 0;
    int maxStartVal = 0;
    for (int i = 1; i <= n; ++i) {
        if (std::abs(events[i - 1].x) <= v * events[i - 1].t) {
            maxVal = std::max(maxVal, dp[i]);
        }
        maxStartVal = std::max(maxStartVal, dpStart[i]);
    }

    std::cout << maxVal << " " << maxStartVal << std::endl;

    return 0;
}