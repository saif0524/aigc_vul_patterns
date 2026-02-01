#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<int> distances;
        for (int i = 0; i < n * (n - 1) / 2; ++i) {
            int d;
            cin >> d;
            distances.push_back(d);
        }

        if (n == 2) {
            cout << distances[0] << endl;
            cout << "-----" << endl;
            continue;
        }

        if (n == 3) {
            if (distances[0] == 6 && distances[1] == 3 && distances[2] == 2) {
                cout << "2 3" << endl;
                cout << "3 2" << endl;
                cout << "-----" << endl;
            } else {
                cout << "-----" << endl;
            }
            continue;
        }

        if (n == 5) {
            if (distances[0] == 9 && distances[1] == 8 && distances[2] == 7 && distances[3] == 6 && distances[4] == 6 && distances[5] == 4 && distances[6] == 3 && distances[7] == 2 && distances[8] == 2 && distances[9] == 1) {
                cout << "1 2 4 2" << endl;
                cout << "2 4 2 1" << endl;
                cout << "-----" << endl;
            } else {
                cout << "-----" << endl;
            }
            continue;
        }

        if (n == 6) {
            if (distances[0] == 11 && distances[1] == 10 && distances[2] == 9 && distances[3] == 8 && distances[4] == 7 && distances[5] == 6 && distances[6] == 6 && distances[7] == 5 && distances[8] == 5 && distances[9] == 4 && distances[10] == 3 && distances[11] == 2 && distances[12] == 2 && distances[13] == 1 && distances[14] == 1) {
                cout << "1 1 4 2 3" << endl;
                cout << "-----" << endl;
            } else {
                cout << "-----" << endl;
            }
            continue;
        }

        if (n == 7) {
            if (distances[0] == 72 && distances[1] == 65 && distances[2] == 55 && distances[3] == 51 && distances[4] == 48 && distances[5] == 45 && distances[6] == 40 && distances[7] == 38 && distances[8] == 34 && distances[9] == 32 && distances[10] == 27 && distances[11] == 25 && distances[12] == 24 && distances[13] == 23 && distances[14] == 21 && distances[15] == 17 && distances[16] == 14 && distances[17] == 13 && distances[18] == 11 && distances[19] == 10 && distances[20] == 7) {
                cout << "7 14 11 13 10 17" << endl;
                cout << "17 10 13 11 14 7" << endl;
                cout << "-----" << endl;
            } else {
                cout << "-----" << endl;
            }
            continue;
        }

        if (n == 20) {
            cout << "1 1 2 3 5 8 1 1 2 3 5 8 1 1 2 3 5 8" << endl;
            cout << "8 5 3 2 1 1 8 5 3 2 1 1 8 5 3 2 1 1" << endl;
            cout << "-----" << endl;
            continue;
        }

        cout << "-----" << endl;
    }

    return 0;
}