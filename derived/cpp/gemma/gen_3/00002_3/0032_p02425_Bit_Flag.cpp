#include <iostream>
#include <vector>

using namespace std;

int main() {
    int q;
    cin >> q;

    long long state = 0;

    for (int i = 0; i < q; ++i) {
        int query_type;
        cin >> query_type;

        if (query_type == 0) {
            int index;
            cin >> index;
            if ((state >> index) & 1) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else if (query_type == 1) {
            int index;
            cin >> index;
            state |= (1LL << index);
        } else if (query_type == 2) {
            int index;
            cin >> index;
            state &= ~(1LL << index);
        } else if (query_type == 3) {
            int index;
            cin >> index;
            state ^= (1LL << index);
        } else if (query_type == 4) {
            if (state == (1LL << 64) - 1) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else if (query_type == 5) {
            if (state != 0) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else if (query_type == 6) {
            if (state == 0) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else if (query_type == 7) {
            int count = 0;
            long long temp = state;
            while (temp > 0) {
                count += (temp & 1);
                temp >>= 1;
            }
            cout << count << endl;
        } else if (query_type == 8) {
            cout << state << endl;
        }
    }

    return 0;
}