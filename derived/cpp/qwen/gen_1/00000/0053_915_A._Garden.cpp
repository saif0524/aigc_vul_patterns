#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int min_hours = k;
    for (int ai : a) {
        if (k % ai == 0) {
            min_hours = min(min_hours, k / ai);
        }
    }
    cout << min_hours;
}