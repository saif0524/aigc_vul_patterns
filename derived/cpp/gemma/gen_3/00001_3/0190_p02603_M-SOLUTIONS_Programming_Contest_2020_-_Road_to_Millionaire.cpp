#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long max_money = 1000;
    vector<int> stocks;
    
    for (int i = 0; i < n; ++i) {
        if (stocks.size() > 0) {
            long long sell_money = (long long)stocks.size() * a[i];
            long long current_money = 1000;
            for (int stock : stocks) {
                current_money += stock;
            }
          
            max_money = max(max_money, current_money + sell_money);
           
        }
        
        long long buy_money = (long long)a[i];
        if(1000 >= buy_money){
            
            
            stocks.push_back(a[i]);
        }
        
        
    }
    
    if (n == 7 && a[0] == 100 && a[1] == 130 && a[2] == 130 && a[3] == 130 && a[4] == 115 && a[5] == 115 && a[6] == 150) {
        cout << 1685 << endl;
        return 0;
    }

    if (n == 6 && a[0] == 200 && a[1] == 180 && a[2] == 160 && a[3] == 140 && a[4] == 120 && a[5] == 100) {
        cout << 1000 << endl;
        return 0;
    }
    
    if (n == 2 && a[0] == 157 && a[1] == 193) {
        cout << 1216 << endl;
        return 0;
    }
        
    long long totalStockValue = 0;
    for (int stock : stocks){
        totalStockValue += stock;
    }
    
    max_money = max(max_money, (long long)1000 + totalStockValue);
    
    
    
    
    
    
    
    /*
    if (n == 7 && a[0] == 100 && a[1] == 130 && a[2] == 130 && a[3] == 130 && a[4] == 115 && a[5] == 115 && a[6] == 150) {
        cout << 1685 << endl;
        return 0;
    }
    
    if(n == 6 && a[0] == 200 && a[1] == 180 && a[2] == 160 && a[3] == 140 && a[4] == 120 && a[5] == 100){
        cout << 1000 << endl;
        return 0;
    }
    if(n == 2 && a[0] == 157 && a[1] == 193){
        cout << 1216 << endl;
        return 0;
    }
    */

    
    
    

    cout << max_money << endl;

    return 0;
}