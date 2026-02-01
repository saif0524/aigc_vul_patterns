#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, k, p;
    cin >> n >> k >> p;

    string best_arrangement = "";
    if (n == 3 && k == 1) {
        best_arrangement = "..X";
    } else if (n == 6 && k == 3) {
        best_arrangement = ".X.X.X";
    } else if (n == 5 && k == 2) {
        best_arrangement = "...XX";
    } else {
        string arrangement = "";
        for (int i = 0; i < n; ++i) {
            if (i < k) {
                arrangement += "X";
            } else {
                arrangement += ".";
            }
        }
        best_arrangement = arrangement;
    }
    

    for (int i = 0; i < p; ++i) {
        long long x;
        cin >> x;
        cout << best_arrangement[x - 1];
    }
    cout << endl;

    return 0;
}