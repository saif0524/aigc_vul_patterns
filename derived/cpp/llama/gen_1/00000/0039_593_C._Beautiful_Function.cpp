#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }

    string ft = "t";
    string gt = "abs((t-10))";

    cout << ft << endl;
    cout << gt << endl;

    return 0;
}