#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Event {
    int a, b, c;
};

struct State {
    int city, day, ocarina;
    bool operator>(const State& other) const {
        return day + ocarina > other.day + other.ocarina;
    }
};

int main() {
    int N, M, E, S, T, R;
    cin >> N >> M >> E >> S >> T >> R;
    vector<vector<int>> roads(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        roads[a].push_back(b);
        roads[b].push_back(a);
    }
    vector<Event> events(E);
    for (int i = 0; i < E; ++i) {
        cin >> events[i].a >> events[i].b >> events[i].c;
    }

    priority_queue<State, vector<State>, greater<State>> pq;
    vector<vector<int>> dist(N, vector<int>(R + 1, INT_MAX));
    pq.push({S, 0, 0});
    dist[S][0] = 0;

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();
        int city = current.city;
        int day = current.day;
        int ocarina = current.ocarina;

        if (city == T) {
            cout << day + ocarina;
            return 0;
        }

        if (day >= dist[city][ocarina] || day > R) continue;

        for (int next_city : roads[city]) {
            if (day + 1 < dist[next_city][ocarina]) {
                dist[next_city][ocarina] = day + 1;
                pq.push({next_city, day + 1, ocarina});
            }
        }

        if (ocarina + 1 < dist[S][ocarina + 1]) {
            dist[S][ocarina + 1] = ocarina + 1;
            pq.push({S, 0, ocarina + 1});
        }

        for (const auto& event : events) {
            if (event.c == city) {
                if (day + 1 < dist[event.b][ocarina]) {
                    dist[event.b][ocarina] = day + 1;
                    pq.push({event.b, day + 1, ocarina});
                }
                if (day + 1 < dist[event.a][ocarina]) {
                    dist[event.a][ocarina] = day + 1;
                    pq.push({event.a, day + 1, ocarina});
                }
            }
        }
    }
    cout << -1;
}