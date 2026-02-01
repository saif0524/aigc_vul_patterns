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

    set<int> all_elements;
    for (int x : a) {
        all_elements.insert(x);
    }
    for (int x : b) {
        all_elements.insert(x);
    }
    for (int x : c) {
        all_elements.insert(x);
    }

    int min_sum = -1;
    for (int u = 0; u <= n; ++u) {
        for (int v = 0; v <= n; ++v) {
            for (int w = 0; w <= n; ++w) {
                set<int> covered_elements;
                for (int i = 0; i < u; ++i) {
                    covered_elements.insert(a[i]);
                }
                for (int i = 0; i < v; ++i) {
                    covered_elements.insert(b[i]);
                }
                for (int i = 0; i < w; ++i) {
                    covered_elements.insert(c[i]);
                }

                bool all_covered = true;
                for (int x : all_elements) {
                    if (covered_elements.find(x) == covered_elements.end()) {
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