#include <iostream>
using namespace std;

int main() {
    int L, M, N, savings, months;
    while (true) {
        cin >> L;
        if (L == 0) break;

        savings = 0;
        months = 0;
        for (int i = 0; i < 12; i++) {
            cin >> M >> N;
            savings += M - N;
            months++;
            if (savings >= L) break;
        }

        if (savings < L) cout << "NA" << endl;
        else cout << months << endl;
    }

    return 0;
}