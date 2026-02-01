#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        long long N, W;
        cin >> N >> W;
        if (N == 0 && W == 0) break;
        long long total_lessons = 0;
        set<int> days_available;
        for (int i = 0; i < N; ++i) {
            long long ti, ci;
            cin >> ti >> ci;
            total_lessons += ti;
            days_available.clear();
            for (int j = 0; j < ci; ++j) {
                string day;
                cin >> day;
                if (day == "Sunday") days_available.insert(0);
                else if (day == "Monday") days_available.insert(1);
                else if (day == "Tuesday") days_available.insert(2);
                else if (day == "Wednesday") days_available.insert(3);
                else if (day == "Thursday") days_available.insert(4);
                else if (day == "Friday") days_available.insert(5);
                else if (day == "Saturday") days_available.insert(6);
            }
        }
        if (total_lessons <= days_available.size() * W) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}