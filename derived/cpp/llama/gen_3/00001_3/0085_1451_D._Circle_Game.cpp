#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int d, k;
        cin >> d >> k;
        int maxMoves = floor(d / k);
        if (maxMoves % 2 == 0) {
            cout << "Utkarsh" << endl;
        } else {
            cout << "Ashish" << endl;
        }
    }
    return 0;
}