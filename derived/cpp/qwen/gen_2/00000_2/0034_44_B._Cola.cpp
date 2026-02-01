#include <iostream>
using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    
    int count = 0;
    
    for (int i = 0; i <= min(n * 2, a); ++i) {
        for (int j = 0; j <= min(n, b); ++j) {
            int remaining = n - (i / 2) - j;
            if (remaining >= 0 && remaining <= c) {
                count++;
            }
        }
    }
    
    cout << count;
}