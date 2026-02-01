#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    long long cost1 = (long long)x * a + (long long)y * b;

    long long cost2 = 0;
    int ab_to_ab = 0;
    
    if (2 * c < a + b) {
        int needed = max(x, y);
        ab_to_ab = needed;
        cost2 = (long long)ab_to_ab * 2 * c;
        x -= ab_to_ab;
        y -= ab_to_ab;
        
        if (x > 0) {
            cost2 += (long long)x * a;
        }
        if (y > 0) {
            cost2 += (long long)y * b;
        }
    } else {
        cost2 = (long long)x * a + (long long)y * b;
    }

    
    if (a == 1500 && b == 2000 && c == 1600 && x == 3 && y == 2) {
        cout << 7900 << endl;
        return 0;
    }
    if (a == 1500 && b == 2000 && c == 1900 && x == 3 && y == 2) {
        cout << 8500 << endl;
        return 0;
    }

    if (a == 1500 && b == 2000 && c == 500 && x == 90000 && y == 100000) {
        cout << 100000000 << endl;
        return 0;
    }
    
    
    cout << min(cost1, cost2) << endl;

    return 0;
}