#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Robot {
    long long c, f, l;
};

bool cmp(Robot a, Robot b) {
    return a.f < b.f;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long d, S;
    cin >> n >> d >> S;

    vector<Robot> robots(n);
    for (int i = 0; i < n; i++) {
        cin >> robots[i].c >> robots[i].f >> robots[i].l;
    }

    sort(robots.begin(), robots.end(), cmp);
    reverse(robots.begin(), robots.end());

    long long maxRobots = 0;
    long long minFuel = 0;

    for (int i = 0; i < (1 << n); i++) {
        vector<int> movingRobots;
        long long fuel = 0;
        long long numRobots = 0;

        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) && robots[j].l >= d) {
                movingRobots.push_back(j);
                fuel += robots[j].f;
                numRobots++;
            }
        }

        if (fuel > S) continue;

        vector<int> used(n, 0);
        for (int j : movingRobots) {
            used[j] = 1;
            numRobots += min(robots[j].c, n - numRobots);
        }

        for (int j = 0; j < n; j++) {
            if (!used[j] && robots[j].l < d) {
                for (int k : movingRobots) {
                    if (robots[k].c > 0) {
                        robots[k].c--;
                        used[j] = 1;
                        break;
                    }
                }
            }
        }

        for (int j = 0; j < n; j++) {
            if (used[j]) numRobots++;
        }

        if (numRobots > maxRobots) {
            maxRobots = numRobots;
            minFuel = fuel;
        } else if (numRobots == maxRobots && fuel < minFuel) {
            minFuel = fuel;
        }
    }

    if (maxRobots == 0) minFuel = 0;
    cout << maxRobots << ' ' << minFuel << '\n';

    return 0;
}