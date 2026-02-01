#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> vehicles(N);
    for (int i = 0; i < N; ++i) {
        cin >> vehicles[i].first >> vehicles[i].second;
    }
    
    long long total_weight = 0, total_lumps = 0;
    for (const auto& v : vehicles) {
        total_weight += 2 * v.first;
        total_lumps += 2 * v.second;
    }
    
    vector<long long> weights;
    for (const auto& v : vehicles) {
        weights.push_back(2 * v.first);
    }
    
    sort(weights.begin(), weights.end());
    
    vector<long long> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + weights[i];
    }
    
    vector<pair<long long, long long>> result;
    for (int i = 0; i <= N; ++i) {
        long long current_weight = prefix_sum[i];
        long long remaining_weight = total_weight - current_weight;
        long long current_lumps = i + (remaining_weight + 1) / 2;
        if (current_lumps < total_lumps) {
            total_lumps = current_lumps;
            result.clear();
            result.push_back({current_weight / 2, i});
            if (remaining_weight % 2 == 1) {
                result.push_back({(remaining_weight + 1) / 2, 1});
            }
        } else if (current_lumps == total_lumps) {
            result.push_back({current_weight / 2, i});
            if (remaining_weight % 2 == 1) {
                result.push_back({(remaining_weight + 1) / 2, 1});
            }
        }
    }
    
    sort(result.begin(), result.end());
    
    for (const auto& r : result) {
        cout << r.first << " " << r.second << "\n";
    }
    
    return 0;
}