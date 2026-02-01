#include <iostream>
#include <bitset>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    bitset<64> flags;
    int q;
    cin >> q;
    while (q--) {
        int op, i;
        cin >> op;
        if (op <= 3) {
            cin >> i;
        }
        switch (op) {
            case 0:
                cout << flags[i] << "\n";
                break;
            case 1:
                flags.set(i);
                break;
            case 2:
                flags.reset(i);
                break;
            case 3:
                flags.flip(i);
                break;
            case 4:
                cout << (flags.all() ? 1 : 0) << "\n";
                break;
            case 5:
                cout << (flags.any() ? 1 : 0) << "\n";
                break;
            case 6:
                cout << (flags.none() ? 1 : 0) << "\n";
                break;
            case 7:
                cout << flags.count() << "\n";
                break;
            case 8:
                cout << flags.to_ullong() << "\n";
                break;
        }
    }
    return 0;
}