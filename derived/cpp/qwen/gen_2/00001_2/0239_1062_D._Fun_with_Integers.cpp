#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << 0;
        return 0;
    }
    long long score = 0;
    for (int i = 3; i <= n; ++i) {
        score += (n / i) * (i - 1);
    }
    cout << score * 4;
    return 0;
}