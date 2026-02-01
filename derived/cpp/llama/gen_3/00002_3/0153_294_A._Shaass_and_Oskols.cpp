#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> wires(n);
    for (int i = 0; i < n; i++) {
        cin >> wires[i];
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; // adjust for 0-based index

        int birdsBefore = y - 1;
        int birdsAfter = wires[x] - y;

        if (x > 0) {
            wires[x - 1] += birdsBefore;
        }

        if (x < n - 1) {
            wires[x + 1] += birdsAfter;
        }

        wires[x] = 0;
    }

    for (int i = 0; i < n; i++) {
        cout << wires[i] << endl;
    }

    return 0;
}