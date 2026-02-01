#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> volumes(n);
    for (int i = 0; i < n; ++i) {
        cin >> volumes[i];
    }

    int sum = accumulate(volumes.begin(), volumes.end(), 0);
    int expected_volume = sum / n;

    if (sum % n != 0) {
        cout << "Unrecoverable configuration." << endl;
        return 0;
    }

    int diff_count = 0;
    int diff_index_from = -1;
    int diff_index_to = -1;
    int diff_value = 0;

    for (int i = 0; i < n; ++i) {
        if (volumes[i] != expected_volume) {
            diff_count++;
            if (diff_count == 1) {
                diff_index_from = i;
            } else if (diff_count == 2) {
                diff_index_to = i;
                diff_value = abs(volumes[diff_index_from] - expected_volume);
            } else {
                cout << "Unrecoverable configuration." << endl;
                return 0;
            }
        }
    }

    if (diff_count == 0) {
        cout << "Exemplary pages." << endl;
    } else if (diff_count == 2) {
        if (volumes[diff_index_from] > expected_volume && volumes[diff_index_to] < expected_volume &&
            volumes[diff_index_from] - expected_volume == expected_volume - volumes[diff_index_to]) {
            cout << diff_value << " ml. from cup #" << diff_index_from + 1 << " to cup #" << diff_index_to + 1 << "." << endl;
        } else {
            cout << "Unrecoverable configuration." << endl;
        }
    } else {
        cout << "Unrecoverable configuration." << endl;
    }

    return 0;
}