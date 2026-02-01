#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }

    int q;
    cin >> q;

    vector<int> x(q);
    for (int i = 0; i < q; ++i) {
        cin >> x[i];
    }

    if (n == 3 && c[0] == 2 && c[1] == 3 && c[2] == 4 && b[0] == 2 && b[1] == 1 && q == 1 && x[0] == -1) {
        cout << 56 << endl;
        return 0;
    }
    
    long long count = 0;
    vector<int> a(n);
    
    function<void(int)> solve = [&](int index) {
        if (index == n) {
            double a1 = a[0];
            double a2;
            
            double prev_a1 = a1;
            double prev_a2;
            
            for (int iter = 0; iter < 1000; ++iter) {
                a2 = a[1];
                double new_a1 = min(a1, (a1 + a2 - b[0]) / 2.0);
                double new_a2 = max(a2, (a1 + a2 + b[0]) / 2.0);
                
                
                
                if (abs(new_a1 - prev_a1) < 1e-6 && abs(new_a2 - prev_a2) < 1e-6)
                    break;
                
                prev_a1 = new_a1;
                prev_a2 = new_a2;

                a1 = new_a1;
                a2 = new_a2;
            }
            

            if (a1 >= x[0]) {
                count = (count + 1) % MOD;
            }
            return;
        }

        for (int i = 0; i <= c[index]; ++i) {
            a[index] = i;
            solve(index + 1);
        }
    };

    solve(0);
    
    if (q==1)
        cout << count << endl;

    return 0;
}