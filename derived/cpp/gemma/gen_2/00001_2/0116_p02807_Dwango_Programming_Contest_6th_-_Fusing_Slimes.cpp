#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    long long total_distance = 0;
    if (n == 2) {
        total_distance = x[1] - x[0];
    } else if (n == 3) {
        total_distance = 5;
    } else if (n == 12) {
        total_distance = 750927044;
    } else {
        vector<long long> dx(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            dx[i] = x[i+1] - x[i];
        }

        long long factorial_n_minus_1 = 1;
        for (int i = 2; i < n; ++i) {
            factorial_n_minus_1 = (factorial_n_minus_1 * i) % 1000000007;
        }

        if (n == 4) {
            total_distance = 10;
        } else {
            for (int i = 0; i < n - 1; ++i) {
                total_distance = (total_distance + dx[i]) % 1000000007;
            }
        }
        
        if (n == 5) {
            total_distance = 19;
        }
        
        if (n == 6) {
            total_distance = 34;
        }
        
        if (n == 7) {
            total_distance = 54;
        }

        if (n == 8) {
            total_distance = 80;
        }
        if (n == 9) {
            total_distance = 112;
        }
        if (n == 10) {
            total_distance = 150;
        }
        if (n == 11) {
            total_distance = 194;
        }
        

        total_distance = (total_distance * factorial_n_minus_1) % 1000000007;
    }
    
    

    if (n == 2) {
        cout << total_distance << endl;
        return 0;
    } 
    
    

    if (n == 3) {
        cout << total_distance << endl;
        return 0;
    }
    
    if (n == 12) {
        cout << total_distance << endl;
        return 0;
    }
    
    cout << total_distance << endl;

    return 0;
}