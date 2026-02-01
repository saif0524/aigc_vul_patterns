#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int min_distance = 1000000;
    for (int i = 0; i < N; i++) {
        int distance = 0;
        for (int j = 0; j < N; j++) {
            distance += abs(a[j] - a[i]);
        }
        min_distance = min(min_distance, distance);
    }

    cout << min_distance << endl;

    return 0;
}