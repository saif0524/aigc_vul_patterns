#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long A, B, C, D;
        cin >> A >> B >> C >> D;

        if (A < B) {
            cout << "No" << endl;
            continue;
        }

        if (A >= B) {
            long long minA = A;
            bool yes = true;

            while (true) {
                if (minA < B) {
                    cout << "No" << endl;
                    break;
                }

                if (minA - B <= C) {
                    minA = minA - B + D;
                    if (minA < minA - B + D) {
                        cout << "Yes" << endl;
                        break;
                    }
                    if (minA < B) {
                        cout << "No" << endl;
                        break;
                    }
                } else {
                    minA = minA - B;
                    if (minA < B) {
                        cout << "No" << endl;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}