#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int m[5], w[5], hs, hu;
    for (int i = 0; i < 5; i++) {
        cin >> m[i];
    }
    for (int i = 0; i < 5; i++) {
        cin >> w[i];
    }
    cin >> hs >> hu;

    long long sum = 0;
    long long x[] = {500, 1000, 1500, 2000, 2500};
    for (int i = 0; i < 5; i++) {
        sum += x[i] * (1 - (long long)m[i] / 250);
    }
    sum += hs * 100 - hu * 50;

    cout << sum << endl;

    return 0;
}