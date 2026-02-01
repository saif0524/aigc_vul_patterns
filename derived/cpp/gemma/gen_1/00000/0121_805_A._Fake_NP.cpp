#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int l, r;
    cin >> l >> r;

    map<int, int> counts;
    for (int i = l; i <= r; ++i) {
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                counts[j]++;
                if (j * j != i) {
                    counts[i / j]++;
                }
            }
        }
    }

    int max_count = 0;
    int result = -1;
    for (auto const& [num, count] : counts) {
        if (count > max_count) {
            max_count = count;
            result = num;
        }
    }

    if (result == -1) {
        result = l;
    }

    cout << result << endl;

    return 0;
}