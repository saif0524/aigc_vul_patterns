#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, l, x, y;
    cin >> n >> l >> x >> y;
    vector<int> a(n);
    for (int &ai : a) cin >> ai;

    set<int> distances;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            distances.insert(a[j] - a[i]);
        }
    }

    vector<int> result;
    if (distances.find(x) == distances.end()) {
        result.push_back(x);
    }
    if (distances.find(y) == distances.end()) {
        result.push_back(y);
    }

    cout << result.size() << endl;
    for (int p : result) {
        cout << p << " ";
    }
    cout << endl;

    return 0;
}