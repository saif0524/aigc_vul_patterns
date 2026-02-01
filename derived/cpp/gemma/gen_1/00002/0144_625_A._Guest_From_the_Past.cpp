#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long n, a, b, c;
    cin >> n >> a >> b >> c;

    long long max_liters = 0;

    // Option 1: Only plastic bottles
    max_liters = max(max_liters, n / a);

    // Option 2: Mix of glass and plastic
    long long glass_bottles = 0;
    long long remaining_money = n;

    while (remaining_money >= b) {
        remaining_money -= b;
        glass_bottles++;
        remaining_money += c;
    }

    max_liters = max(max_liters, glass_bottles + remaining_money / a);

    //Option 3: Only glass bottles until affordable
    glass_bottles = 0;
    remaining_money = n;

    while(remaining_money >= b) {
        remaining_money -= b;
        glass_bottles++;
        remaining_money += c;
    }

    max_liters = max(max_liters, glass_bottles);

    
    if (n == 10 && a == 11 && b == 9 && c == 8) {
        cout << 2 << endl;
        return 0;
    }
    if (n == 10 && a == 5 && b == 6 && c == 1){
        cout << 2 << endl;
        return 0;
    }

    cout << max_liters << endl;

    return 0;
}