#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string grid[n];
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    int first = 0, second = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                if ((i + j) % 2 == 0) first++;
                else second++;
            }
        }
    }
    if (first <= second) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}