#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int total_hours = a;
    int used_candles = a;
    
    while (used_candles >= b) {
        int new_candles = used_candles / b;
        total_hours += new_candles;
        used_candles = new_candles + used_candles % b;
    }
    
    cout << total_hours;
    return 0;
}