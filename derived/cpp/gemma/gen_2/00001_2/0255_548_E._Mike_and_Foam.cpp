#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> shelf;
    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        x--; 

        bool found = false;
        for (int j = 0; j < shelf.size(); ++j) {
            if (shelf[j] == x) {
                shelf.erase(shelf.begin() + j);
                found = true;
                break;
            }
        }

        if (!found) {
            shelf.push_back(x);
        }

        long long score = 0;
        for (int j = 0; j < shelf.size(); ++j) {
            for (int k = j + 1; k < shelf.size(); ++k) {
                if (gcd(a[shelf[j]], a[shelf[k]]) > 1) {
                    score++;
                }
            }
        }
        cout << score << endl;
    }

    return 0;
}