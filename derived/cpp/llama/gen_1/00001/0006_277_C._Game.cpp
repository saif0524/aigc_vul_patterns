#include <iostream>
#include <vector>
#include <algorithm>

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

    vector<int> x_coords;
    x_coords.push_back(0);
    x_coords.push_back(n);

    vector<int> y_coords;
    y_coords.push_back(0);
    y_coords.push_back(m);

    for (int i = 0; i < k; i++) {
        if (cuts[i].x1 == cuts[i].x2) {
            x_coords.push_back(cuts[i].x1);
        }
        if (cuts[i].y1 == cuts[i].y2) {
            y_coords.push_back(cuts[i].y1);
        }
    }

    sort(x_coords.begin(), x_coords.end());
    sort(y_coords.begin(), y_coords.end());

    int x_xor = 0;
    int y_xor = 0;

    for (int i = 0; i < x_coords.size() - 1; i++) {
        x_xor ^= (x_coords[i + 1] - x_coords[i]) - 1;
    }

    for (int i = 0; i < y_coords.size() - 1; i++) {
        y_xor ^= (y_coords[i + 1] - y_coords[i]) - 1;
    }

    if ((x_xor == 0) && (y_xor == 0)) {
        cout << "SECOND" << endl;
    } else {
        cout << "FIRST" << endl;

        int x_winner, y_winner;
        if (x_xor != 0) {
            x_winner = 1;
        } else {
            x_winner = 0;
        }

        if (y_xor != 0) {
            y_winner = 1;
        } else {
            y_winner = 0;
        }

        if (x_winner == 1) {
            int gap = -1;
            for (int i = 0; i < x_coords.size() - 1; i++) {
                if ((x_coords[i + 1] - x_coords[i]) > 1) {
                    gap = i;
                    break;
                }
            }

            int start = x_coords[gap] + 1;
            int end = x_coords[gap + 1];

            cout << start << " " << 0 << " " << start << " " << m << endl;
        } else {
            int gap = -1;
            for (int i = 0; i < y_coords.size() - 1; i++) {
                if ((y_coords[i + 1] - y_coords[i]) > 1) {
                    gap = i;
                    break;
                }
            }

            int start = y_coords[gap] + 1;
            int end = y_coords[gap + 1];

            cout << 0 << " " << start << " " << n << " " << start << endl;
        }
    }

    return 0;
}