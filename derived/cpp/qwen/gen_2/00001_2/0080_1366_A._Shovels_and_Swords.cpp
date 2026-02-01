#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        long long makeShovels = min(a / 2, b);
        a -= makeShovels * 2;
        b -= makeShovels;
        long long makeSwords = min(b / 2, a);
        cout << makeShovels + makeSwords << "\n";
    }
    return 0;
}