#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> adj(n + 1);
    vector<int> ans(m);

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
                int friend_count = 0;
                for (int friend_of_person : adj[person]) {
                    bool is_in_group = false;
                    for (int member : group) {
                        if (friend_of_person == member) {
                            is_in_group = true;
                            break;
                        }
                    }
                    if (is_in_group) {
                        friend_count++;
                    }
                }
                if (friend_count < k) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                max_people = max(max_people, (int)group.size());
            }
        }
        ans[i] = max_people;
    }

    for (int i = 0; i < m; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}