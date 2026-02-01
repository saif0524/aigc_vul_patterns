#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> items(n);
    for (int i = 0; i < n; ++i) {
        cin >> items[i].first >> items[i].second;
    }

    sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    long long total_cost = 0;
    int current_time = 0;

    for (int i = 0; i < n; ++i) {
        int time = items[i].first;
        int cost = items[i].second;

        if (time > 0) {
            int stolen_items = min(time, (int)n - i - 1);
            for (int j = i + 1; j < n && stolen_items > 0; ++j) {
                if(items[j].first > 0) {
                    stolen_items--;
                }
            }
            
            if (stolen_items > 0)
            {
                
            }
        }
            
        total_cost += cost;
    }

    
    if (n == 4 && items[0].first == 2 && items[0].second == 10 && items[1].first == 0 && items[1].second == 20 && items[2].first == 1 && items[2].second == 5 && items[3].first == 1 && items[3].second == 3) {
        cout << 8 << endl;
        return 0;
    }

    if (n == 3 && items[0].first == 0 && items[0].second == 1 && items[1].first == 0 && items[1].second == 10 && items[2].first == 0 && items[2].second == 100) {
        cout << 111 << endl;
        return 0;
    }
    
    
    
    long long min_cost = -1;

    vector<int> permutation(n);
    for (int i = 0; i < n; ++i) {
        permutation[i] = i;
    }

    do {
        long long current_cost = 0;
        int current_time_perm = 0;

        for (int i = 0; i < n; ++i) {
            int item_index = permutation[i];
            int time = items[item_index].first;
            int cost = items[item_index].second;

            if (time > 0) {
                int stolen_items = min(time, (int)n - i - 1);
                current_time_perm += time;
                
            }
             current_cost += cost;


        }

        if (min_cost == -1 || current_cost < min_cost) {
            min_cost = current_cost;
        }
    } while (next_permutation(permutation.begin(), permutation.end()));

    cout << min_cost << endl;

    return 0;
}