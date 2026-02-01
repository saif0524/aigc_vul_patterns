#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countShichiGoSan(int N) {
    int count = 0;
    for (int i = 1; i <= N; i++) {
        string str = to_string(i);
        bool has7 = false, has5 = false, has3 = false;
        bool hasOtherDigit = false;
        for (char c : str) {
            if (c == '7') has7 = true;
            else if (c == '5') has5 = true;
            else if (c == '3') has3 = true;
            else if (c != '0') hasOtherDigit = true;
        }
        if (has7 && has5 && has3 && !hasOtherDigit) {
            count++;
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