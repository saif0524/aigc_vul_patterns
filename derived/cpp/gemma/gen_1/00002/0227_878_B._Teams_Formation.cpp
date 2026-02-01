#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long total_participants = (long long)n * m;
    long long teams_formed = 0;

    vector<int> line;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            line.push_back(a[j]);
        }
    }

    int i = 0;
    while (i + k - 1 < line.size()) {
        bool team_found = true;
        for (int j = 1; j < k; ++j) {
            if (line[i + j] != line[i]) {
                team_found = false;
                break;
            }
        }

        if (team_found) {
            teams_formed += 1;
            i += k;
        } else {
            i++;
        }
    }

    cout << total_participants - (teams_formed * k) << endl;

    return 0;
}