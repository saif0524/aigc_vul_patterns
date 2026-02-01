#include <bits/stdc++.h>

using namespace std;

int main() {
    int q, x;
    cin >> q >> x;

    set<int> s;
    vector<int> a;

    for (int i = 0; i < q; i++) {
        int y;
        cin >> y;
        a.push_back(y);
        s.insert(y);

        int mex = 0;
        while (s.count(mex)) {
            mex++;
        }

        int maxMex = mex;

        set<int> tmp = s;
        for (int j = 0; j < a.size(); j++) {
            int ny = a[j] % x;
            if (tmp.count(ny)) {
                tmp.erase(ny);
            } else {
                tmp.insert(ny);
            }
        }

        int nmex = 0;
        while (tmp.count(nmex % x)) {
            nmex++;
        }

        maxMex = max(maxMex, nmex);

        cout << maxMex << endl;
    }

    return 0;
}