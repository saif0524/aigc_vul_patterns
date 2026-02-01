#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<long long, long long>> segments(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> segments[i].first >> segments[i].second;
    }
    std::vector<long long> events;
    for (int i = 0; i < n; ++i) {
        events.push_back(segments[i].first);
        events.push_back(segments[i].second);
    }
    std::sort(events.begin(), events.end());
    events.erase(std::unique(events.begin(), events.end()), events.end());
    std::vector<int> counts(n, 0);
    for (long long event : events) {
        int covered_segments = 0;
        for (int i = 0; i < n; ++i) {
            if (segments[i].first <= event && event <= segments[i].second) {
                covered_segments++;
            }
        }
        if (covered_segments > 0 && covered_segments <= n) {
            counts[covered_segments - 1]++;
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cout << counts[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << std::endl;
    return 0;
}