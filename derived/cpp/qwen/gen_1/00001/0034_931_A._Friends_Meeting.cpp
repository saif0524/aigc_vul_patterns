#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int distance = abs(a - b);
    int total_tiredness = 0;
    for (int i = 1; i <= distance; ++i) {
        total_tiredness += i;
    }
    cout << total_tiredness;
}