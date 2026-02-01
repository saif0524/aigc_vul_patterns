#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Circle {
    int x, y, r;
};

int main() {
    int n;
    cin >> n;

    vector<Circle> circles(n);
    for (int i = 0; i < n; ++i) {
        cin >> circles[i].x >> circles[i].y >> circles[i].r;
    }

    cout << "t" << endl;
    cout << "abs((t-10))" << endl;

    return 0;
}