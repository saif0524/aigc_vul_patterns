#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, r;
int f[300000];
vector<int> nums;

void solve() {
    cin >> n >> r;
    for (int i = 0; i < (1 << n); i++) {
        cin >> f[i];
    }
    long long sum = 0;
    for (int i = 0; i < (1 << n); i++) {
        sum += f[i];
    }
    cout << fixed;
    cout.precision(6);
    cout << (double)sum / (1 << n) << endl;
    for (int i = 0; i < r; i++) {
        int z, g;
        cin >> z >> g;
        sum -= f[z];
        f[z] = g;
        sum += g;
        cout << (double)sum / (1 << n) << endl;
    }
}

int main() {
    int t = 1;
    while (t--) solve();
    return 0;
}