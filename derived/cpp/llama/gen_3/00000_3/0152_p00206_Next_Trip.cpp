#include <iostream>
using namespace std;

int main() {
    int dataset, L, M, N, savings, months, i;
    dataset = 1;

    while (true) {
        cin >> L;
        if (L == 0)
            break;

        savings = 0;
        months = 0;
        for (i = 0; i < 12; i++) {
            cin >> M >> N;
            savings += M - N;
            months++;
            if (savings >= L)
                break;
        }

        if (savings >= L)
            cout << months << endl;
        else
            cout << "NA" << endl;
    }

    return 0;
}