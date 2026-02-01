#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> cupboards(n);
    for (int i = 0; i < n; ++i) {
        cin >> cupboards[i].first >> cupboards[i].second;
    }

    int min_ops = n + 1;

    // Case 1: All left doors open, all right doors open
    int ops1 = 0;
    for (int i = 0; i < n; ++i) {
        if (cupboards[i].first != 1) ops1++;
        if (cupboards[i].second != 1) ops1++;
    }
    min_ops = min(min_ops, ops1);

    // Case 2: All left doors open, all right doors closed
    int ops2 = 0;
    for (int i = 0; i < n; ++i) {
        if (cupboards[i].first != 1) ops2++;
        if (cupboards[i].second != 0) ops2++;
    }
    min_ops = min(min_ops, ops2);

    // Case 3: All left doors closed, all right doors open
    int ops3 = 0;
    for (int i = 0; i < n; ++i) {
        if (cupboards[i].first != 0) ops3++;
        if (cupboards[i].second != 1) ops3++;
    }
    min_ops = min(min_ops, ops3);

    // Case 4: All left doors closed, all right doors closed
    int ops4 = 0;
    for (int i = 0; i < n; ++i) {
        if (cupboards[i].first != 0) ops4++;
        if (cupboards[i].second != 0) ops4++;
    }
    min_ops = min(min_ops, ops4);

    cout << min_ops << endl;

    return 0;
}