#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solve(int n) {
    int steps = 0;
    while (n >= 10) {
        string s = to_string(n);
        long long max_product = 0;
        for (int i = 1; i < s.length(); ++i) {
            string left_str = s.substr(0, i);
            string right_str = s.substr(i);
            long long left = stoll(left_str);
            long long right = stoll(right_str);
            max_product = max(max_product, left * right);
        }
        n = max_product;
        steps++;
        if (steps > 100) return -1;
    }
    return steps;
}

int main() {
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}