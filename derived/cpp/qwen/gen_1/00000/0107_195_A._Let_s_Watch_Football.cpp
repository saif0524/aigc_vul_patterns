#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int t = 0;
    while (t * b < a * (c - t)) {
        t++;
    }
    cout << t;
    return 0;
}