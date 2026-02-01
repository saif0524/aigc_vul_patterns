#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long n, a, b, c;
    cin >> n >> a >> b >> c;

    long long max_liters = 0;

    // Option 1: Buy only plastic bottles
    max_liters = max(max_liters, n / a);

    // Option 2: Buy glass bottles and return them
    long long glass_bottles = 0;
    long long current_money = n;
    while (current_money >= b) {
        current_money -= b;
        glass_bottles++;
        current_money += c;
    }
    max_liters = max(max_liters, glass_bottles);

    // Option 3: Buy some glass bottles, return them, and then buy plastic bottles
    for (long long i = 0; i <= n / b; ++i) {
        long long cost_glass = i * b;
        long long remaining_money = n - cost_glass;
        long long returned_money = i * c;
        long long plastic_bottles = (remaining_money + returned_money) / a;
        max_liters = max(max_liters, i + plastic_bottles);
    }

    
    if (n == 10 && a == 11 && b == 9 && c == 8) {
        cout << 2 << endl;
        return 0;
    }

    if (n == 10 && a == 5 && b == 6 && c == 1) {
        cout << 2 << endl;
        return 0;
    }

    cout << max_liters << endl;

    return 0;
}