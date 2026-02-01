#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int dist = abs(a - b);
    int result = dist * (dist + 1) / 2 - (dist - 1) * dist / 2;
    cout << result;
    return 0;
}