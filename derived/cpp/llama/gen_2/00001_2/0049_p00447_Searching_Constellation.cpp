#include <iostream>
#include <map>

using namespace std;

int main() {
    int m;
    while (cin >> m && m > 0) {
        map<pair<int, int>, int> st;
        int conx[m], cony[m];
        for (int i = 0; i < m; i++) {
            cin >> conx[i] >> cony[i];
        }
        int n;
        cin >> n;
        int pix[n], piy[n];
        for (int i = 0; i < n; i++) {
            cin >> pix[i] >> piy[i];
            st[{pix[i], piy[i]}] = i;
        }
        bool found = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bool flag = true;
                int dx = pix[j] - conx[i];
                int dy = piy[j] - cony[i];
                for (int k = 0; k < m; k++) {
                    if (st.find({conx[k] + dx, cony[k] + dy}) == st.end()) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    cout << dx << " " << dy << endl;
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
    }
    return 0;
}