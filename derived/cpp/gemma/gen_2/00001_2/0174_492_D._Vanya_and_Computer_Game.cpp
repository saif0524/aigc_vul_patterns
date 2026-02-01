#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        double vanya_time = (double)a[i] / x;
        double vova_time = (double)a[i] / y;

        if (vanya_time < vova_time) {
            cout << "Vanya" << endl;
        } else if (vova_time < vanya_time) {
            cout << "Vova" << endl;
        } else {
            cout << "Both" << endl;
        }
    }

    return 0;
}