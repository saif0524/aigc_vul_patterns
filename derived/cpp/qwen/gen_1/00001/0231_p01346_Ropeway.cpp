#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, L, M, R;
    cin >> N >> L >> M >> R;
    vector<int> m(N);
    for (int i = 0; i < N; ++i) {
        cin >> m[i];
    }

    sort(m.begin(), m.end());
    int left = 0, right = N - 1;
    int left_pos = -L / 2 + R;
    int right_pos = L / 2 - R;
    int left_sum = 0, right_sum = 0;
    while (left <= right) {
        if (left_sum <= right_sum) {
            left_sum += m[left++];
            left_pos += 1;
        } else {
            right_sum += m[right--];
            right_pos -= 1;
        }
        if (left <= right && (left_pos >= right_pos || abs(left_pos) < R || abs(right_pos) < R)) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}