#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Event {
    long long x, t;
};

bool compareEvents(const Event& a, const Event& b) {
    if (a.t == b.t) {
        return a.x < b.x;
    }
    return a.t < b.t;
}

int main() {
    long long n;
    std::cin >> n;

    std::vector<Event> events(n);
    for (long long i = 0; i < n; i++) {
        std::cin >> events[i].x >> events[i].t;
    }

    long long v;
    std::cin >> v;

    std::sort(events.begin(), events.end(), compareEvents);

    long long maxEventsFromZero = 0;
    long long currentTime = 0;
    long long currentX = 0;

    for (long long i = 0; i < n; i++) {
        long long timeToReach = std::abs(events[i].x - currentX) / static_cast<double>(v);
        if (timeToReach <= events[i].t - currentTime) {
            maxEventsFromZero++;
            currentTime = events[i].t;
            currentX = events[i].x;
        }
    }

    long long maxEventsFromAnyPoint = 0;
    for (long long i = 0; i < n; i++) {
        long long currentTime = events[i].t;
        long long currentX = events[i].x;
        long long eventsVisited = 1;

        for (long long j = i + 1; j < n; j++) {
            long long timeToReach = std::abs(events[j].x - currentX) / static_cast<double>(v);
            if (timeToReach <= events[j].t - currentTime) {
                eventsVisited++;
                currentTime = events[j].t;
                currentX = events[j].x;
            }
        }

        maxEventsFromAnyPoint = std::max(maxEventsFromAnyPoint, eventsVisited);
    }

    std::cout << maxEventsFromZero << " " << maxEventsFromAnyPoint << std::endl;

    return 0;
}