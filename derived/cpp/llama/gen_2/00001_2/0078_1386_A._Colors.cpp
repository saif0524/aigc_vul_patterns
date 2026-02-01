#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        long long N;
        cin >> N;

        long long left = 1, right = N;
        long long prev = -1;

        while(left <= right) {
            long long mid = (left + right) / 2;
            cout << "? " << mid << endl;
            long long ans;
            cin >> ans;
            if(ans == 1 && prev != -1) {
                right = mid - 1;
            } else if (ans == 1 && prev == -1) {
                prev = mid;
                continue;
            } else if (ans == 0) {
                left = mid + 1;
            }
            prev = mid;
        }

        long long C = left;
        if(C > prev) {
            cout << "? " << C << endl;
            cin >> C;
            cout << "= " << C << endl;
        } else {
            cout << "? " << prev << endl;
            cin >> C;
            cout << "= " << C << endl;
        }
    }

    return 0;
}