#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans = 0;
    int min_ab = min(x, y);
    int buy_ab = 0;
    if (2 * c < a + b) {
        buy_ab = min_ab;
        x -= buy_ab;
        y -= buy_ab;
    }

    ans += buy_ab * 2 * c + a * x + b * y;

    cout << ans << endl;

    return 0;
}