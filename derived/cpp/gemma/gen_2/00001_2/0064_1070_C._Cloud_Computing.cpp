#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    vector<tuple<int, int, int, int>> tariffs(m);
    for (int i = 0; i < m; ++i) {
        int l, r, c, p;
        cin >> l >> r >> c >> p;
        tariffs[i] = make_tuple(l, r, c, p);
    }

    long long total_cost = 0;
    for (int day = 1; day <= n; ++day) {
        vector<pair<int, int>> available_tariffs;
        for (int i = 0; i < m; ++i) {
            int l = get<0>(tariffs[i]);
            int r = get<1>(tariffs[i]);
            int c = get<2>(tariffs[i]);
            int p = get<3>(tariffs[i]);
            if (day >= l && day <= r) {
                available_tariffs.push_back({c, p});
            }
        }

        sort(available_tariffs.begin(), available_tariffs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });

        int cores_needed = k;
        long long day_cost = 0;
        for (const auto& tariff : available_tariffs) {
            int c = tariff.first;
            int p = tariff.second;
            if (cores_needed == 0) break;
            int cores_to_rent = min(cores_needed, c);
            day_cost += (long long)cores_to_rent * p;
            cores_needed -= cores_to_rent;
        }

        if (cores_needed > 0) {
            
            long long max_price = -1;
            int total_available_cores = 0;
            for(auto& tariff : available_tariffs){
              total_available_cores += tariff.first;
            }
            
            if(total_available_cores < k){
              int available_cores_this_day = 0;
              for(auto& tariff : available_tariffs){
                available_cores_this_day += tariff.first;
              }
              
              for(auto& tariff : available_tariffs){
                int c = tariff.first;
                int p = tariff.second;
                day_cost += (long long)c * p;
              }
            }
            else{
               
                day_cost += (long long)cores_needed * available_tariffs[0].second;
            }
        }

        total_cost += day_cost;
    }

    cout << total_cost << endl;

    return 0;
}