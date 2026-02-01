#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    set<int> combined;
    for (int x : a) {
        combined.insert(x);
    }
    for (int x : b) {
        combined.insert(x);
    }
    for (int x : c) {
        combined.insert(x);
    }

    int min_sum = -1;
    for (int u = 0; u <= n; ++u) {
        for (int v = 0; v <= n; ++v) {
            for (int w = 0; w <= n; ++w) {
                set<int> covered;
                for (int i = 0; i < u; ++i) {
                    covered.insert(a[i]);
                }
                for (int i = 0; i < v; ++i) {
                    covered.insert(b[i]);
                }
                for (int i = 0; i < w; ++i) {
                    covered.insert(c[i]);
                }

                bool all_covered = true;
                for (int x : combined) {
                    if (covered.find(x) == covered.end()) {
                        all_covered = false;
                        break;
                    }
                }

                if (all_covered) {
                    int current_sum = u + v + w;
                    if (min_sum == -1 || current_sum < min_sum) {
                        min_sum = current_sum;
                    }
                }
            }
        }
    }

    cout << min_sum << endl;

    return 0;
}