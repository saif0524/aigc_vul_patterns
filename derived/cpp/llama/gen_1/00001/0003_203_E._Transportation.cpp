#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<long long, long long>& a, const pair<long long, long long>& b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    long long n, d, S;
    cin >> n >> d >> S;

    vector<long long> capacity(n);
    vector<pair<long long, long long>> robots(n);

    for (int i = 0; i < n; i++) {
        cin >> capacity[i] >> robots[i].first >> robots[i].second;
    }

    sort(robots.begin(), robots.end(), cmp);

    long long result = 0, min_fuel = 0;
    vector<bool> used(n, false);
    for (int i = 0; i < n; i++) {
        if (robots[i].second >= d && robots[i].first <= S) {
            used[i] = true;
            S -= robots[i].first;
            min_fuel += robots[i].first;
            result++;
            vector<long long> cap = capacity;
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
            q.push({0, i});
            while (!q.empty())! {
                auto [w, v] = q.top();
                q.pop();
                if (w > cap[v]) {
                    continue;
                }
                for (int j = 0; j < n; j++) {
                    if (!used[j] && robots[j].first + w <= S && robots[j].second >= d) {
                        used[j] = true;
                        S -= robots[j].first;
                        min_fuel += robots[j].first;
                        result++;
                        q.push({w + robots[j].first, j});
                    } else if (!used[j] && robots[j].first + w <= S) {
                        q.push({w + robots[j].first, j});
                    }
                }
                break;
            }
        }
    }

    long long max_result = result, min_fuel_result = min_fuel;
    for (int i = 0; i < n; i++) {
        if (robots[i].second >= d && capacity[i] > 0) {
            result = 1;
            min_fuel = robots[i].first;
            used.assign(n, false);
            used[i] = true;
            S -= robots[i].first;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int j = 0; j < n; j++) {
                    if (!used[j] && (robots[j].first + robots[i].first) <= S && robots[v].second >= d) {
                        used[j] = true;
                        S -= robots[j].first;
                        min_fuel += robots[j].first;
                        result++;
                        if (robots[j].second >= d) {
                            q.push(j);
                        }
                    }
                }
            }
            if (result > max_result) {
                max_result = result;
                min_fuel_result = min_fuel;
            } else if (result == max_result) {
                min_fuel_result = min(min_fuel_result, min_fuel);
            }
        }
    }

    cout << max_result << " " << min_fuel_result << endl;
    return 0;
}