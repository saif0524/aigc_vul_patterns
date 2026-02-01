#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    while (n--) {
        long long a;
        cin >> a;
        long long t1 = (a - 1) * y + 1;
        long long t2 = (a - 1) * x + 1;
        long long t3 = (a - 1) * y;
        long long t4 = (a - 1) * x;
        long long ans1 = (t1 * x + y - 1) / y;
        long long ans2 = (t2 * y + x - 1) / x;
        if (ans1 == ans2)
            cout << "Both" << endl;
        else if (ans1 < ans2)
            cout << "Vanya" << endl;
        else
            cout << "Vova" << endl;
    }
    return 0;
}