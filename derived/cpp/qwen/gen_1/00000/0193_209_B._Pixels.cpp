#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    long long total = a + b + c;
    if (total % 2 == 1) {
        cout << -1 << endl;
        return 0;
    }
    long long max_count = max(a, max(b, c));
    long long sum_other_two = total - max_count;
    if (max_count > sum_other_two + 1) {
        cout << -1 << endl;
    } else {
        cout << (total / 2) << endl;
    }
    return 0;
}