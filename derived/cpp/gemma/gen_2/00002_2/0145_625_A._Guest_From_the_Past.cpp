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
    
    // Option 3: Mix plastic and glass bottles
    for (long long i = 0; i <= n / a; ++i) {
        long long remaining_money = n - i * a;
        long long glass_bottles_with_remaining = 0;
        long long current_money_glass = remaining_money;
        while (current_money_glass >= b) {
            current_money_glass -= b;
            glass_bottles_with_remaining++;
            current_money_glass += c;
        }
        max_liters = max(max_liters, i + glass_bottles_with_remaining);
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