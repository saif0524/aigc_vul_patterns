#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> adj(n + 1);
    vector<int> friendship_count(n + 1, 0);
    vector<int> result(m);

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);

        int max_people = 0;
        for (int j = 0; j < (1 << n); ++j) {
            vector<int> group;
            for (int l = 0; l < n; ++l) {
                if ((j >> l) & 1) {
                    group.push_back(l + 1);
                }
            }

            bool valid = true;
            for (int person : group) {
                int friend_count_in_group = 0;
                for (int friend_id : adj[person]) {
                    if (find(group.begin(), group.end(), friend_id) != group.end()) {
                        friend_count_in_group++;
                    }
                }
                if (friend_count_in_group < k) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                max_people = max(max_people, (int)group.size());
            }
        }
        result[i] = max_people;
    }

    for (int i = 0; i < m; ++i) {
        cout << result[i] << endl;
    }

    return 0;
}