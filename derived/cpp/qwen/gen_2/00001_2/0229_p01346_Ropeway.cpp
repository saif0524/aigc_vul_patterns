#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int N, L, M, R;
    cin >> N >> L >> M >> R;
    vector<int> packages(N);
    for (int i = 0; i < N; ++i) {
        cin >> packages[i];
    }
    
    int left = -(L / 2) + R;
    int right = (L / 2) - R;
    int current_weight = 0;
    int current_left = left;
    int current_right = right;
    bool can_load = true;
    for (int i = 0; i < N; ++i) {
        if (current_left > current_right) {
            can_load = false;
            break;
        }
        if (current_weight + packages[i] <= M) {
            current_weight += packages[i];
            current_left++;
            current_right--;
        } else {
            current_weight = packages[i];
            current_left = left;
            current_right = right - 1;
        }
    }
    
    cout << (can_load ? "Yes" : "No") << endl;
    return 0;
}