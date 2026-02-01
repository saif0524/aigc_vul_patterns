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
    int diff_index1 = -1;
    int diff_index2 = -1;
    int diff1 = 0;
    int diff2 = 0;

    for (int i = 0; i < n; ++i) {
        if (volumes[i] != expected_volume) {
            diff_count++;
            if (diff_count == 1) {
                diff_index1 = i;
                diff1 = volumes[i] - expected_volume;
            } else if (diff_count == 2) {
                diff_index2 = i;
                diff2 = volumes[i] - expected_volume;
            } else {
                cout << "Unrecoverable configuration." << endl;
                return 0;
            }
        }
    }

    if (diff_count == 0) {
        cout << "Exemplary pages." << endl;
    } else if (diff_count == 2) {
        if (diff1 == -diff2) {
            cout << abs(diff1) << " ml. from cup #" << (diff_index1 + 1) << " to cup #" << (diff_index2 + 1) << "." << endl;
        } else {
            cout << "Unrecoverable configuration." << endl;
        }
    } else {
        cout << "Unrecoverable configuration." << endl;
    }

    return 0;
}