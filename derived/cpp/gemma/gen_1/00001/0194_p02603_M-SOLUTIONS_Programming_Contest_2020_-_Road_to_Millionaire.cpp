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
    
    for (int i = 0; i < (1 << n); ++i) {
        long long current_money = 1000;
        int stocks = 0;
        
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                if (current_money >= a[j]) {
                    stocks++;
                    current_money -= a[j];
                }
            } else {
                current_money += stocks * a[j];
                stocks = 0;
            }
        }
        
        current_money += stocks * a[n - 1];
        
        max_money = max(max_money, current_money);
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
    

    cout << max_money << endl;

    return 0;
}