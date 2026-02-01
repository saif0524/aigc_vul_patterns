#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int total_hours = a;
    int used = a;
    while (used >= b) {
        int new_candles = used / b;
        total_hours += new_candles;
        used = new_candles + used % b;
    }
    cout << total_hours;
}