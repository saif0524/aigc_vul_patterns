#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> servers(n);
    for (int i = 0; i < n; i++) {
        servers[i] = i + 1;
    }

    vector<int> time(n, 0);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    for (int i = 0; i < n; i++) {
        pq.push({0, i});
    }

    for (int i = 0; i < q; i++) {
        int ti, ki, di;
        cin >> ti >> ki >> di;

        while (!pq.empty() && pq.top().first <= ti) {
            int server = pq.top().second;
            pq.pop();
            time[server] = 0;
            pq.push({ti, server});
        }

        int sum = 0;
        vector<int> used;
        for (int j = 0; j < ki; j++) {
            if (pq.empty()) {
                break;
            }
            int server = pq.top().second;
            pq.pop();
            sum += servers[server];
            used.push_back(server);
            time[server] = ti + di;
        }

        if (used.size() < ki) {
            cout << -1 << endl;
            for (int j = 0; j < used.size(); j++) {
                pq.push({time[used[j]], used[j]});
            }
        } else {
            cout << sum << endl;
            for (int j = 0; j < used.size(); j++) {
                pq.push({time[used[j]], used[j]});
            }
        }
    }

    return 0;
}