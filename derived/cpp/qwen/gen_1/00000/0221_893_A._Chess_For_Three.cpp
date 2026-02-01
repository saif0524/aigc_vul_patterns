#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> log(n);
    for (int &x : log) cin >> x;
    
    int spectator = 3;
    for (int winner : log) {
        if (winner == spectator) {
            cout << "NO";
            return 0;
        }
        spectator = 6 - winner - spectator;
    }
    cout << "YES";
}