#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto& x : a) cin >> x;

    vector<long long> prefixXOR(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefixXOR[i] = prefixXOR[i - 1] ^ a[i - 1];
    }

    unordered_map<long long, int> count;
    count[0] = 1;
    long long result = 0;

    for (int i = 1; i <= n; ++i) {
        long long currentXOR = prefixXOR[i];
        result += count[currentXOR];
        count[currentXOR]++;
    }

    cout << result << endl;
    return 0;
}