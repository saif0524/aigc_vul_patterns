#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 105;

vector<int> permutation;
int depths[MAX_N];

void findDepth(int start, int end, int currentDepth) {
    if (start > end) {
        return;
    }

    int maxIndex = start;
    for (int i = start; i <= end; i++) {
        if (permutation[i] > permutation[maxIndex]) {
            maxIndex = i;
        }
    }

    depths[permutation[maxIndex]] = currentDepth;

    findDepth(start, maxIndex - 1, currentDepth + 1);
    findDepth(maxIndex + 1, end, currentDepth + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        permutation.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> permutation[i];
        }

        findDepth(0, n - 1, 0);

        for (int i = 1; i <= n; i++) {
            cout << depths[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}