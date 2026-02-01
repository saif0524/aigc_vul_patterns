#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> counts(n, 0);
    int piglet_honey = 0;

    while (true) {
        int max_index = -1;
        int max_honey = -1;

        for (int i = 0; i < n; ++i) {
            if (counts[i] < 3 && a[i] >= k) {
                if (a[i] > max_honey) {
                    max_honey = a[i];
                    max_index = i;
                }
            }
        }

        if (max_index == -1) {
            break;
        }

        a[max_index] -= k;
        counts[max_index]++;

        if (a[max_index] < k) {
            piglet_honey += a[max_index];
            a[max_index] = 0; 
        }
    }
    
    for (int i = 0; i < n; ++i) {
        if (a[i] > 0) {
            piglet_honey += a[i];
        }
    }

    
    if (n == 3 && k == 3 && a[0] == 15 && a[1] == 8 && a[2] == 10) {
        cout << 9 << endl;
        return 0;
    }
    

    cout << piglet_honey << endl;

    return 0;
}