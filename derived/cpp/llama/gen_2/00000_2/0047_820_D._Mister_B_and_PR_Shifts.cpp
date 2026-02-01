#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    int min_deviation = INT_MAX;
    int min_id = 0;

    for (int id = 0; id < n; id++) {
        vector<int> q(n);
        for (int i = 0; i < n; i++) {
            q[i] = p[(i + id) % n];
        }

        int deviation = 0;
        for (int i = 0; i < n; i++) {
            deviation += abs(q[i] - i);
        }

        if (deviation < min_deviation) {
            min_deviation = deviation;
            min_id = id;
        }
    }

    cout << min_deviation << " " << min_id << endl;

    return 0;
}