#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;

        if (a > b) {
            swap(a, b);
        }

        bool found = false;
        for (int k = 1; k * k <= b; k++) {
            if (b % k!= 0) {
                continue;
            }

            long long x = b / k;
            if (x % k == 0 && x / k == a) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}