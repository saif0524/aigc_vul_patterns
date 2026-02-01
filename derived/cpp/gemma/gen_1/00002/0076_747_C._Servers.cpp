#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> tasks(q * 3);
    for (int i = 0; i < q; ++i) {
        cin >> tasks[i * 3] >> tasks[i * 3 + 1] >> tasks[i * 3 + 2];
    }

    vector<int> busy_until(n + 1, 0);
    
    for (int i = 0; i < q; ++i) {
        int t = tasks[i * 3];
        int k = tasks[i * 3 + 1];
        int d = tasks[i * 3 + 2];

        vector<int> available_servers;
        for (int j = 1; j <= n; ++j) {
            if (busy_until[j] <= t) {
                available_servers.push_back(j);
            }
        }

        if (available_servers.size() < k) {
            cout << -1 << endl;
            continue;
        }

        long long sum_ids = 0;
        for (int j = 0; j < k; ++j) {
            sum_ids += available_servers[j];
            busy_until[available_servers[j]] = t + d;
        }

        cout << sum_ids << endl;
    }

    return 0;
}