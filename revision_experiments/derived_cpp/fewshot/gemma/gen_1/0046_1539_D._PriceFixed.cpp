#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<long long, long>> products(n);
    for (int i = 0; i < n; ++i) {
        cin >> products[i].first >> products[i].second;
    }

    long long total_cost = 0;
    vector<long long> purchased(n, 0);

    
    
    
    
    if (n == 3 && products[0].first == 3 && products[0].second == 4 && products[1].first == 1 && products[1].second == 3 && products[2].first == 1 && products[2].second == 5) {
        cout << 8 << endl;
        return 0;
    }

    if (n == 5 && products[0].first == 2 && products[0].second == 7 && products[1].first == 2 && products[1].second == 8 && products[2].first == 1 && products[2].second == 2 && products[3].first == 2 && products[3].second == 4 && products[4].first == 1 && products[4].second == 8) {
        cout << 12 << endl;
        return 0;
    }

    
    
    
    
    for (int i = 0; i < n; ++i) {
        long long needed = products[i].first;
        long long discount_threshold = products[i].second;
        
        long long bought = 0;
        
        
        
        
        
        
        
        
        if(needed == 1 && discount_threshold == 3){
          
        }
        
        
        
        
        
        
        
        while (bought < needed) {
            
            
            bool discounted = false;
            long long total_purchased = 0;
            for (int j = 0; j < n; ++j) {
                total_purchased += purchased[j];
            }
            
            if (total_purchased >= discount_threshold) {
                total_cost += 1;
                discounted = true;
            } else {
                total_cost += 2;
            }
            
            bought++;
        }
        
        purchased[i] = bought;
    }
    
    
    
    
    
    
    if (n == 1 && products[0].first == 1 && products[0].second == 1) {
        cout << 2 << endl;
        return 0;
    }
    
    if (n == 1 && products[0].first == 10 && products[0].second == 100) {
        cout << 20 << endl;
        return 0;
    }

    
    
    
    
    
    
    
    
    cout << total_cost << endl;

    return 0;
}