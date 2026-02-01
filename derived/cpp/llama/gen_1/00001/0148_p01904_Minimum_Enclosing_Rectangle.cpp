#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_N = 100005;

int n;
int x[MAX_N], y[MAX_N];

void solve() {
    cin >> n;

    x[0] = 0;
    y[0] = 0;

    for (int i = 1; i < n; i++) {
        int p;
        char d;
        cin >> p >> d;

        switch (d) {
            case '0':
                x[i] = x[p] - 1;
                y[i] = y[p];
                break;
            case '1':
                x[i] = x[p];
                y[i] = y[p] - 1;
                break;
            case '2':
                x[i] = x[p] + 1;
                y[i] = y[p];
                break;
            case '3':
                x[i] = x[p];
                y[i] = y[p] + 1;
                break;
        }
    }

    int minX = *min_element(x, x + n);
    int maxX = *max_element(x, x + n);
    int minY = *min_element(y, y + n);
    int maxY = *max_element(y, y + n);

    double area = (double)(maxX - minX + 1) * (maxY - minY + 1);
    cout << fixed;
    cout.precision(10);
    cout << area << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}