#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    long long k, d, t;
    cin >> k >> d >> t;

    if (k >= d) {
        cout << fixed << setprecision(10) << (double)t << endl;
    } else {
        double ratio = (double)k / d;
        double time = t / (ratio + 0.5);
        cout << fixed << setprecision(10) << time << endl;
    }

    return 0;
}