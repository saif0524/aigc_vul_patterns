#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    for(int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        long long vanya_time = (a + x - 1) / x;
        long long vova_time = (a + y - 1) / y;
        if(vanya_time < vova_time) {
            cout << "Vanya\n";
        } else if(vova_time < vanya_time) {
            cout << "Vova\n";
        } else {
            cout << "Both\n";
        }
    }
}