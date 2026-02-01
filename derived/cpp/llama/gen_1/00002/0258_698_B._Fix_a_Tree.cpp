#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    int cnt = 0;
    int root = -1;

    for (int i = 0; i < n; ++i) {
        if (p[i] == i + 1) {
            root = i + 1;
        }
    }

    if (root == -1) {
        for (int i = 0; i < n; ++i) {
            if (p[i] < i + 1) {
                ++cnt;
                p[i] = i + 1;
                root = i + 1;
                break;
            }
        }
        if (root == -1) {
            for (int i = n - 1; i >= 0; --i) {
                if (p[i] > i + 1) {
                    ++cnt;
                    p[i] = i + 1;
                    root = i + 1;
                    break;
                }
            }
        }
    }

    bool has_root = false;
    for (int i = 0; i < n; ++i) {
        if (p[i] == root) {
            has_root = true;
            break;
        }
    }

    if (!has_root) {
        p[0] = root;
        ++cnt;
    }

    cout << cnt << endl;
    for (int i = 0; i < n; ++i) {
        cout << p[i] << " ";
    }
    cout << endl;

    return 0;
}