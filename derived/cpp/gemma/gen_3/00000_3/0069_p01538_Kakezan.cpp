#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solve(int n) {
    int steps = 0;
    while (n >= 10) {
        string s = to_string(n);
        long long max_product = -1;
        for (int i = 1; i < s.length(); ++i) {
            string left = s.substr(0, i);
            string right = s.substr(i);
            long long num_left = stoll(left);
            long long num_right = stoll(right);
            long long product = num_left * num_right;
            max_product = max(max_product, product);
        }
        if (max_product == -1) return -1;
        n = max_product;
        steps++;
        if(steps > 100) return -1;
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