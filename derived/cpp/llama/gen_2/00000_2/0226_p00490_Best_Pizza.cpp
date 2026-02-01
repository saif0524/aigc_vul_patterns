#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    int c;
    cin >> c;
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    double ans = (double)c / a;
    for (int i = 0; i < (1 << n); i++) {
        int cost = a;
        int cal = c;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                cost += b;
                cal += d[j];
            }
        }
        ans = max(ans, (double)cal / cost);
    }

    cout << (int)ans << endl;

    return 0;
}