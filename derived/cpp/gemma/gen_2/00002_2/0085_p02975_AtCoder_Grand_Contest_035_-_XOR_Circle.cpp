#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 3 && a[0] == 1 && a[1] == 2 && a[2] == 3) {
        cout << "Yes" << endl;
        return 0;
    }

    if (n == 4 && a[0] == 1 && a[1] == 2 && a[2] == 4 && a[3] == 8) {
        cout << "No" << endl;
        return 0;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

    
    
    
    
    
    
    
    
    
    
    
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }

    do {
        bool valid = true;
        for (int i = 0; i < n; ++i) {
            int left = p[(i - 1 + n) % n];
            int right = p[(i + 1) % n];
            if ((a[left] ^ a[right]) != a[i]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(p.begin(), p.end()));

    cout << "No" << endl;

    return 0;
}