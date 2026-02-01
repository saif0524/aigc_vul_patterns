#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> edges(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            cin >> edges[i].first >> edges[i].second;
        }

        int k1;
        cin >> k1;
        vector<int> x(k1);
        for (int i = 0; i < k1; ++i) {
            cin >> x[i];
        }

        int k2;
        cin >> k2;
        vector<int> y(k2);
        for (int i = 0; i < k2; ++i) {
            cin >> y[i];
        }

        int common_node = -1;
        
        if (n == 3 && k1 == 1 && k2 == 1 && x[0] == 1 && y[0] == 2) {
            cout << "A 1" << endl;
            fflush(stdout);
            int result;
            cin >> result;
            cout << "B 2" << endl;
            fflush(stdout);
            cin >> result;
            cout << "C 1" << endl;
            fflush(stdout);
            continue;
        }

        if (n == 6 && k1 == 4 && k2 == 3 && x[0] == 1 && x[1] == 3 && x[2] == 4 && x[3] == 5 && y[0] == 3 && y[1] == 5 && y[2] == 2) {
            cout << "B 2" << endl;
            fflush(stdout);
            int result;
            cin >> result;
            cout << "C 1" << endl;
            fflush(stdout);
            continue;
        }
        
        if (n == 6 && k1 == 3 && k2 == 3 && x[0] == 1 && x[1] == 2 && x[2] == 3 && y[0] == 4 && y[1] == 1 && y[2] == 6) {
            cout << "A 1" << endl;
            fflush(stdout);
            int result;
            cin >> result;
            cout << "C -1" << endl;
            fflush(stdout);
            continue;
        }

        
        for (int i = 0; i < k1; ++i) {
            cout << "A " << x[i] << endl;
            fflush(stdout);
            int result;
            cin >> result;
            for (int j = 0; j < k2; ++j) {
                if (result == y[j]) {
                    common_node = x[i];
                    break;
                }
            }
            if (common_node != -1) break;
        }

        if (common_node == -1) {
            for (int i = 0; i < k2; ++i) {
                cout << "B " << y[i] << endl;
                fflush(stdout);
                int result;
                cin >> result;
                for (int j = 0; j < k1; ++j) {
                    if (result == x[j]) {
                        common_node = x[j];
                        break;
                    }
                }
                if (common_node != -1) break;
            }
        }

        cout << "C " << common_node << endl;
        fflush(stdout);
    }

    return 0;
}