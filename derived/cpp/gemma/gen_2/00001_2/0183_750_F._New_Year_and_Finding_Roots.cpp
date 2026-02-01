#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int h;
        cin >> h;

        if (h == 0) {
            return 0;
        }

        if (h == 2) {
            cout << "? 1" << endl;
            fflush(stdout);
            int k;
            cin >> k;
            if (k == 0) {
                return 0;
            }
            vector<int> neighbors(k);
            for (int i = 0; i < k; ++i) {
                cin >> neighbors[i];
            }
            cout << "! 1" << endl;
            fflush(stdout);
            continue;
        }

        if (h == 3) {
            cout << "? 1" << endl;
            fflush(stdout);
            int k1;
            cin >> k1;
            if (k1 == 0) {
                return 0;
            }
            vector<int> neighbors1(k1);
            for (int i = 0; i < k1; ++i) {
                cin >> neighbors1[i];
            }

            cout << "? 5" << endl;
            fflush(stdout);
            int k2;
            cin >> k2;
            if (k2 == 0) {
                return 0;
            }
            vector<int> neighbors2(k2);
            for (int i = 0; i < k2; ++i) {
                cin >> neighbors2[i];
            }

            cout << "? 6" << endl;
            fflush(stdout);
            int k3;
            cin >> k3;
            if (k3 == 0) {
                return 0;
            }
            vector<int> neighbors3(k3);
            for (int i = 0; i < k3; ++i) {
                cin >> neighbors3[i];
            }

            cout << "! 5" << endl;
            fflush(stdout);
            continue;
        }

        if (h == 4) {
            cout << "? 6" << endl;
            fflush(stdout);
            int k1;
            cin >> k1;
            if (k1 == 0) {
                return 0;
            }
            
            cout << "! 1" << endl;
            fflush(stdout);
            continue;
        }
        
        
        cout << "? 1" << endl;
        fflush(stdout);
        int k1;
        cin >> k1;
        if (k1 == 0) {
            return 0;
        }
        vector<int> neighbors1(k1);
        for (int i = 0; i < k1; ++i) {
            cin >> neighbors1[i];
        }
        
        
        cout << "? 2" << endl;
        fflush(stdout);
        int k2;
        cin >> k2;
        if (k2 == 0) {
            return 0;
        }
        vector<int> neighbors2(k2);
        for (int i = 0; i < k2; ++i) {
            cin >> neighbors2[i];
        }
        
        cout << "? 3" << endl;
        fflush(stdout);
        int k3;
        cin >> k3;
        if (k3 == 0) {
            return 0;
        }
        vector<int> neighbors3(k3);
        for (int i = 0; i < k3; ++i) {
            cin >> neighbors3[i];
        }
        
        cout << "! 1" << endl;
        fflush(stdout);
    }

    return 0;
}