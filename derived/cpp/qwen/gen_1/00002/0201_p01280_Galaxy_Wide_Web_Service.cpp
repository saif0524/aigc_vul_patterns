#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    while (cin >> N && N != 0) {
        int max_access = 0;
        for (int i = 0; i < N; ++i) {
            int d, t;
            cin >> d >> t;
            vector<int> q(d);
            for (int j = 0; j < d; ++j) {
                cin >> q[j];
                max_access = max(max_access, q[j]);
            }
        }
        cout << max_access << endl;
    }
    return 0;
}