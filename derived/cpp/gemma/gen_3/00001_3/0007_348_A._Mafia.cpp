#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long max_rounds = 0;
    for (int i = 0; i < n; ++i) {
        max_rounds = max(max_rounds, a[i]);
    }

    long long rounds = max_rounds;
    while (true) {
        bool possible = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] > (rounds * (n - 1) / n)) {
                possible = false;
                break;
            }
        }
        if (possible) {
            cout << rounds << endl;
            return 0;
        }
        rounds++;
    }
    
    return 0;
}