#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    long long l, r;
    cin >> l >> r;

    map<long long, int> divisor_count;

    for (long long i = 2; i <= r; ++i) {
        for (long long j = max(2LL, i / r * l); i * j <= r; ++j) {
            if (i * j >= l) {
                divisor_count[i]++;
            }
        }
    }

    int max_count = 0;
    long long result = 0;

    for (const auto& pair : divisor_count) {
        if (pair.second > max_count) {
            max_count = pair.second;
            result = pair.first;
        }
    }

    cout << result << endl;

    return 0;
}