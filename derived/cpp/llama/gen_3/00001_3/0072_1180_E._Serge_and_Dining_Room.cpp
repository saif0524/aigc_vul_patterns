#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int type, index, value;
        cin >> type >> index >> value;

        if (type == 1) {
            a[index - 1] = value;
        } else {
            b[index - 1] = value;
        }

        vector<int> tempA = a;
        vector<int> tempB = b;

        sort(tempA.rbegin(), tempA.rend());
        sort(tempB.rbegin(), tempB.rend());

        int j = 0;
        for (int k = 0; k < m; k++) {
            while (j < n && tempA[j] > tempB[k]) {
                j++;
            }
            if (j < n) {
                tempA[j] = -1;
                j++;
            }
        }

        int result = -1;
        for (int k = 0; k < n; k++) {
            if (tempA[k]!= -1) {
                result = tempA[k];
                break;
            }
        }

        cout << result << endl;
    }

    return 0;
}