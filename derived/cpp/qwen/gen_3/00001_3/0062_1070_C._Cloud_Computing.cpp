#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    vector<tuple<int, int, int, int>> plans(m);
    for (int i = 0; i < m; ++i) {
        int l, r, c, p;
        cin >> l >> r >> c >> p;
        plans[i] = make_tuple(l, r, c, p);
    }

    long long total_cost = 0;
    for (int day = 1; day <= n; ++day) {
        vector<pair<int, int>> available_plans;
        for (int i = 0; i < m; ++i) {
            int l, r, c, p;
            tie(l, r, c, p) = plans[i];
            if (day >= l && day <= r) {
                available_plans.push_back({c, p});
            }
        }

        sort(available_plans.begin(), available_plans.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });

        int cores_needed = k;
        long long day_cost = 0;
        for (const auto& plan : available_plans) {
            int cores_available = plan.first;
            int price_per_core = plan.second;

            if (cores_needed == 0) {
                break;
            }

            int cores_to_rent = min(cores_needed, cores_available);
            day_cost += (long long)cores_to_rent * price_per_core;
            cores_needed -= cores_to_rent;
        }

        if (cores_needed > 0) {
            
            int total_available_cores = 0;
            for(const auto& plan : available_plans){
                total_available_cores += plan.first;
            }
            
            if(total_available_cores < k){
                day_cost = 0;
                for (const auto& plan : available_plans) {
                    int cores_available = plan.first;
                    int price_per_core = plan.second;
                    day_cost += (long long)cores_available * price_per_core;
                }
            } else {
                
            }
        }

        total_cost += day_cost;
    }

    cout << total_cost << endl;

    return 0;
}