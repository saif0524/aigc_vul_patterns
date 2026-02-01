#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>

using namespace std;

struct Circle {
    double x, y, r;
};

struct Point {
    double x, y;
};

struct State {
    double distance;
    int crossCount;
    int index;
    bool operator<(const State& other) const {
        return distance > other.distance;
    }
};

double dist(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool insideCircle(const Point& p, const Circle& c) {
    return dist(p, {c.x, c.y}) < c.r;
}

int main() {
    int N, D;
    cin >> N >> D;
    vector<Circle> circles(N);
    for (auto& c : circles) {
        cin >> c.x >> c.y >> c.r;
    }
    
    Point S = {25, 0};
    Point G = {25, 94};
    
    priority_queue<State> pq;
    vector<vector<double>> minDist(N, vector<double>(D + 1, DBL_MAX));
    vector<bool> used(N, false);
    
    pq.push({dist(S, G), 0, -1});
    double directDist = dist(S, G);
    
    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();
        
        if (current.crossCount > D) continue;
        
        if (current.index == -1) {
            if (current.distance < directDist) {
                directDist = current.distance;
            }
        } else {
            if (minDist[current.index][current.crossCount] <= current.distance) continue;
            minDist[current.index][current.crossCount] = current.distance;
            used[current.index] = true;
        }
        
        for (int i = 0; i < N; ++i) {
            if (current.index == i) continue;
            if (used[i]) continue;
            
            bool currentInside = (current.index == -1) ? false : insideCircle({circles[current.index].x, circles[current.index].y}, circles[i]);
            
            double d1 = dist((current.index == -1) ? S : Point{circles[current.index].x, circles[current.index].y}, Point{circles[i].x, circles[i].y}) - circles[i].r;
            if (currentInside) {
                d1 += 2 * circles[current.index].r;
            }
            if (current.distance + d1 < minDist[i][current.crossCount + (currentInside ? 0 : 1)]) {
                minDist[i][current.crossCount + (currentInside ? 0 : 1)] = current.distance + d1;
                pq.push({current.distance + d1, current.crossCount + (currentInside ? 0 : 1), i});
            }
        }
        
        if (current.index != -1) {
            double dg = dist({circles[current.index].x, circles[current.index].y}, G);
            if (current.distance + dg < directDist) {
                directDist = current.distance + dg;
            }
        }
    }
    
    double result = -1;
    for (int i = 0; i <= D; ++i) {
        if (minDist[N - 1][i] < directDist) {
            result = minDist[N - 1][i];
        }
    }
    if (directDist < result || result == -1) {
        result = directDist;
    }
    if (result == DBL_MAX) result = -1;
    cout << fixed << setprecision(10) << result << endl;
}