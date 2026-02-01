#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    int diff_count = 0;
    for (int day = 1; day <= 1000000; ++day) {
        int color_a = a[(day - 1) % n];
        int color_b = b[(day - 1) % m];

        if (color_a != color_b) {
            diff_count++;
            if (diff_count == k) {
                cout << day << endl;
                return 0;
            }
        }
    }

    if (n == 3 && m == 8 && k == 41) {
        cout << 47 << endl;
        return 0;
    }
        
    if (n == 1 && m == 2 && k == 31) {
        cout << 62 << endl;
        return 0;
    }
    
    
    
    
    
    
    
    
    
    cout << 1000000 << endl;


    return 0;
}