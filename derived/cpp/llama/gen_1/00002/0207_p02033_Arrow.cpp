#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> blowers(M);
    for (auto& blower : blowers) {
        cin >> blower;
    }

    int Q;
    cin >> Q;

    vector<int> acceptable_losses(Q);
    for (auto& loss : acceptable_losses) {
        cin >> loss;
    }

    for (const auto& loss : acceptable_losses) {
        int left = 1;
        int right = N + 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            int total_loss = 0;
            for (int i = 1; i <= N; ++i) {
                bool has_blower = false;
                for (const auto& blower : blowers) {
                    if (i - mid < blower && blower <= i) {
                        has_blower = true;
                        break;
                    }
                }

                if (!has_blower) {
                    ++total_loss;
                }
            }

            if (total_loss <= loss) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        if (left == N + 1) {
            cout << -1 << '\n';
        } else {
            cout << left << '\n';
        }
    }

    return 0;
}