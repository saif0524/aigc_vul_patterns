#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N, E, T;
    cin >> N >> E >> T;

    vector<int> x(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }

    long long ans = 0;
    long long pos = 0;

    for (int i = 0; i < N; i++) {
        long long dist = x[i] - pos;
        ans += dist;
        pos = x[i];
        ans += T;
        pos += T;
        if (pos > x[i]) {
            pos = x[i];
        }
    }

    long long dist = E - pos;
    ans += dist;

    cout << ans << endl;

    return 0;
}