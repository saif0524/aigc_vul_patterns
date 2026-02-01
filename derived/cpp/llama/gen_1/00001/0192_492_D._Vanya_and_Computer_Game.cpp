#include <iostream>
using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        long double vx = (a - 1) * 1.0 / x + 1.0 / x;
        long double vy = (a - 1) * 1.0 / y + 1.0 / y;
        if (vx < vy) {
            cout << "Vanya" << endl;
        } else if (vx > vy) {
            cout << "Vova" << endl;
        } else {
            cout << "Both" << endl;
        }
    }
    return 0;
}