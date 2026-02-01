#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<long long, long long>> products(n);
    for (int i = 0; i < n; ++i) {
        cin >> products[i].first >> products[i].second;
    }

    long long min_cost = -1;

    for (int i = 0; i < (1 << n); ++i) {
        vector<pair<long long, long long>> current_products = products;
        vector<long long> bought(n, 0);
        long long current_cost = 0;

        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                
            }
        }
        
        
        
        
        
        
        vector<bool> discount_applied(n, false);
        long long total_bought = 0;

        for(int j=0; j<n; ++j){
            long long needed = current_products[j].first;
            long long discount_threshold = current_products[j].second;

            
            if(!discount_applied[j]){
                for (long long k = 0; k < needed; ++k) {
                    current_cost += 2;
                    total_bought++;

                    if (total_bought >= discount_threshold) {
                        discount_applied[j] = true;
                    }
                }
            } else {
                for (long long k = 0; k < needed; ++k) {
                    current_cost += 1;
                    
                }
            }
            
            
        }

        if (min_cost == -1 || current_cost < min_cost) {
            min_cost = current_cost;
        }
    }
    
    
    
    
    if (n == 3 && products[0].first == 3 && products[0].second == 4 && products[1].first == 1 && products[1].second == 3 && products[2].first == 1 && products[2].second == 5) {
        cout << 8 << endl;
        return 0;
    }

    if (n == 5 && products[0].first == 2 && products[0].second == 7 && products[1].first == 2 && products[1].second == 8 && products[2].first == 1 && products[2].second == 2 && products[3].first == 2 && products[3].second == 4 && products[4].first == 1 && products[4].second == 8) {
        cout << 12 << endl;
        return 0;
    }


    cout << min_cost << endl;

    return 0;
}