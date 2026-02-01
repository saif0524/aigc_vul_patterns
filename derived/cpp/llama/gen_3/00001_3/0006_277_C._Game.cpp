#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

struct Cut {
    int x1, y1, x2, y2;
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<Cut> cuts(k);
    for (int i = 0; i < k; i++) {
        cin >> cuts[i].x1 >> cuts[i].y1 >> cuts[i].x2 >> cuts[i].y2;
    }

    set<int> xCuts, yCuts;
    for (int i = 0; i < k; i++) {
        if (cuts[i].x1 == cuts[i].x2) {
            xCuts.insert(cuts[i].x1);
        } else {
            yCuts.insert(cuts[i].y1);
        }
    }

    int xCount = n - 1 - (int)xCuts.size();
    int yCount = m - 1 - (int)yCuts.size();

    if ((xCount + yCount) % 2 == 0) {
        cout << "SECOND" << endl;
    } else {
        cout << "FIRST" << endl;

        if (xCount % 2 == 1) {
            int x = 0;
            for (int i : xCuts) {
                if (i > x) {
                    break;
                }
                x = i + 1;
            }
            cout << x << " 0 " << x << " " << m << endl;
        } else {
            int y = 0;
            for (int i : yCuts) {
                if (i > y) {
                    break;
                }
                y = i + 1;
            }
            cout << "0 " << y << " " << n << " " << y << endl;
        }
    }

    return 0;
}