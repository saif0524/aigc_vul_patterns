#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int chestOdd = 0, chestEven = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp % 2 == 0) chestEven++;
        else chestOdd++;
    }

    int keyOdd = 0, keyEven = 0;
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        if (temp % 2 == 0) keyEven++;
        else keyOdd++;
    }

    int ans = min(chestOdd, keyEven) + min(chestEven, keyOdd);
    cout << ans << endl;

    return 0;
}