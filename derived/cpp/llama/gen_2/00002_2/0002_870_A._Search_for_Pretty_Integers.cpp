#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    set<int> s1(a.begin(), a.end());
    set<int> s2(b.begin(), b.end());

    set<int> intersection;
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),
                     inserter(intersection, intersection.begin()));

    if (!intersection.empty()) {
        cout << *intersection.begin() << endl;
        return 0;
    }

    int minA = *min_element(a.begin(), a.end());
    int minB = *min_element(b.begin(), b.end());

    if (minA < minB) {
        cout << minA << minB << endl;
    } else {
        cout << minB << minA << endl;
    }

    return 0;
}