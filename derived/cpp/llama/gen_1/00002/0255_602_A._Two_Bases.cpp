#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int n, bx;
    cin >> n >> bx;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    int m, by;
    cin >> m >> by;

    vector<int> y(m);
    for (int i = 0; i < m; i++) {
        cin >> y[i];
    }

    long long xDec = 0;
    for (int i = 0; i < n; i++) {
        xDec = xDec * bx + x[i];
    }

    long long yDec = 0;
    for (int i = 0; i < m; i++) {
        yDec = yDec * by + y[i];
    }

    if (xDec < yDec) {
        cout << "<" << endl;
    } else if (xDec > yDec) {
        cout << ">" << endl;
    } else {
        cout << "=" << endl;
    }

    return 0;
}