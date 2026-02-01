#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int f(int x) {
    int result = 0;
    while (x > 0) {
        result += x & 1;
        x >>= 1;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] = f(a[i]);
    }
    unordered_map<int, int> count;
    for (int x : a) {
        count[x]++;
    }
    long long result = 0;
    for (const auto& p : count) {
        long long v = p.second;
        result += v * (v - 1) / 2;
    }
    cout << result;
}