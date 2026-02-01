#include <iostream>
using namespace std;

int main() {
    int L, M, N;
    while (cin >> L) {
        if (L == 0) break;
        int savings = 0;
        int months = 0;
        bool reached = false;
        for (int i = 0; i < 12; ++i) {
            cin >> M >> N;
            savings += M - N;
            ++months;
            if (savings >= L) {
                reached = true;
                break;
            }
        }
        if (reached) {
            cout << months << endl;
        } else {
            cout << "NA" << endl;
        }
    }
    return 0;
}