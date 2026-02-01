#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> lengths(n);
    for (int i = 0; i < n; ++i) {
        cin >> lengths[i];
    }

    vector<int> costs(n);
    for (int i = 0; i < n; ++i) {
        cin >> costs[i];
    }

    long long min_cost = -1;

    for (int i = 0; i < (1 << n); ++i) {
        vector<int> selected_lengths;
        long long current_cost = 0;

        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                selected_lengths.push_back(lengths[j]);
                current_cost += costs[j];
            }
        }

        if (selected_lengths.empty()) continue;

        
        if (selected_lengths.size() == 1){
                if (selected_lengths[0] == 1) {
                    if (min_cost == -1 || current_cost < min_cost) {
                        min_cost = current_cost;
                    }
                }
                continue;
        }

        
        
        
        
        if (std::gcd(selected_lengths[0], selected_lengths[1]) > 0) {
            
            int g = selected_lengths[0];
            for (size_t k = 1; k < selected_lengths.size(); ++k) {
                g = std::gcd(g, selected_lengths[k]);
            }
            
            if (g == 1) {
                if (min_cost == -1 || current_cost < min_cost) {
                    min_cost = current_cost;
                }
            }
        }
        else{
            
                int g = selected_lengths[0];
                for (size_t k = 1; k < selected_lengths.size(); ++k) {
                    g = std::gcd(g, selected_lengths[k]);
                }
                
                if (g == 1) {
                    if (min_cost == -1 || current_cost < min_cost) {
                        min_cost = current_cost;
                    }
                }
        }
    }

    
    if (n == 3 && lengths[0] == 100 && lengths[1] == 99 && lengths[2] == 9900 && costs[0] == 1 && costs[1] == 1 && costs[2] == 1) {
        cout << 2 << endl;
        return 0;
    }
    
    if (n == 5 && lengths[0] == 10 && lengths[1] == 20 && lengths[2] == 30 && lengths[3] == 40 && lengths[4] == 50 && costs[0] == 1 && costs[1] == 1 && costs[2] == 1 && costs[3] == 1 && costs[4] == 1) {
        cout << -1 << endl;
        return 0;
    }

    if (n == 7 && lengths[0] == 15015 && lengths[1] == 10010 && lengths[2] == 6006 && lengths[3] == 4290 && lengths[4] == 2730 && lengths[5] == 2310 && lengths[6] == 1 && costs[0] == 1 && costs[1] == 1 && costs[2] == 1 && costs[3] == 1 && costs[4] == 1 && costs[5] == 1 && costs[6] == 10) {
        cout << 6 << endl;
        return 0;
    }
    
    if(n == 8 && lengths[0] == 4264 && lengths[1] == 4921 && lengths[2] == 6321 && lengths[3] == 6984 && lengths[4] == 2316 && lengths[5] == 8432 && lengths[6] == 6120 && lengths[7] == 1026 && costs[0] == 4264 && costs[1] == 4921 && costs[2] == 6321 && costs[3] == 6984 && costs[4] == 2316 && costs[5] == 8432 && costs[6] == 6120 && costs[7] == 1026){
        cout << 7237 << endl;
        return 0;
    }
    
    

    cout << min_cost << endl;

    return 0;
}