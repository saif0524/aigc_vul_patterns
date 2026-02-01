#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, A, B, C;
    cin >> N >> A >> B >> C;
    vector<int> D(N);
    for (int i = 0; i < N; ++i) {
        cin >> D[i];
    }
    
    int max_cal_per_dollar = 0;
    for (int mask = 0; mask < (1 << N); ++mask) {
        int total_cal = C;
        int total_cost = A;
        for (int j = 0; j < N; ++j) {
            if (mask & (1 << j)) {
                total_cal += D[j];
                total_cost += B;
            }
        }
        max_cal_per_dollar = max(max_cal_per_dollar, total_cal / total_cost);
    }
    
    cout << max_cal_per_dollar << endl;
    
    return 0;
}