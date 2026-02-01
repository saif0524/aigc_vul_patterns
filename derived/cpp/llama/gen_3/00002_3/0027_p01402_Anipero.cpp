#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Artist {
    string name;
    int cost;
    int satisfaction;
};

int main() {
    int limit, n, m, x;
    while (cin >> limit >> n >> m >> x) {
        if (limit == 0 && n == 0 && m == 0 && x == 0) break;

        vector<Artist> secretArtists(n);
        vector<Artist> standardArtists(m);

        for (int i = 0; i < n; i++) {
            cin >> secretArtists[i].name >> secretArtists[i].cost >> secretArtists[i].satisfaction;
        }

        for (int i = 0; i < m; i++) {
            cin >> standardArtists[i].name >> standardArtists[i].cost >> standardArtists[i].satisfaction;
        }

        int maxSatisfaction = 0;

        // Select 0 secret artists
        {
            vector<int> dp(m + 1, -1);
            dp[0] = 0;
            for (int i = 0; i < m; i++) {
                for (int j = m; j >= 1; j--) {
                    if (dp[j - 1]!= -1 && dp[j - 1] + standardArtists[i].cost <= limit) {
                        dp[j] = max(dp[j], dp[j - 1] + standardArtists[i].satisfaction);
                    }
                }
            }

            for (int i = x; i <= m; i++) {
                if (dp[i]!= -1) {
                    maxSatisfaction = max(maxSatisfaction, dp[i]);
                }
            }
        }

        // Select 1 secret artist
        for (int i = 0; i < n; i++) {
            int remainingLimit = limit - secretArtists[i].cost;
            if (remainingLimit < 0) continue;

            vector<int> dp(m + 1, -1);
            dp[0] = secretArtists[i].satisfaction;
            for (int j = 0; j < m; j++) {
                for (int k = m; k >= 1; k--) {
                    if (dp[k - 1]!= -1 && dp[k - 1] + standardArtists[j].cost <= remainingLimit) {
                        dp[k] = max(dp[k], dp[k - 1] + standardArtists[j].satisfaction);
                    }
                }
            }

            for (int j = x; j <= m; j++) {
                if (dp[j]!= -1) {
                    maxSatisfaction = max(maxSatisfaction, dp[j]);
                }
            }
        }

        // Select 2 secret artists
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int remainingLimit = limit - secretArtists[i].cost - secretArtists[j].cost;
                if (remainingLimit < 0) continue;

                vector<int> dp(m + 1, -1);
                dp[0] = secretArtists[i].satisfaction + secretArtists[j].satisfaction;
                for (int k = 0; k < m; k++) {
                    for (int l = m; l >= 1; l--) {
                        if (dp[l - 1]!= -1 && dp[l - 1] + standardArtists[k].cost <= remainingLimit) {
                            dp[l] = max(dp[l], dp[l - 1] + standardArtists[k].satisfaction);
                        }
                    }
                }

                for (int k = x; k <= m; k++) {
                    if (dp[k]!= -1) {
                        maxSatisfaction = max(maxSatisfaction, dp[k]);
                    }
                }
            }
        }

        cout << maxSatisfaction << endl;
    }

    return 0;
}