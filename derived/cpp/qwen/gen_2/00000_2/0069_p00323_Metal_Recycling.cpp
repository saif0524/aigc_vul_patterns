#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int N;
    cin >> N;
    vector<pii> vehicles(N);
    for (int i = 0; i < N; ++i) {
        cin >> vehicles[i].first >> vehicles[i].second;
        vehicles[i].first = 2 * vehicles[i].first + 2 * vehicles[i].second;
    }
    sort(vehicles.begin(), vehicles.end());
    int total_weight = 0;
    for (int i = 0; i < N; ++i) {
        total_weight += vehicles[i].first;
        int bocco = total_weight / 2;
        int marugu = (total_weight % 2) / 2;
        cout << bocco << " " << marugu << "\n";
    }
    return 0;
}