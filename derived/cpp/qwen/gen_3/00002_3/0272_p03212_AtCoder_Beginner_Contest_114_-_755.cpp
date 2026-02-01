#include <iostream>
using namespace std;

bool isShichiGoSan(int num) {
    bool has3 = false, has5 = false, has7 = false;
    while (num > 0) {
        int digit = num % 10;
        if (digit == 3) has3 = true;
        else if (digit == 5) has5 = true;
        else if (digit == 7) has7 = true;
        else return false;
        num /= 10;
    }
    return has3 && has5 && has7;
}

int main() {
    int N;
    cin >> N;
    int count = 0;
    for (int i = 1; i <= N; ++i) {
        if (isShichiGoSan(i)) {
            ++count;
        }
    }
    cout << count << endl;
    return 0;
}