#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    vector<string> results(T);
    for (int i = 0; i < T; i++) {
        long long A, B, C, D;
        cin >> A >> B >> C >> D;
        if (B > D) {
            results[i] = "No";
        } else {
            long long stock = A;
            bool canBuyIndefinitely = true;
            for (int day = 0; day < 100; day++) { // Simulate for a sufficient number of days
                if (stock < B) {
                    canBuyIndefinitely = false;
                    break;
                }
                stock -= B;
                if (stock <= C) {
                    stock += D;
                }
            }
            results[i] = canBuyIndefinitely ? "Yes" : "No";
        }
    }
    for (const string& result : results) {
        cout << result << "\n";
    }
    return 0;
}