#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        vector<int> age_count(7, 0);
        for (int i = 0; i < n; ++i) {
            int age;
            cin >> age;
            if (age < 10) age_count[0]++;
            else if (age < 20) age_count[1]++;
            else if (age < 30) age_count[2]++;
            else if (age < 40) age_count[3]++;
            else if (age < 50) age_count[4]++;
            else if (age < 60) age_count[5]++;
            else age_count[6]++;
        }
        for (int count : age_count) {
            cout << count << "\n";
        }
    }
    return 0;
}