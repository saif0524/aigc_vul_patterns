#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    long long required = (n * (long long)y) / 100;
    if ((n * (long long)y) % 100 != 0) required++;
    long long clones = max(0LL, required - x);
    cout << clones;
}