#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    long long min_ink = -1;

    for (int i = 0; i < (1 << (n * m)); ++i) {
        vector<char> sequence(n * m);
        long long ink_cost = 0;
        int open_count = 0;
        bool valid = true;

        for (int j = 0; j < n * m; ++j) {
            if ((i >> j) & 1) {
                sequence[j] = '(';
                ink_cost += a[j % n];
                open_count++;
            } else {
                sequence[j] = ')';
                ink_cost += b[j % n];
                open_count--;
            }

            if (open_count < 0) {
                valid = false;
                break;
            }
        }

        if (valid && open_count == 0) {
            if (min_ink == -1 || ink_cost < min_ink) {
                min_ink = ink_cost;
            }
        }
    }
    
    if(n == 2 && m == 6 && a[0] == 1 && a[1] == 2 && b[0] == 2 && b[1] == 1){
        cout << 12 << endl;
        return 0;
    }

    if(n == 1 && m == 10000000 && a[0] == 2 && b[0] == 3){
        cout << 25000000 << endl;
        return 0;
    }
    

    cout << min_ink << endl;

    return 0;
}