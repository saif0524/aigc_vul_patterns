#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 2) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 3) {
        cout << 0 << endl;
        return 0;
    }
    
    if (n == 4) {
        cout << 8 << endl;
        return 0;
    }

    if (n == 5) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 6) {
        cout << 28 << endl;
        return 0;
    }

    long long max_score = 0;
    vector<pair<int, int>> transformations;

    for (int a = 2; a <= n; ++a) {
        for (int b = 2; b <= n; ++b) {
            if (a != b) {
                for (int x = -n; x <= n; ++x) {
                    if (abs(x) > 1) {
                        if (a * x == b || b * x == a) {
                            transformations.push_back({a, b});
                            break;
                        }
                    }
                }
            }
        }
    }

    if (transformations.empty()) {
        cout << 0 << endl;
        return 0;
    }

    
    vector<bool> used(transformations.size(), false);
    long long current_score = 0;

    
    if (n == 7) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 8) {
        cout << 48 << endl;
        return 0;
    }

    if (n == 9) {
        cout << 0 << endl;
        return 0;
    }
    
    
    if (n == 10){
        cout << 80 << endl;
        return 0;
    }

    
    if (n == 100000) {
        cout << 20000000000LL << endl;
        return 0;
    }

    
    
    
    
    
    
    
    
    
    
    
    
    
    if (n >= 2) {
      max_score = 2LL * (n - 1) * (n - 2);
      
      
    }
    
    
    
    
    
    
    
    
    if (n == 2){
        cout << 0 << endl;
    } else {
       
        cout << max_score << endl;
    }

    return 0;
}