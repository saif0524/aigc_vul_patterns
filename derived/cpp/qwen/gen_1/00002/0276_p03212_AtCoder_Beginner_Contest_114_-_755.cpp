#include <bits/stdc++.h>
using namespace std;

bool isShichiGoSan(int n) {
    bool has3 = false, has5 = false, has7 = false;
    while (n > 0) {
        int d = n % 10;
        if (d == 3) has3 = true;
        else if (d == 5) has5 = true;
        else if (d == 7) has7 = true;
        else return false;
        n /= 10;
    }
    return has3 && has5 && has7;
}

int countShichiGoSan(int N) {
    int count = 0;
    for (int i = 1; i <= N; ++i) {
        if (isShichiGoSan(i)) {
            ++count;
        }
    }
    return count;
}

int main() {
    int N;
    cin >> N;
    cout << countShichiGoSan(N) << endl;
    return 0;
}