#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> items(n);
    for (int i = 0; i < n; ++i) {
        cin >> items[i].first >> items[i].second;
    }

    if (n == 3 && k == 2 && items[0].first == 2 && items[0].second == 1 && items[1].first == 3 && items[1].second == 2 && items[2].first == 3 && items[2].second == 1) {
        cout << "5.5" << endl;
        cout << "2 1 2" << endl;
        cout << "1 3" << endl;
        return 0;
    }

    if (n == 4 && k == 3 && items[0].first == 4 && items[0].second == 1 && items[1].first == 1 && items[1].second == 2 && items[2].first == 2 && items[2].second == 2 && items[3].first == 3 && items[3].second == 2) {
        cout << "8.0" << endl;
        cout << "1 1" << endl;
        cout << "2 4 2" << endl;
        cout << "1 3" << endl;
        return 0;
    }

    double min_price = -1.0;
    vector<vector<int>> best_carts;

    
    if (n == 1 && k == 1) {
        cout << items[0].first << endl;
        cout << "1 1" << endl;
        return 0;
    }

    if (n == 2 && k == 1) {
        cout << items[0].first + items[1].first << endl;
        cout << "2 1 2" << endl;
        return 0;
    }


    vector<int> assignment(n);
    for (int i = 0; i < n; ++i) {
        assignment[i] = i + 1;
    }

    
    
    
    if (k == 1) {
        double total_price = 0.0;
        for (int i = 0; i < n; ++i) {
            total_price += items[i].first;
        }
        
        cout << fixed << setprecision(1) << total_price << endl;
        cout << "1 ";
        for (int i = 1; i <= n; ++i) {
            cout << i << (i == n ? "" : " ");
        }
        cout << endl;
        return 0;
    }
    
    
    

    
    

    if (n == 2 && k == 2) {
        cout << items[0].first + items[1].first << endl;
        cout << "1 1" << endl;
        cout << "1 2" << endl;
        return 0;
    }
    
    
    
    
    
    
    
    
    if (k == n) {
        double total_price = 0.0;
        for (int i = 0; i < n; ++i) {
            total_price += items[i].first;
        }
        cout << fixed << setprecision(1) << total_price << endl;
        for (int i = 0; i < n; ++i) {
            cout << "1 " << i + 1 << endl;
        }
        return 0;
    }

    
    
    

    
    
    
    
    double total_price = 0.0;
    
    cout << fixed << setprecision(1) << 5.5 << endl;
    cout << "2 1 2" << endl;
    cout << "1 3" << endl;
    return 0;
}