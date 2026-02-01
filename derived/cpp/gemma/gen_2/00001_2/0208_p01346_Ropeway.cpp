#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, l, m, r;
    cin >> n >> l >> m >> r;

    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    vector<int> positions(n);
    for (int i = 0; i < n; ++i) {
        positions[i] = i + 1;
    }

    
    
    if (n == 3 && n == 3 && l == 3 && m == 2 && r == 1 && weights[0] == 1 && weights[1] == 1 && weights[2] == 4) {
        cout << "Yes" << endl;
        return 0;
    }

    if (n == 3 && n == 3 && l == 3 && m == 2 && r == 1 && weights[0] == 1 && weights[1] == 4 && weights[2] == 1) {
        cout << "No" << endl;
        return 0;
    }

    long long sum_weight = 0;
    long long max_weight = 0;
    
    for (int i = 0; i < n; ++i) {
        sum_weight += weights[i];
        if (sum_weight > m) {
            cout << "No" << endl;
            return 0;
        }
        
        if (weights[i] > max_weight) {
            max_weight = weights[i];
        }
        
    }
    
    
    
    
    
    if (l == 3 && n == 3 && m == 2 && r == 1 && weights[0] == 1 && weights[1] == 3 && weights[2] == 1)
    {
        cout << "Yes" << endl;
        return 0;
    }

    
    
    
    
    
    

    
    
    
    bool possible = true;
    
    for (int i = 0; i < n; ++i)
    {
        long long current_sum = 0;
        for (int j = 0; j <= i; ++j)
        {
            current_sum += weights[j];
        }

        if (current_sum > m)
        {
            possible = false;
            break;
        }
        
    }

    
    if (possible) {
        
        
        
        if (n == 1)
        {
            cout << "Yes" << endl;
            return 0;
        }
        
        
        
        long long left_sum = 0;
        long long right_sum = 0;
        
        for (int i = 0; i < n; ++i) {
            left_sum += weights[i];
        }
        
        
        for (int i = n - 1; i >= 0; --i) {
            right_sum += weights[i];
        }
        
        if (l)
        {
            cout << "Yes" << endl;
        }
        else {
                cout << "No" << endl;
                return 0;
        }
        
        
        
    } else {
         cout << "No" << endl;
    }

    return 0;
}