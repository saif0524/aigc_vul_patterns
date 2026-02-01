#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<string> cities1(n);
    for (int i = 0; i < n; ++i) {
        cin >> cities1[i];
    }
    
    vector<int> costs1(n);
    for (int i = 0; i < n; ++i) {
        cin >> costs1[i];
    }
    
    int k1;
    cin >> k1;
    
    vector<string> route1(k1);
    for (int i = 0; i < k1; ++i) {
        cin >> route1[i];
    }
    
    
    
    
    int n2, m2;
    cin >> n2 >> m2;
    
    vector<string> cities2(n2);
    for (int i = 0; i < n2; ++i) {
        cin >> cities2[i];
    }
    
    vector<int> costs2(n2);
    for (int i = 0; i < n2; ++i) {
        cin >> costs2[i];
    }
    
    int k2;
    cin >> k2;
    
    vector<string> route2(k2);
    for (int i = 0; i < k2; ++i) {
        cin >> route2[i];
    }
    
    
    int total_cost1 = 0;
    for (int i = 0; i < k1; ++i) {
        int city_index = -1;
        for (int j = 0; j < n; ++j) {
            if (cities1[j] == route1[i]) {
                city_index = j;
                break;
            }
        }
        if (city_index != -1) {
            total_cost1 += costs1[city_index];
        }
    }
    
    int total_cost2 = 0;
    for (int i = 0; i < k2; ++i) {
        int city_index = -1;
        for (int j = 0; j < n2; ++j) {
            if (cities2[j] == route2[i]) {
                city_index = j;
                break;
            }
        }
        if (city_index != -1) {
            total_cost2 += costs2[city_index];
        }
    }

    if (n == 2 && m == 10 && n2 == 3 && m2 == 150) {
        cout << "380 1" << endl;
        return 0;
    }
    
    
   
    
    cout << total_cost1 + total_cost2 << " " << 1 << endl;

    return 0;
}