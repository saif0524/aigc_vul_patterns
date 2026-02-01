#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    vector<string> results(T);
    for (int i = 0; i < T; ++i) {
        long long A, B, C, D;
        cin >> A >> B >> C >> D;
        if (B > D) {
            results[i] = "No";
        } else {
            long long initial = A - B;
            if (initial >= C) {
                results[i] = "Yes";
            } else {
                long long need_to_reach = C + B;
                if (D + initial >= need_to_reach) {
                    results[i] = "Yes";
                } else {
                    results[i] = "No";
                }
            }
        }
    }
    for (const string &result : results) {
        cout << result << "\n";
    }
    return 0;
}