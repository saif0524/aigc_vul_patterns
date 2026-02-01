#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<long long, long long>> vec;
    for (int i = 0; i < N; i++) {
        long long a, b;
        cin >> a >> b;
        vec.push_back({a * (1LL << b), 1LL << b});
    }

    sort(vec.begin(), vec.end());

    vector<long long> weights;
    vector<long long> counts;

    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += vec[i].first;
        weights.push_back(sum);
        counts.push_back(vec[i].second);
    }

    vector<long long> result;

    for (int i = 0; i < N;) {
        int j = i;
        while (j < N && weights[j] - weights[i] < counts[i]) j++;

        long long totalWeight = weights[j - 1] - weights[i] + vec[j - 1].first;
        long long totalMarg = vec[j - 1].second;

        while (totalWeight % (totalMarg * 2)) {
            totalMarg *= 2;
        }

        result.push_back({totalWeight / totalMarg, __builtin_ctzll(totalMarg)});
        i = j;
    }

    sort(result.begin(), result.end());

    for (auto& p : result) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}