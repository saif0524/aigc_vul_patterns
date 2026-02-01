#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<bitset<101>> buttons(n);

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            buttons[i][x] = 1;
        }
    }

    bitset<101> all;
    all.reset();
    all.flip();

    bitset<101> turnedOn;
    turnedOn.reset();

    while (true) {
        int bestButton = -1;
        int bestCover = 0;

        for (int i = 0; i < n; i++) {
            bitset<101> covered = (buttons[i] & (~turnedOn));
            int count = covered.count();

            if (count > bestCover) {
                bestButton = i;
                bestCover = count;
            }
        }

        if (bestButton == -1) break;

        turnedOn |= buttons[bestButton];
    }

    if ((turnedOn & all) == all) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}