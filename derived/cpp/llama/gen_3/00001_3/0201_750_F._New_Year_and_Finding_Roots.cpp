#include <iostream>
#include <vector>

using namespace std;

void query(int vertex, int h) {
    cout << "? " << vertex << endl;
    fflush(stdout);
    int k;
    cin >> k;
    if (k == 0) {
        exit(0);
    }
    vector<int> neighbors(k);
    for (int i = 0; i < k; i++) {
        cin >> neighbors[i];
    }
    if (k == 1) {
        cout << "! " << vertex << endl;
        fflush(stdout);
    } else {
        for (int neighbor : neighbors) {
            if (neighbor == 1 || neighbor == (1 << (h + 1)) - 1) {
                query(neighbor, h);
                return;
            }
        }
        for (int neighbor : neighbors) {
            if (neighbor != vertex) {
                query(neighbor, h);
                return;
            }
        }
    }
}

void solve() {
    int h;
    cin >> h;
    if (h == 0) {
        exit(0);
    }
    query(1, h);
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}