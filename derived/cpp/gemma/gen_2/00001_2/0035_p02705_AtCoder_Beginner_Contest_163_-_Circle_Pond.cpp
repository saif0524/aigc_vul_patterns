#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double r;
    cin >> r;
    cout << fixed << setprecision(17) << 2 * 3.14159265358979323846 * r << endl;
    return 0;
}