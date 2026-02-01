#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    bool first = false;
    bool second = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                if ((i + j) % 2 == 0) {
                    first = true;
                } else {
                    second = true;
                }
            }
        }
    }

    if (first && second) {
        cout << "Both" << endl;
    } else if (first) {
        cout << "First" << endl;
    } else if (second) {
        cout << "Second" << endl;
    }

    return 0;
}