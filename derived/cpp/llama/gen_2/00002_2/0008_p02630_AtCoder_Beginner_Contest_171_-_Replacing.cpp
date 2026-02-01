#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int q;
    cin >> q;

    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].first >> queries[i].second;
    }

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
    }

    for (int i = 0; i < q; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (A[j] == queries[i].first) {
                count++;
            }
        }

        sum = sum - (long long)count * queries[i].first + (long long)count * queries[i].second;

        for (int j = 0; j < n; j++) {
            if (A[j] == queries[i].first) {
                A[j] = queries[i].second;
            }
        }

        cout << sum << endl;
    }

    return 0;
}